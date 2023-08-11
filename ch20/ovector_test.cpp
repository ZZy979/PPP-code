#include <gtest/gtest.h>

#include "ovector.h"
#include "ch19/counted_element.h"

TEST(OvectorTest, ElementAccess) {
    ovector<int> v;
    for (int i = 0; i < 10; ++i)
        v.push_back(new int(i));
    EXPECT_EQ(v.size(), 10);
    EXPECT_EQ(v[8], 8);
}

TEST(OvectorTest, Destructor) {
    auto p = new ovector<Counted_element>;
    for (int i = 0; i < 10; ++i)
        p->push_back(new Counted_element(i));
    EXPECT_EQ(Counted_element::count(), 10);

    delete p;
    EXPECT_EQ(Counted_element::count(), 0);
}
