#include <gtest/gtest.h>

#include "temperature_converters.h"

TEST(Ctok, Good) {
    EXPECT_DOUBLE_EQ(ctok(-273.15), 0);
    EXPECT_DOUBLE_EQ(ctok(0), 273.15);
    EXPECT_DOUBLE_EQ(ctok(100), 373.15);
}

TEST(Ctok, Bad) {
    EXPECT_THROW(ctok(-280), std::invalid_argument);
}

TEST(Ktoc, Good) {
    EXPECT_DOUBLE_EQ(ktoc(0), -273.15);
    EXPECT_DOUBLE_EQ(ktoc(273.15), 0);
    EXPECT_DOUBLE_EQ(ktoc(500), 226.85);
}

TEST(Ktoc, Bad) {
    EXPECT_THROW(ktoc(-1), std::invalid_argument);
}

TEST(Ctof, Good) {
    EXPECT_DOUBLE_EQ(ctof(-273.15), -459.67);
    EXPECT_DOUBLE_EQ(ctof(0), 32);
    EXPECT_DOUBLE_EQ(ctof(18), 64.4);
}

TEST(Ctof, Bad) {
    EXPECT_THROW(ctof(-300), std::invalid_argument);
}

TEST(Ftoc, Good) {
    EXPECT_DOUBLE_EQ(ftoc(-459.67), -273.15);
    EXPECT_DOUBLE_EQ(ftoc(0), -160.0 / 9);
    EXPECT_DOUBLE_EQ(ftoc(1234.56), 30064.0 / 45);
}

TEST(Ftoc, Bad) {
    EXPECT_THROW(ftoc(-500), std::invalid_argument);
}
