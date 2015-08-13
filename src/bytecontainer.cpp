#include "bytecontainer.h"

#include <iomanip>
#include <stdexcept>
#include <sstream>
#include <string>
#include <vector>

ByteContainer::ByteContainer(const std::string& str, StringRepresentation rep) {
    switch (rep) {
        case StringRepresentation::kAscii:
            BuildAscii(str);
            break;
        case StringRepresentation::kHex:
            BuildHex(str);
            break;
        default:
            break;
    }
}

void ByteContainer::BuildAscii(const std::string& str) {
    bytes_.assign(str.begin(), str.end());
}

void ByteContainer::BuildHex(const std::string& hex) {
    std::stringstream hex_string_stream;
    for (size_t i = 0; i < hex.length(); ) {
        hex_string_stream.clear();
        const char tmpValue[3] = {hex[i++], hex[i++], '\0'};
        hex_string_stream.str(tmpValue);
        hex_string_stream >> std::hex;

        int next_byte;
        hex_string_stream >> next_byte;
        bytes_.push_back(next_byte);
    }
}

std::string ByteContainer::ToAscii() const {
    return std::string(bytes_.begin(), bytes_.end());
}

std::string ByteContainer::ToHex() const {
    std::stringstream hex_string_stream;
    hex_string_stream << std::hex << std::setfill('0');
    for (size_t i = 0; i < bytes_.size(); ++i) {
        hex_string_stream << std::setw(2) << static_cast<int>(bytes_[i]);
    }
    return hex_string_stream.str();
}

std::string ByteContainer::ToBase64() const {
    std::string res;
    size_t size = bytes_.size();
    for (size_t i = 0; i < size; ) {
        int octets[3] = {bytes_[i++], ((i < size)? bytes_[i++]: 0), ((i < size)? bytes_[i++]: 0)};
        int octet_concatenation = (octets[0] << 16) | (octets[1] << 8) | octets[2];

        res += Base64Value(octet_concatenation >> 18);
        res += Base64Value((octet_concatenation >> 12) & 0x3f);
        res += Base64Value((octet_concatenation >> 6) & 0x3f);
        res += Base64Value(octet_concatenation & 0x3f);
    }
    return res;
}

int ByteContainer::Base64Value(int c) const {
    if (c < 0 || c >= 64) {
        return c;
    } else if (c < 26) {
        return c + 'A';
    } else if (c < 52) {
        return c - 26 + 'a';
    } else if (c < 62) {
        return c - 52 + '0';
    } else if (c == 62) {
        return '+';
    }
    return '/';
}

ByteContainer& ByteContainer::operator^=(const ByteContainer& rhs) {
    if (rhs.size() > bytes_.size()) {
        bytes_.resize(rhs.size());
    }
    for (size_t i = 0; i < rhs.size(); ++i) {
        bytes_[i] ^= rhs[i];
    }
    return *this;
}

ByteContainer operator^(ByteContainer lhs, const ByteContainer& rhs) {
    return lhs ^= rhs;
}

bool operator==(const ByteContainer& lhs, const ByteContainer& rhs) {
    if (lhs.size() != rhs.size()) {
        return false;
    }
    for (size_t i = 0; i < lhs.size(); ++i) {
        if (lhs[i] != rhs[i]) {
            return false;
        }
    }
    return true;
}

size_t HammingDistance(const ByteContainer& lhs, const ByteContainer& rhs) {
    if (lhs.size() != rhs.size()) {
        throw std::invalid_argument("lhs and rhs have different sizes");
    }
    size_t res = 0;
    for (size_t i = 0; i < lhs.size(); ++i) {
        res += (lhs[i] != rhs[i]);
    }
    return res;
}
