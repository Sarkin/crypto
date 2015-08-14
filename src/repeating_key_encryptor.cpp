#include "repeating_key_encryptor.h"

#include <stdexcept>

#include "bytecontainer.h"

ByteContainer RepeatingKeyEncryptor::Encrypt(const ByteContainer& key) const {
    ByteContainer res(bytes_);
    if (key.size() == 0) {
        return key;
    }
    for (size_t i = 0, k = 0; i < bytes_.size(); ++i) {
        res[i] ^= key[k];
        if (++k == key.size()) {
            k = 0;
        }
    }
    return res;
}
