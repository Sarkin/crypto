// Defines RepeatingKeyEncryptor: a class that encrypts a message
// using a repeating-key cipher.

#ifndef CRYPTOGRAPHY_CRYPTO_REPEATING_KEY_ENCRYPTOR_H_
#define CRYPTOGRAPHY_CRYPTO_REPEATING_KEY_ENCRYPTOR_H_

#include "bytecontainer.h"

class RepeatingKeyEncryptor {
public:
    RepeatingKeyEncryptor(const ByteContainer& bc) : bytes_(bc) { }
    // Returns the encryption of bytes_ using key.
    ByteContainer Encrypt(const ByteContainer& key) const;
private:
    ByteContainer bytes_;
};

#endif // CRYPTOGRAPHY_CRYPTO_REPEATING_KEY_ENCRYPTOR_H_
