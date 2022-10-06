#include <gtest/gtest.h>

#include "area.h"

TEST(AreaTest, Good) {
    EXPECT_EQ(12, area(3, 4));
    EXPECT_EQ(40, area(8, 5));
}

TEST(AreaTest, Bad) {
    EXPECT_THROW(area(0, 1), Bad_area);
    EXPECT_THROW(area(-1, 2), Bad_area);
    EXPECT_THROW(area(2, 0), Bad_area);
    EXPECT_THROW(area(0, -1), Bad_area);
}

TEST(FramedAreaTest, Good) {
    EXPECT_EQ(2, framed_area(3, 4));
    EXPECT_EQ(18, framed_area(8, 5));
}

TEST(FramedAreaTest, Bad) {
    EXPECT_THROW(framed_area(2, 3), Bad_area);
    EXPECT_THROW(framed_area(1, 4), Bad_area);
    EXPECT_THROW(framed_area(4, 2), Bad_area);
    EXPECT_THROW(framed_area(-1, 1), Bad_area);
}
