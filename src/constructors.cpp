#include <BigNum.h>

bignum::BigNum::BigNum(const std::string &num) {
    
    size_t dot_count = std::count(num.begin(), num.end(), '.');

    if (dot_count > 1) {
        throw std::runtime_error("Can not convert non-number string to BigNum");
    }
    size_t length = num.size();
    if (dot_count == 1) {
        int64_t dot_pos = num.find('.');
        _fraction_shift = length - dot_pos;
        --length;
        std::string new_string = num.substr(0, dot_pos) + num.substr(dot_pos + 1, length - dot_pos - 1);
    }
    else {
        _fraction_shift = 0;
        std::string new_string = num;
    }
    for (size_t i = length; i > 0; i -= CHUNK_LEN) {
        _chunks.push_back(std::stoll(num.substr(std::max(0ul, i - CHUNK_LEN), std::min(static_cast<size_t>(CHUNK_LEN), i))));
    }

}
