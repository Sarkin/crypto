#include "../src/singlebyte_decryptor.h"

#include <string>
#include <vector>

#include "../src/bytecontainer.h"
#include "gtest/gtest.h"

TEST(Decryption, PlaintextEnglishWithKey) {
    std::string t_str = "This is my simple English plaintext string!";
    ByteContainer t_bc(t_str, StringRepresentation::kAscii);
    ByteContainer t_key(std::string(t_str.size(), '#'), StringRepresentation::kAscii);
    ByteContainer t_encrypted = t_bc ^ t_key;
    SingleByteDecryptor sbd(t_encrypted);
    EXPECT_EQ(t_bc, sbd.Decrypt('#'));
}

TEST(Decryption, PlaintextEnglishWithoutKey1) {
    std::string t_str = "This is my simple English plaintext string!";
    ByteContainer t_bc(t_str, StringRepresentation::kAscii);
    ByteContainer t_key(std::string(t_str.size(), '#'), StringRepresentation::kAscii);
    ByteContainer t_encrypted = t_bc ^ t_key;
    SingleByteDecryptor sbd(t_encrypted);
    EXPECT_EQ(t_bc, sbd.Decrypt(sbd.Decrypt()));
}

TEST(Decryption, PlaintextEnglishWithoutKey2) {
    std::string t_str = "Cooking MC's like a pound of bacon";
    ByteContainer t_encrypted = ByteContainer("1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736", StringRepresentation::kHex);
    SingleByteDecryptor sbd(t_encrypted);
    EXPECT_EQ(t_str, sbd.Decrypt(sbd.Decrypt()).ToAscii());
}
