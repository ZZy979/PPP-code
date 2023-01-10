#pragma once

#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

#include "Chrono.h"
#include "book.h"
#include "patron.h"

struct Transaction {
    Book book;
    Patron patron;
    Chrono::Date borrow_date;
};

class Library {
public:
    Library() {}
    Library(const std::vector<Book>& books, const std::vector<Patron>& patrons,
            const std::vector<Transaction>& transactions);

    bool add_book(const Book& book);
    bool add_patron(const Patron& patron);
    void check_out_book(const std::string& book_isbn, int patron_card_number,
            const Chrono::Date& borrow_date);

    const Book& get_book(const std::string& isbn) const;
    const Patron& get_patron(int card_number) const;
    const std::vector<Transaction>& get_transactions() const { return transactions_; }
    std::vector<std::string> patrons_owing_fees() const;
private:
    std::unordered_map<std::string, Book> books_;   // key is ISBN
    std::unordered_map<int, Patron> patrons_;       // key is library card number
    std::vector<Transaction> transactions_;
};

class Check_out_error : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class No_such_book : public Check_out_error {
public:
    No_such_book() :Check_out_error("No such book") {}
};

class No_such_patron : public Check_out_error {
public:
    No_such_patron() :Check_out_error("No such patron") {}
};

class Patron_owes_fees : public Check_out_error {
public:
    Patron_owes_fees() :Check_out_error("Patron owes fees") {}
};
