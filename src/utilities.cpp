#include "utilities.h"

#include <algorithm>
#include <string>

#include "bytecontainer.h"

int SimpleEnglishValue(const ByteContainer& bc) {
    return SimpleEnglishValue(bc.ToAscii());
}

int SimpleEnglishValue(const std::string& str) {
    const std::string english_by_frequency = "ETAON RISHD LFCMU GYPWB VKJXQ Z";
    const int number_of_groups = std::count(english_by_frequency.begin(),
            english_by_frequency.end(), ' ');
    int score = 0;
    for (size_t i = 0; i < str.size(); ++i) {
        int frequency_index = std::find(english_by_frequency.begin(),
                english_by_frequency.end(), toupper(str[i])) -
            english_by_frequency.begin();
        int frequency_group = std::count(english_by_frequency.begin(),
                english_by_frequency.begin() + frequency_index, ' ');
        score += (1 << (number_of_groups - frequency_group));
    }
    return score;
}

int EnglishValue(const ByteContainer& bc) {
    return SimpleEnglishValue(bc);
}

int EnglishValue(const std::string& str) {
    return SimpleEnglishValue(str);
}
