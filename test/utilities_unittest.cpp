#include "../src/utilities.h"

#include <string>

#include "gtest/gtest.h"

TEST(SimpleEnglishValue, SimpleTest) {
    EXPECT_GE(SimpleEnglishValue("This is simple English plaintext!"),
            SimpleEnglishValue("Gibberish abc def ghi jklmnop"));
}
