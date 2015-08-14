// Defines RepeatingKeyDecryptor: a class that decrypts a message
// encrypted using a repeating-key cipher.

#ifndef CRYPTOGRAPHY_CRYPTO_REPEATING_KEY_DECRYPTOR_H_
#define CRYPTOGRAPHY_CRYPTO_REPEATING_KEY_DECRYPTOR_H_

#include "bytecontainer.h"

class RepeatingKeyDecryptor {
public:
    RepeatingKeyDecryptor(const ByteContainer& bc) : bytes_(bc) { }
    // Returns the decryption of the cipher text using key.
    ByteContainer Decrypt(const ByteContainer& key);
    // Cryptographic attack! Try to guess the key and choose best candidate. Returns the key.
    ByteContainer Decrypt();
private:
    ByteContainer bytes_;
};

#endif // CRYPTOGRAPHY_CRYPTO_REPEATING_KEY_DECRYPTOR_H_
