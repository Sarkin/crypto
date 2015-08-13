#include "singlebyte_decryptor.h"

#include <algorithm>

#include "bytecontainer.h"
#include "utilities.h"

ByteContainer SingleByteDecryptor::Decrypt(Byte key) {
    ByteContainer res(bytes_);
    for (size_t i = 0; i < res.size(); ++i) {
        res[i] ^= key;
    }
    return res;
}

ByteContainer SingleByteDecryptor::Decrypt() {
    std::pair<int, int> value_key(0, 0);
    for (int key = 0; key < 256; key++) {
        value_key = std::max(value_key, std::make_pair(SimpleEnglishValue(Decrypt(key)), key));
    }
    return Decrypt(value_key.second);
}
