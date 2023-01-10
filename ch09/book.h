#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

#include "Chrono.h"

enum class Genre {
    fiction, nonfiction, periodical, biography, children, computer
};

class Book {
public:
    Book(const std::string& isbn, const std::string& title, const std::string& author,
            const Chrono::Date& copyright_date, Genre genre, bool checked_out);

    const std::string& isbn() const { return isbn_; }
    const std::string& title() const { return title_; }
    const std::string& author() const { return author_; }
    const Chrono::Date& copyright_date() const { return copyright_date_; }
    Genre get_genre() const { return genre_; }
    bool checked_out() const { return checked_out_; }

    void checkout();
    void checkin();

private:
    std::string isbn_;      // International Standard Book Number
    std::string title_;
    std::string author_;
    Chrono::Date copyright_date_;
    Genre genre_;
    bool checked_out_;
};

class Invalid_ISBN : public std::logic_error {
    using std::logic_error::logic_error;
};

class Invalid_operation : public std::logic_error {
    using std::logic_error::logic_error;
};

bool is_valid_isbn(const std::string& isbn);
bool operator==(const Book& a, const Book& b);
bool operator!=(const Book& a, const Book& b);
std::ostream& operator<<(std::ostream& os, const Book& book);
