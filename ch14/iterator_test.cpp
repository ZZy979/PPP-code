#include <gtest/gtest.h>
#include <sstream>

#include "iterator.h"

TEST(VectorIterator, Nonempty) {
    std::vector<double> v{0.1, 0.2, 0.3};
    Vector_iterator it(v);

    double* p = it.next();
    EXPECT_NE(p, nullptr);
    EXPECT_DOUBLE_EQ(*p, 0.1);
    *p = 0.4;
    EXPECT_DOUBLE_EQ(v[0], 0.4);

    EXPECT_NE(p = it.next(), nullptr);
    EXPECT_DOUBLE_EQ(*p, 0.2);

    EXPECT_NE(p = it.next(), nullptr);
    EXPECT_DOUBLE_EQ(*p, 0.3);

    EXPECT_EQ(it.next(), nullptr);
}

TEST(VectorIterator, Empty) {
    std::vector<double> v;
    Vector_iterator it(v);
    EXPECT_EQ(it.next(), nullptr);
}

TEST(ListIterator, Nonempty) {
    std::list<double> l{0.1, 0.2, 0.3};
    List_iterator it(l);

    double* p = it.next();
    EXPECT_NE(p, nullptr);
    EXPECT_DOUBLE_EQ(*p, 0.1);
    *p = 0.4;
    EXPECT_DOUBLE_EQ(l.front(), 0.4);

    EXPECT_NE(p = it.next(), nullptr);
    EXPECT_DOUBLE_EQ(*p, 0.2);

    EXPECT_NE(p = it.next(), nullptr);
    EXPECT_DOUBLE_EQ(*p, 0.3);

    EXPECT_EQ(it.next(), nullptr);
}

TEST(ListIterator, Empty) {
    std::list<double> l;
    List_iterator it(l);
    EXPECT_EQ(it.next(), nullptr);
}

TEST(Print, VectorIterator) {
    struct Test_case {
        std::vector<double> v;
        std::string expected;
    } test_cases[] = {
        {{0.1, 0.2, 0.3}, "0.1 0.2 0.3 "},
        {{3.14}, "3.14 "},
        {{}, ""}
    };
    for (Test_case t : test_cases) {
        Vector_iterator it(t.v);
        std::ostringstream oss;
        print(oss, it);
        EXPECT_EQ(t.expected, oss.str());
    }
}

TEST(Print, ListIterator) {
    struct Test_case {
        std::list<double> l;
        std::string expected;
    } test_cases[] = {
        {{0.1, 0.2, 0.3}, "0.1 0.2 0.3 "},
        {{3.14}, "3.14 "},
        {{}, ""}
    };
    for (Test_case t : test_cases) {
        List_iterator it(t.l);
        std::ostringstream oss;
        print(oss, it);
        EXPECT_EQ(t.expected, oss.str());
    }
}
