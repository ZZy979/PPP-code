#include <gtest/gtest.h>

#include "matrix_operation.h"

using namespace Numeric_lib;

using IntVector = Matrix<int, 1>;
using IntMatrix = Matrix<int, 2>;
using IntTensor = Matrix<int, 3>;

class MatrixOperationTest : public ::testing::Test {
protected:
    MatrixOperationTest() :a1_(4), a2_(3), b1_(3, 4), b2_(4, 2), c1_(2, 3, 4), c2_(3, 2, 4) {
        int a1[4] = {1, 2, 3, 4}, a2[3] = {5, 6, 7};
        a1_ = IntVector(a1);
        a2_ = IntVector(a2);

        int b1[3][4] = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
        };
        int b2[4][2] = {
            {8, 3},
            {5, 1},
            {4, 7},
            {2, 6}
        };
        b1_ = IntMatrix(b1);
        b2_ = IntMatrix(b2);

        int c1[2][3][4] = {
            {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
            {{13, 14, 15, 16}, {17, 18, 19, 20}, {21, 22, 23, 24}}
        };
        int c2[3][2][4] = {
            {{24, 23, 22, 21}, {20, 19, 18, 17}},
            {{16, 15, 14, 13}, {12, 11, 10, 9}},
            {{8, 7, 6, 5}, {4, 3, 2, 1}}
        };
        c1_ = IntTensor(c1);
        c2_ = IntTensor(c2);
    }

    IntVector a1_, a2_;
    IntMatrix b1_, b2_;
    IntTensor c1_, c2_;
};

TEST_F(MatrixOperationTest, MatrixVectorMultiply) {
    int expected[3] = {30, 70, 110};
    EXPECT_EQ(mm(b1_, a1_), IntVector(expected));

    EXPECT_THROW(mm(b1_, a2_), Matrix_error);
}

TEST_F(MatrixOperationTest, MatrixMultiply) {
    int expected[3][2] = {{38, 50}, {114, 118}, {190, 186}};
    EXPECT_EQ(mm(b1_, b2_), IntMatrix(expected));

    EXPECT_THROW(mm(b2_, b1_), Matrix_error);
}

TEST_F(MatrixOperationTest, VectorAdd) {
    int expected[4] = {6, 8, 10, 12};
    EXPECT_EQ(a1_ + b1_[1], IntVector(expected));

    EXPECT_THROW(a1_ + a2_, Matrix_error);
}

TEST_F(MatrixOperationTest, MatrixAdd) {
    IntMatrix b3 = b1_ * 2;
    int expected[3][4] = {
        {3, 6, 9, 12},
        {15, 18, 21, 24},
        {27, 30, 33, 36}
    };
    EXPECT_EQ(b1_ + b3, IntMatrix(expected));

    EXPECT_THROW(b1_ + b2_, Matrix_error);
}

TEST_F(MatrixOperationTest, TensorAdd) {
    IntTensor c3 = c1_ / 3;
    int expected[2][3][4] = {
        {{1, 2, 4, 5}, {6, 8, 9, 10}, {12, 13, 14, 16}},
        {{17, 18, 20, 21}, {22, 24, 25, 26}, {28, 29, 30, 32}}
    };
    EXPECT_EQ(c1_ + c3, IntTensor(expected));

    EXPECT_THROW(c1_ + c2_, Matrix_error);
}
