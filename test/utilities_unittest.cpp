#include <algorithm>
#include <string>
#include <vector>

#include "../src/utilities.h"
#include "gtest/gtest.h"

TEST(Base64Value, OutOfRange) {
    EXPECT_EQ(-1, Base64Value(-1));
    EXPECT_EQ(64, Base64Value(64));
    EXPECT_EQ(-100, Base64Value(-100));
    EXPECT_EQ(100, Base64Value(100));
}

TEST(Base64Value, Correctness) {
    EXPECT_EQ('A', Base64Value(0));
    EXPECT_EQ('Z', Base64Value(25));
    EXPECT_EQ('a', Base64Value(26));
    EXPECT_EQ('z', Base64Value(51));
    EXPECT_EQ('0', Base64Value(52));
    EXPECT_EQ('9', Base64Value(61));
    EXPECT_EQ('+', Base64Value(62));
    EXPECT_EQ('/', Base64Value(63));
}

// BytesToHex(HexToBytes(a)) == a
TEST(BytesToHex, Consistency) {
    std::string hex = "a0ffb9c7001122338591f7b1c4";
    ByteContainer bc;
    HexToBytes(hex, bc);
    std::string tmp;
    BytesToHex(bc, tmp);
    EXPECT_EQ(hex, tmp);
}

// HexToBytes(BytesToHex(a)) == a
TEST(HexToBytes, Consistency) {
    ByteContainer bc;
    for (size_t i = 0; i < (1 << 8); ++i) {
        bc.push_back(i);
    }
    std::string hex;
    BytesToHex(bc, hex);
    ByteContainer tmp;
    HexToBytes(hex, tmp);
    EXPECT_EQ(bc, tmp);
}

TEST(BytesToHex, SimpleByteSequence) {
    ByteContainer bc = {0, 1, 2, 16, 161};
    std::string hex;
    BytesToHex(bc, hex);
    EXPECT_EQ("00010210a1", hex);
}

TEST(HexToBytes, SimpleHexString) {
    std::string hex = "00010210a1";
    ByteContainer bc;
    HexToBytes(hex, bc);
    EXPECT_EQ(ByteContainer({0, 1, 2, 16, 161}), bc);
}

TEST(BytesTo64, SimpleByteSequenceTest) {
    std::string str = "I'm killing your brain like a poisonous mushroom";
    ByteContainer bc;
    AsciiToBytes(str, bc);
    std::string str64;
    BytesTo64(bc, str64);
    EXPECT_EQ("SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsa"
            "WtlIGEgcG9pc29ub3VzIG11c2hyb29t", str64);
}

TEST(XorAscii, SimpleAsciiStrings) {
    std::string lhs = "abcABC";
    std::string rhs = "abcabc";
    std::string res;
    XorAscii(lhs, rhs, res);
    EXPECT_EQ(std::string(3, '\0') + std::string(3, ' '), res);
}
