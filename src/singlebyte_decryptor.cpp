#include "singlebyte_decryptor.h"

#include <algorithm>
#include <map>
#include <iostream>

#include "bytecontainer.h"

ByteContainer SingleByteDecryptor::Decrypt(Byte key) {
    ByteContainer res(bytes_);
    for (size_t i = 0; i < res.size(); ++i) {
        res[i] ^= key;
    }
    return res;
}

ByteContainer SingleByteDecryptor::Decrypt() {
    std::string letters_by_frequency = "ETAON RISHD LFCMU GYPWB VKJXQ Z";
    int mx_score = 0;
    ByteContainer bst;
    for (int key = 0; key < 256; key++) {
        ByteContainer now = Decrypt(key);
        int score = 0;
        for (size_t i = 0; i < now.size(); ++i) {
            int cur = std::find(letters_by_frequency.begin(), letters_by_frequency.end(), toupper(now[i])) - letters_by_frequency.begin();
            score += (1 << (10 - std::count(letters_by_frequency.begin(), letters_by_frequency.begin() + cur, ' ')));
        }
        if (score > mx_score) {
            mx_score = score;
            bst = now;
        }
    }
    return bst;
}
