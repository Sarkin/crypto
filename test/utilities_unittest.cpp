#include <algorithm>
#include "../src/utilities.h"
#include "gtest/gtest.h"

TEST(Base64Value, OutOfRange) {
    EXPECT_EQ(-1, Base64Value(-1));
    EXPECT_EQ(0, Base64Value(5));
}
