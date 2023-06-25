#include <gtest/gtest.h>

#include "symbol_table.h"

class SymbolTableTest : public ::testing::Test {
protected:
    void SetUp() override {
        var_table.define_name("a", 1);
        var_table.define_name("b", 2);
    }

    Symbol_table var_table;
};

TEST_F(SymbolTableTest, GetValue) {
    EXPECT_DOUBLE_EQ(var_table.get_value("a"), 1);
    EXPECT_DOUBLE_EQ(var_table.get_value("b"), 2);
    EXPECT_THROW(var_table.get_value("c"), Variable_error);
}

TEST_F(SymbolTableTest, SetValue) {
    var_table.set_value("a", 2);
    EXPECT_DOUBLE_EQ(var_table.get_value("a"), 2);
    EXPECT_THROW(var_table.set_value("c", 4), Variable_error);
}

TEST_F(SymbolTableTest, IsDeclared) {
    EXPECT_TRUE(var_table.is_declared("a"));
    EXPECT_TRUE(var_table.is_declared("b"));
    EXPECT_FALSE(var_table.is_declared("c"));
}

TEST_F(SymbolTableTest, DefineName) {
    EXPECT_DOUBLE_EQ(var_table.define_name("c", 3), 3);
    EXPECT_DOUBLE_EQ(var_table.get_value("c"), 3);
    EXPECT_THROW(var_table.define_name("a", 2), Variable_error);
    EXPECT_THROW(var_table.define_name("b", 3), Variable_error);
}
