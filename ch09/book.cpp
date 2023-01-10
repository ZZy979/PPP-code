#include "book.h"

#include <regex>

// construct a Book, throws Invalid_ISBN if isbn is of wrong format
Book::Book(const std::string& isbn, const std::string& title, const std::string& author,
        const Chrono::Date& copyright_date, Genre genre, bool checked_out)
        :isbn_(isbn), title_(title), author_(author),
        copyright_date_(copyright_date), genre_(genre), checked_out_(checked_out) {
    if (!is_valid_isbn(isbn))
        throw Invalid_ISBN("Invalid ISBN: " + isbn);
}

// check out the book, throws Invalid_operation if already checked out
void Book::checkout() {
    if (checked_out_)
        throw Invalid_operation("Book already checked out");
    checked_out_ = true;
}

// check in the book, throws Invalid_operation if not checked out
void Book::checkin() {
    if (!checked_out_)
        throw Invalid_operation("Book not checked out");
    checked_out_ = false;
}

// return true if isbn is of valid format: n-n-n-x,
// where n is an integer and x is a digit or a letter
bool is_valid_isbn(const std::string& isbn) {
    static const std::regex isbn_pattern(R"(\d+-\d+-\d+-\w)");
    return std::regex_match(isbn, isbn_pattern);
}

// check whether the ISBN numbers are the same for two books
bool operator==(const Book& a, const Book& b) {
    return a.isbn() == b.isbn();
}

// check whether the ISBN numbers are not same for two books
bool operator!=(const Book& a, const Book& b) {
    return !(a == b);
}

std::ostream& operator<<(std::ostream& os, const Book& book) {
    return os << book.title() << std::endl
            << book.author() << std::endl
            << book.isbn() << std::endl;
}
