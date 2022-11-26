#include <gtest/gtest.h>

#include "variable.h"

class CalculatorV2VariableTest : public ::testing::Test {
protected:
    void SetUp() override {
        var_table.define_name("a", 1);
    }

    Symbol_table var_table;
};

TEST_F(CalculatorV2VariableTest, GetValue) {
    EXPECT_DOUBLE_EQ(var_table.get_value("a"), 1);
    EXPECT_THROW(var_table.get_value("b"), Variable_error);
}

TEST_F(CalculatorV2VariableTest, SetValue) {
    var_table.set_value("a", 2);
    EXPECT_DOUBLE_EQ(var_table.get_value("a"), 2);
    EXPECT_THROW(var_table.set_value("b", 3), Variable_error);
}

TEST_F(CalculatorV2VariableTest, IsDeclared) {
    EXPECT_TRUE(var_table.is_declared("a"));
    EXPECT_FALSE(var_table.is_declared("b"));
}

TEST_F(CalculatorV2VariableTest, DefineName) {
    EXPECT_DOUBLE_EQ(var_table.define_name("b", 3), 3);
    EXPECT_DOUBLE_EQ(var_table.get_value("b"), 3);
    EXPECT_THROW(var_table.define_name("a", 2), Variable_error);
}
