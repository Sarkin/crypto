// Contains formatting and string conversion utilities

#ifndef CRYPTOGRAPHY_CRYPTO_UTILITIES_H_
#define CRYPTOGRAPHY_CRYPTO_UTILITIES_H_

#include <string>

#include "types.h"

typedef unsigned char byte;
typedef std::vector<byte> ByteContainer;

// Converts an ASCII string to Base64 string.
void HexTo64(const std::string &source, std::string &destination);

// Converts a sequence of bytes to an ASCII string.
void BytesToHex(const ByteContainer &source, std::string &destination);

// Converts a hex string to a sequence of bytes.
void HexToBytes(const std::string &hex, ByteContainer &dest);


#endif // CRYPTOGRAPHY_CRYPTO_UTILITIES_H_
