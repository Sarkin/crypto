// Contains formatting and string conversion utilities

#ifndef CRYPTOGRAPHY_CRYPTO_UTILITIES_H_
#define CRYPTOGRAPHY_CRYPTO_UTILITIES_H_

#include <iostream>
#include <string>
#include <vector>

typedef unsigned char byte;
typedef std::vector<byte> ByteContainer;

// Prints ByteContainer elements space-separated
std::ostream& operator << (std::ostream& os, const ByteContainer& bc);

// Converts an ASCII string to a sequence of bytes
void AsciiToBytes(const std::string& source, ByteContainer& destination);

// Converts an ASCII string to Base64 string.
void HexTo64(const std::string& source, std::string& destination);

// Converts a sequence of bytes to a hex string.
void BytesToHex(const ByteContainer& source, std::string& destination);

// Converts a hex string to a sequence of bytes.
void HexToBytes(const std::string& hex, ByteContainer& destination);

#endif // CRYPTOGRAPHY_CRYPTO_UTILITIES_H_
