#include "../src/repeating_key_decryptor.h"

#include <string>
#include <vector>

#include "../src/bytecontainer.h"
#include "gtest/gtest.h"

TEST(Decryption, PlaintextEnglishWithKey) {
    ByteContainer t_encrypted("0b3637272a2b2e63622c2e69692a23693a2a3c6"
            "324202d623d63343c2a26226324272765272"
            "a282b2f20430a652e2c652a3124333a653e2b"
            "2027630c692b20283165286326302e27282f", StringRepresentation::kHex);
    RepeatingKeyDecryptor rkd(t_encrypted);
    ByteContainer t_key("ICE", StringRepresentation::kAscii);
    ByteContainer t_expected("Burning 'em, if you ain't quick and nimble\n"
            "I go crazy when I hear a cymbal", StringRepresentation::kAscii);
    EXPECT_EQ(t_expected, rkd.Decrypt(t_key));
}

TEST(Decryption, PlaintextEnglishWithoutKey) {
    ByteContainer t_encrypted("0b3637272a2b2e63622c2e69692a23693a2a3c6"
            "324202d623d63343c2a26226324272765272"
            "a282b2f20430a652e2c652a3124333a653e2b"
            "2027630c692b20283165286326302e27282f", StringRepresentation::kHex);
    RepeatingKeyDecryptor rkd(t_encrypted);
    ByteContainer t_expected("Burning 'em, if you ain't quick and nimble\n"
            "I go crazy when I hear a cymbal", StringRepresentation::kAscii);
    EXPECT_EQ(t_expected, rkd.Decrypt(rkd.Decrypt()));
}
