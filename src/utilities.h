// Contains formatting and string conversion utilities

#ifndef CRYPTOGRAPHY_CRYPTO_UTILITIES_H_
#define CRYPTOGRAPHY_CRYPTO_UTILITIES_H_

#include <iostream>
#include <string>
#include <vector>

typedef unsigned char Byte;
typedef std::vector<Byte> ByteContainer;

// Returns Base64 represenation of c. Returns c if c is invalid.
int Base64Value(int c);

// Prints ByteContainer elements space-separated.
std::ostream& operator << (std::ostream& os, const ByteContainer& bc);

// Converts an ASCII string to a sequence of bytes.
void AsciiToBytes(const std::string& source, ByteContainer& destination);

// Converts sequence of bytes to an ASCII string.
void BytesToAscii(const ByteContainer& source, std::string& destination);

// Converts a sequence of bytes to a Base64 string.
void BytesTo64(const ByteContainer& source, std::string& destination);

// Converts a sequence of bytes to a hex string.
void BytesToHex(const ByteContainer& source, std::string& destination);

// Converts a hex string to a sequence of bytes.
void HexToBytes(const std::string& hex, ByteContainer& destination);

// XORs 2 byte sequences.
void XorBytes(const ByteContainer& lhs, const ByteContainer& rhs,
        ByteContainer& res);

// XORs 2 ASCII strings.
void XorAscii(const std::string& lhs, const std::string& rhs,
        std::string &res);

#endif // CRYPTOGRAPHY_CRYPTO_UTILITIES_H_
