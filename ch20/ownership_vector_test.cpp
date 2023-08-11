#include <gtest/gtest.h>

#include "ownership_vector.h"
#include "ch19/counted_element.h"

TEST(OwnershipVectorTest, ElementAccess) {
    ownership_vector<int> v;
    for (int i = 0; i < 10; ++i)
        v.push_back(new int(i));

    int a[] = {10, 11, 12};
    for (int& x : a)
        v.push_back(x);

    EXPECT_EQ(v.size(), 13);
    EXPECT_EQ(v[8], 8);
    EXPECT_EQ(v[11], 11);
}

TEST(OwnershipVectorTest, Destructor) {
    std::vector<Counted_element> v(8);
    auto p = new ownership_vector<Counted_element>;
    for (int i = 0; i < 10; ++i)
        p->push_back(new Counted_element(i));
    EXPECT_EQ(Counted_element::count(), 18);

    delete p;
    EXPECT_EQ(Counted_element::count(), 8);
}
