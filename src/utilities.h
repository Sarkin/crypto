// Contains formatting and string conversion utilities

#ifndef CRYPTOGRAPHY_CRYPTO_UTILITIES_H_
#define CRYPTOGRAPHY_CRYPTO_UTILITIES_H_

#include <iostream>
#include <string>
#include <vector>

typedef unsigned char Byte;
typedef std::vector<Byte> ByteContainer;

// Returns Base64 represenation of c. Returns c is c is invalid.
int Base64Value(int c);

// Prints ByteContainer elements space-separated
std::ostream& operator << (std::ostream& os, const ByteContainer& bc);

// Converts an ASCII string to a sequence of Bytes
void AsciiToBytes(const std::string& source, ByteContainer& destination);

// Converts a sequence of bytes to a Base64 string.
void BytesTo64(const ByteContainer& source, std::string& destination);

// Converts a sequence of Bytes to a hex string.
void BytesToHex(const ByteContainer& source, std::string& destination);

// Converts a hex string to a sequence of Bytes.
void HexToBytes(const std::string& hex, ByteContainer& destination);

#endif // CRYPTOGRAPHY_CRYPTO_UTILITIES_H_
