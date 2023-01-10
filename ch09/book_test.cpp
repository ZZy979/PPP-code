#include <gtest/gtest.h>

#include <sstream>
#include <string>
#include <vector>

#include "book.h"

using namespace Chrono;

class BookTest : public ::testing::Test {
protected:
    BookTest() :book_("0-275-96781-6",
            "Programming: Principles and Practice Using C++ (2nd Edition)",
            "Bjarne Stroustrup", {2014, Month::May, 15}, Genre::computer, false) {
    }
    Book book_;
};

TEST_F(BookTest, Getter) {
    EXPECT_EQ(book_.isbn(), "0-275-96781-6");
    EXPECT_EQ(book_.title(), "Programming: Principles and Practice Using C++ (2nd Edition)");
    EXPECT_EQ(book_.author(), "Bjarne Stroustrup");
    EXPECT_EQ(book_.copyright_date(), Date(2014, Month::May, 15));
    EXPECT_EQ(book_.get_genre(), Genre::computer);
    EXPECT_FALSE(book_.checked_out());
}

TEST_F(BookTest, CheckInAndOut) {
    book_.checkout();
    EXPECT_TRUE(book_.checked_out());
    EXPECT_THROW(book_.checkout(), Invalid_operation);

    book_.checkin();
    EXPECT_FALSE(book_.checked_out());
    EXPECT_THROW(book_.checkin(), Invalid_operation);
}

TEST(HelperFunctionTest, IsValidISBN) {
    std::vector<std::string> valid{
        "0-275-96781-6", "1-234-56789-X"
    };
    for (const std::string& isbn : valid)
        EXPECT_TRUE(is_valid_isbn(isbn));

    std::vector<std::string> invalid{
        "", "1-234-56789", "abc-def-ghi-0", "1+234+56789+0", "1-234-56789-@", "=_="
    };
    for (const std::string& isbn : invalid)
        EXPECT_FALSE(is_valid_isbn(isbn));
}

TEST(HelperFunctionTest, CompareBooks) {
    Book a("1-234-56789-0", "Foo", "Alice", {2015, Month::Sep, 1}, Genre::fiction, true);
    Book b("1-234-56789-0", "Foo-2ed", "Alice", {2019, Month::Jun, 26}, Genre::fiction, false);
    Book c("9-876-54321-0", "Bar", "Alice", {2015, Month::Sep, 1}, Genre::fiction, true);
    EXPECT_EQ(a, b);
    EXPECT_NE(a, c);
}

TEST(HelperFunctionTest, OutputBook) {
    std::ostringstream oss;
    oss << Book("1-234-56789-0", "Foo", "Alice", {2015, Month::Sep, 1}, Genre::fiction, true);
    EXPECT_EQ(oss.str(), "Foo\nAlice\n1-234-56789-0\n");
}
