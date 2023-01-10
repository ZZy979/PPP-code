#include <gtest/gtest.h>

#include "patron.h"

class PatronTest : public ::testing::Test {
protected:
    PatronTest() :alice("Alice", 12345, 0.0) {}

    Patron alice;
};

TEST_F(PatronTest, GetterSetter) {
    EXPECT_EQ(alice.name(), "Alice");
    EXPECT_EQ(alice.card_number(), 12345);
    EXPECT_DOUBLE_EQ(alice.owed_fees(), 0.0);
    EXPECT_FALSE(alice.owes_fees());

    alice.set_owed_fees(3.6);
    EXPECT_DOUBLE_EQ(alice.owed_fees(), 3.6);
    EXPECT_TRUE(alice.owes_fees());
}
