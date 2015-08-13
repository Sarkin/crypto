#include <string>

#include "../src/utilities.h"
#include "gtest/gtest.h"

TEST(SimpleEnglishValue, SimpleTest) {
    EXPECT_GE(SimpleEnglishValue("This is simple English plaintext!"),
            SimpleEnglishValue("Gibberish abc def ghi jklmnop"));
}
