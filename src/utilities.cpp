#include "utilities.h"

#include <iomanip>
#include <iterator>
#include <sstream>

std::ostream& operator << (std::ostream& os, const ByteContainer& bc) {
    std::copy(bc.begin(), bc.end(), std::ostream_iterator<int>(os, " "));
    return os;
}

void AsciiToBytes(const std::string& source, ByteContainer& destination) {
    destination.assign(source.begin(), source.end());
}

int Base64Value(int c) {
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

void BytesTo64(const ByteContainer& source, std::string& destination) {
    destination.clear();

    size_t size = source.size();
    for (size_t i = 0; i < size; ) {
        int octets[3] = {source[i++], ((i < size)? source[i++]: 0), ((i < size)? source[i++]: 0)};
        int octet_concatenation = (octets[0] << 16) | (octets[1] << 8) | octets[2];

        destination += Base64Value(octet_concatenation >> 18);
        destination += Base64Value((octet_concatenation >> 12) & 0x3f);
        destination += Base64Value((octet_concatenation >> 6) & 0x3f);
        destination += Base64Value(octet_concatenation & 0x3f);
    }
}

void BytesToHex(const ByteContainer& source, std::string& destination) {
    destination.clear();

    std::stringstream hex_string_stream;
    hex_string_stream << std::hex << std::setfill('0');
    for (size_t i = 0; i < source.size(); ++i) {
        hex_string_stream << std::setw(2) << static_cast<int>(source[i]);
    }

    destination = hex_string_stream.str();
}

void HexToBytes(const std::string& hex, ByteContainer& destination) {
    destination.clear();

    std::stringstream hex_string_stream;
    for (size_t i = 0; i < hex.length(); ) {
        hex_string_stream.clear();
        const char tmpValue[3] = {hex[i++], hex[i++], '\0'};
        hex_string_stream.str(tmpValue);
        hex_string_stream >> std::hex;

        int next_byte;
        hex_string_stream >> next_byte;
        destination.push_back(next_byte);
    }
}
