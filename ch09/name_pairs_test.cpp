#include <gtest/gtest.h>

#include <sstream>

#include "name_pairs.h"

TEST(NamePairsTest, ReadSortPrint) {
    Name_pairs p(8);
    std::istringstream iss("Cindy Frank Bob Helen Grace Alice Eric Dale 26 25 28 25 26 24 27 25");
    std::ostringstream oss;
    
    p.read_names(iss);
    p.read_ages(iss);
    p.print(oss);
    EXPECT_EQ(oss.str(), "(Cindy,26)\n(Frank,25)\n(Bob,28)\n(Helen,25)\n(Grace,26)\n(Alice,24)\n(Eric,27)\n(Dale,25)\n");

    p.sort();
    oss.str("");
    oss << p;
    EXPECT_EQ(oss.str(), "(Alice,24)\n(Bob,28)\n(Cindy,26)\n(Dale,25)\n(Eric,27)\n(Frank,25)\n(Grace,26)\n(Helen,25)\n");
}

TEST(NamePairsTest, DuplicateNames) {
    Name_pairs p(5);
    std::istringstream iss("Alice Bob Alice Alice Bob 8 6 5 9 7");
    std::ostringstream oss;

    iss >> p;
    p.sort();
    oss << p;
    EXPECT_EQ(oss.str(), "(Alice,5)\n(Alice,8)\n(Alice,9)\n(Bob,6)\n(Bob,7)\n");
}

TEST(NamePairsTest, IncompleteInput) {
    Name_pairs p(3);
    std::istringstream iss("Alice Bob 10 @#$");
    std::ostringstream oss;

    EXPECT_FALSE(iss >> p);
    oss << p;
    EXPECT_EQ(oss.str(), "(Alice,0)\n(Bob,0)\n(10,0)\n");
}

TEST(NamePairsTest, Equal) {
    Name_pairs a(3), b(3), c(3), d(4);
    std::istringstream iss(
            "Alice Bob Cindy 16 18 15 "
            "Alice Bob Cindy 16 18 15 "
            "Alice Bob Cindy 16 17 15 "
            "Alice Bob Cindy Dale 16 18 15 17");

    EXPECT_TRUE(iss >> a >> b >> c >> d);
    EXPECT_EQ(a, b);
    EXPECT_NE(a, c);
    EXPECT_NE(a, d);
}
