#include "library.h"

// construct Library from initial books, patrons and transactions
// for books with the same ISBN or patrons with the same card number, only the first is kept
Library::Library(const std::vector<Book>& books, const std::vector<Patron>& patrons,
        const std::vector<Transaction>& transactions)
        :transactions_(transactions) {
    for (const Book& b : books)
        books_.emplace(b.isbn(), b);
    for (const Patron& p : patrons)
        patrons_.emplace(p.card_number(), p);
}

/**
 * add a book to the library
 *
 * @returns false if a book with the same ISBN already exists
 */
bool Library::add_book(const Book& book) {
    return books_.emplace(book.isbn(), book).second;
}

/**
 * add a patron to the library
 *
 * @returns false if a patron with the same card number already exists
 */
bool Library::add_patron(const Patron& patron) {
    return patrons_.emplace(patron.card_number(), patron).second;
}

/**
 * check out a book for a patron
 *
 * @throws No_such_book if book with specified ISBN doesn't exist
 * @throws No_such_patron if patron with specified card number doesn't exist
 * @throws Patron_owes_fees if the patron owes fees
 * @throws Invalid_operation if the book is already checked out
 */
void Library::check_out_book(const std::string& book_isbn, int patron_card_number,
        const Chrono::Date& borrow_date) {
    auto book_it = books_.find(book_isbn);
    auto patron_it = patrons_.find(patron_card_number);
    if (book_it == books_.end())
        throw No_such_book();
    if (patron_it == patrons_.end())
        throw No_such_patron();
    if (patron_it->second.owes_fees())
        throw Patron_owes_fees();

    book_it->second.checkout();
    transactions_.push_back({book_it->second, patron_it->second, borrow_date});
}

/**
 * get book by ISBN
 *
 * @throws out_of_range if ISBN doesn't exist
 */
const Book& Library::get_book(const std::string& isbn) const {
    return books_.at(isbn);
}

/**
 * get patron by card number
 *
 * @throws out_of_range if card number doesn't exist
 */
const Patron& Library::get_patron(int card_number) const {
    return patrons_.at(card_number);
}

// return a vector that contains the names of all patrons who owe fees
std::vector<std::string> Library::patrons_owing_fees() const {
    std::vector<std::string> names;
    for (const auto& p : patrons_)
        if (p.second.owes_fees())
            names.push_back(p.second.name());
    return names;
}
