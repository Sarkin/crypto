// Defines SingleByteDecryptor: a class that decrypts a message
// encrypted using a single-byte XOR cipher.

#ifndef CRYPTOGRAPHY_CRYPTO_SINGLEBYTE_DECRYPTOR_H_
#define CRYPTOGRAPHY_CRYPTO_SINGLEBYTE_DECRYPTOR_H_

#include "bytecontainer.h"

class SingleByteDecryptor {
public:
    SingleByteDecryptor(const ByteContainer& bc) : bytes_(bc) { }
    // Returns the decryption of the cipher text using key.
    ByteContainer Decrypt(Byte key);
    // Cryptographic attack! Try to guess the key and choose best candidate. Returns the key.
    Byte Decrypt();
private:
    ByteContainer bytes_;
};

#endif // CRYPTOGRAPHY_CRYPTO_SINGLEBYTE_DECRYPTOR_H_
