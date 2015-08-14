#include "../src/bytecontainer.h"

#include <stdexcept>
#include <string>
#include <vector>

#include "gtest/gtest.h"

TEST(Construction, ASCII) {
    std::string t_str = "abcdef\0f";
    ByteContainer bc(t_str, StringRepresentation::kAscii);
    EXPECT_EQ(t_str.length(), bc.size());
    for (size_t i = 0; i < t_str.length(); ++i) {
        EXPECT_EQ(t_str[i], bc[i]);
    }
}

TEST(Construction, Hex) {
    std::string t_hex = "00010210a1ff";
    std::vector<Byte> t_expected = {0, 1, 2, 16, 161, 255};
    ByteContainer bc(t_hex, StringRepresentation::kHex);
    EXPECT_EQ(t_expected.size(), bc.size());
    for (size_t i = 0; i < t_expected.size(); ++i) {
        EXPECT_EQ(t_expected[i], bc[i]);
    }
}

TEST(Conversion, ASCII) {
    std::string t_str = "abcdef\0f";
    ByteContainer bc(t_str, StringRepresentation::kAscii);
    EXPECT_EQ(t_str, bc.ToAscii());
}

TEST(Conversion, Hex) {
    std::string t_hex = "00010210a1ff";
    ByteContainer bc(t_hex, StringRepresentation::kHex);
    EXPECT_EQ(t_hex, bc.ToHex());
}

TEST(Conversion, Base64) {
    std::string t_str = "I'm killing your brain like a poisonous mushroom";
    ByteContainer bc(t_str, StringRepresentation::kAscii);
    std::string t_expected = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
    EXPECT_EQ(t_expected, bc.ToBase64());
}

TEST(XOR, EqualSequences) {
    ByteContainer t_bc("abcdef012345", StringRepresentation::kAscii);
    ByteContainer xor_res = t_bc ^ t_bc;
    EXPECT_EQ(t_bc.size(), xor_res.size());
    for (size_t i = 0; i < xor_res.size(); ++i) {
        EXPECT_EQ(0, xor_res[i]);
    }
}

TEST(XOR, EqualLengthSequences) {
    ByteContainer t_bc1("1c0111001f010100061a024b53535009181c", StringRepresentation::kHex);
    ByteContainer t_bc2("686974207468652062756c6c277320657965", StringRepresentation::kHex);
    ByteContainer t_expected("746865206b696420646f6e277420706c6179", StringRepresentation::kHex);
    EXPECT_EQ(t_expected, t_bc1 ^ t_bc2);
}

TEST(XOR, DifferentLengthSequences) {
    ByteContainer t_bc1("1c0111001f010100061a024b53535009181c", StringRepresentation::kHex);
    ByteContainer t_bc2("686974207468652062756c6c2773206579", StringRepresentation::kHex);
    ByteContainer t_expected("746865206b696420646f6e277420706c611c", StringRepresentation::kHex);
    EXPECT_EQ(t_expected, t_bc1 ^ t_bc2);
}

TEST(HammingDistance, EqualSequences) {
    ByteContainer t_bc("1c0111001f010100061a024b53535009181c", StringRepresentation::kHex);
    EXPECT_EQ(0, HammingDistance(t_bc, t_bc));
}

TEST(HammingDistance, DifferentSequences) {
    ByteContainer t_bc1("kinan sarmini", StringRepresentation::kAscii);
    ByteContainer t_bc2("kinan sarbigi", StringRepresentation::kAscii);
    EXPECT_EQ(2, HammingDistance(t_bc1, t_bc2));
}

TEST(HammingDistance, DifferentLengthSequences) {
    ByteContainer t_bc1("kinan", StringRepresentation::kAscii);
    ByteContainer t_bc2("kinan sarbigi", StringRepresentation::kAscii);
    ASSERT_THROW(HammingDistance(t_bc1, t_bc2), std::invalid_argument);
}
