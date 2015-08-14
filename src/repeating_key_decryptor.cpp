#include "repeating_key_decryptor.h"

#include <iostream>

#include "bytecontainer.h"
#include "repeating_key_encryptor.h"
#include "singlebyte_decryptor.h"
#include "utilities.h"

ByteContainer RepeatingKeyDecryptor::Decrypt(const ByteContainer& key) {
    RepeatingKeyEncryptor rke(bytes_);
    return rke.Encrypt(key);
}

ByteContainer RepeatingKeyDecryptor::Decrypt() {
    for (size_t key_size = 1; key_size < 50; ++key_size) {
        ByteContainer current_key;
        for (size_t i = 0; i < key_size; ++i) {
            ByteContainer i_residue;
            for (size_t j = i; j < bytes_.size(); j += key_size) {
                i_residue.push_back(bytes_[j]);
            }
            SingleByteDecryptor sbd(i_residue);
            current_key.push_back(sbd.Decrypt());
        }
        std::cout << Decrypt(current_key).ToAscii() << " " << EnglishValue(Decrypt(current_key)) << std::endl;
    }
    return ByteContainer();
}
