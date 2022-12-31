#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include <vector>

#include "print_vector.h"

TEST(PrintVectorTest, Nonempty) {
    std::vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19};
    std::ostringstream oss;
    std::string expected = "primes = {2, 3, 5, 7, 11, 13, 17, 19}";
    print("primes", primes, oss);
    EXPECT_EQ(oss.str(), expected);
}

TEST(PrintVectorTest, Empty) {
    std::vector<int> nothing;
    std::ostringstream oss;
    std::string expected = "nothing = {}";
    print("nothing", nothing, oss);
    EXPECT_EQ(oss.str(), expected);
}
