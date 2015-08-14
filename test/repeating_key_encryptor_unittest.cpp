#include "../src/repeating_key_encryptor.h"

#include <string>
#include <vector>

#include "../src/bytecontainer.h"
#include "gtest/gtest.h"

TEST(Encryption, SimplePlaintext) {
    std::string t_str = "Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal";
    ByteContainer t_bc(t_str, StringRepresentation::kAscii);
    ByteContainer t_expected("0b3637272a2b2e63622c2e69692a23693a2a3c6"
            "324202d623d63343c2a26226324272765272"
            "a282b2f20430a652e2c652a3124333a653e2b"
            "2027630c692b20283165286326302e27282f", StringRepresentation::kHex);
    ByteContainer t_key("ICE", StringRepresentation::kAscii);
    RepeatingKeyEncryptor rpe(t_bc);
    EXPECT_EQ(t_expected, rpe.Encrypt(t_key)) << t_expected.ToAscii() << " " << rpe.Encrypt(t_key).ToAscii();
}
