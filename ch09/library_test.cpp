#include <gmock/gmock.h>

#include "Chrono.h"
#include "library.h"

using namespace Chrono;

class LibraryTest : public ::testing::Test {
protected:
    LibraryTest() :library_(
            {
                {"1-111-11111-1", "B1", "A1", {2001, Month::Jan, 1}, Genre::fiction, false},
                {"2-222-22222-2", "B2", "A2", {2002, Month::Feb, 2}, Genre::nonfiction, false},
                {"3-333-33333-3", "B3", "A3", {2003, Month::May, 3}, Genre::periodical, false},
                {"4-444-44444-4", "B4", "A4", {2004, Month::Apr, 4}, Genre::biography, false},
                {"5-555-55555-5", "B5", "A5", {2005, Month::May, 5}, Genre::children, false}
            },
            {
                {"Alice", 111, 0.0},
                {"Bob", 222, 2.5},
                {"Cindy", 333, 0.0},
                {"Dale", 444, 1.8}
            }, {}) {
    }

    Library library_;
};

TEST_F(LibraryTest, AddBook) {
    Book b6("6-666-66666-6", "B6", "A6", {2006, Month::Jun, 6}, Genre::fiction, false);
    Book b1("1-111-11111-1", "B11", "A11", {2011, Month::Jan, 1}, Genre::fiction, false);
    EXPECT_TRUE(library_.add_book(b6));
    EXPECT_EQ(library_.get_book("6-666-66666-6").title(), "B6");
    EXPECT_FALSE(library_.add_book(b1));
    EXPECT_EQ(library_.get_book("1-111-11111-1").title(), "B1");
}

TEST_F(LibraryTest, AddPatron) {
    Patron eric("Eric", 555, 3.2), frank("Frank", 222, 0.0);
    EXPECT_TRUE(library_.add_patron(eric));
    EXPECT_EQ(library_.get_patron(555).name(), "Eric");
    EXPECT_FALSE(library_.add_patron(frank));
    EXPECT_EQ(library_.get_patron(222).name(), "Bob");
}

TEST_F(LibraryTest, CheckOutBook) {
    Date borrow_date(2023, Month::Jan, 9);

    // no such book
    EXPECT_THROW(library_.check_out_book("6-666-66666-6", 111, borrow_date), No_such_book);

    // no such patron
    EXPECT_THROW(library_.check_out_book("1-111-11111-1", 555, borrow_date), No_such_patron);

    // patron owes fees
    EXPECT_THROW(library_.check_out_book("1-111-11111-1", 222, borrow_date), Patron_owes_fees);

    // check out successfully
    library_.check_out_book("5-555-55555-5", 333, borrow_date);
    EXPECT_TRUE(library_.get_book("5-555-55555-5").checked_out());
    EXPECT_EQ(library_.get_transactions().size(), 1);
    const Transaction& transaction = library_.get_transactions()[0];
    EXPECT_EQ(transaction.book.isbn(), "5-555-55555-5");
    EXPECT_EQ(transaction.patron.card_number(), 333);
    EXPECT_EQ(transaction.borrow_date, borrow_date);

    // book already checked out
    EXPECT_THROW(library_.check_out_book("5-555-55555-5", 111, borrow_date), Invalid_operation);
}

TEST_F(LibraryTest, PatronsOwingFees) {
    using ::testing::UnorderedElementsAre;
    EXPECT_THAT(library_.patrons_owing_fees(), UnorderedElementsAre("Bob", "Dale"));
}
