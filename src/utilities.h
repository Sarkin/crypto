#ifndef CRYPTOGRAPHY_CRYPTO_UTILITIES_H_
#define CRYPTOGRAPHY_CRYPTO_UTILITIES_H_

#include <string>

#include "bytecontainer.h"

// A simple English plaintext scoring function. Uses simple frequency
// analysis.
int SimpleEnglishValue(const ByteContainer& bc);
// Same as above
int SimpleEnglishValue(const std::string& str);

#endif // CRYPTOGRAPHY_CRYPTO_UTILITIES_H_
