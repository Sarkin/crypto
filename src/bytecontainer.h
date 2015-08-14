// Defines ByteContainer: a container for storing sequences of
// bytes with various utility, conversion and formatting methods.

#ifndef CRYPTOGRAPHY_CRYPTO_BYTECONTAINER_H_
#define CRYPTOGRAPHY_CRYPTO_BYTECONTAINER_H_

#include <vector>
#include <string>

typedef unsigned char Byte;

enum class StringRepresentation {
    kAscii,
    kHex,
    kBase64,
};

// Byte sequence with various conversion and formatting methods.
class ByteContainer {
public:
    typedef std::vector<Byte> Container;

    ByteContainer() { }
    ByteContainer(size_t size) : bytes_(size) { }
    ByteContainer(const std::string& str, StringRepresentation rep);
    const Byte& operator[](const size_t index) const { return bytes_[index]; }
    Byte& operator[](const size_t index) { return bytes_[index]; }
    // Compound XOR. If the 2 sequences have different lengths then we assume
    // that the shorter sequence is completed with 0s. This is done in order
    // to make the operation meaningful for all sequences.
    ByteContainer& operator^=(const ByteContainer& rhs);
    friend bool operator==(const ByteContainer& lhs, const ByteContainer& rhs);
    // XOR
    friend ByteContainer operator^(ByteContainer lhs, const ByteContainer& rhs);
    // Returns the size of the sequence.
    size_t size() const {
        return bytes_.size();
    }
    void push_back(Byte b) {
        bytes_.push_back(b);
    }
    // Returns ASCII representation of the byte sequence.
    std::string ToAscii() const;
    // Returns hex representation of the byte sequence.
    std::string ToHex() const;
    // Returns Base64 representation of the byte sequence.
    std::string ToBase64() const;
    // Expects 2 ByteContainers of equal size. Throws invalid_argument exception otherwise.
    friend size_t HammingDistance(const ByteContainer& lhs, const ByteContainer& rhs);
private:
    // Returns Base64 represenation of c. Returns c if c is invalid.
    int Base64Value(int c) const;
    // Build the bytes sequence from the ASCII string str.
    void BuildAscii(const std::string& str);
    // Build the bytes sequence from the hex string hex.
    void BuildHex(const std::string& hex);
    // The container used to store the byte sequence.
    Container bytes_;
};

#endif // CRYPTOGRAPHY_CRYPTO_BYTECONTAINER_H_
