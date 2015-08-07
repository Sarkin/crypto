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

void HexTo64(const std::string& source, std::string& destination) {
}

void BytesToHex(const ByteContainer& source, std::string& destination) {
    destination.clear();

    std::stringstream hexStringStream;
    hexStringStream << std::hex << std::setfill('0');
    for (size_t i = 0; i < source.size(); ++i) {
        hexStringStream << std::setw(2) << static_cast<int>(source[i]);
    }

    destination = hexStringStream.str();
}

void HexToBytes(const std::string& hex, ByteContainer& dest) {
}
