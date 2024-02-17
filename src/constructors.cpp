#include <BigNum.h>

namespace bignum{
  
    BigNum::BigNum(const std::string &num) {
    
        size_t dot_count = std::count(num.begin(), num.end(), '.');
        if (dot_count > 1) {
            throw std::runtime_error("Can not convert non-number string to BigNum");
        }
        size_t length = num.size();
        std::string new_string = num;
        if (new_string[0] == '-') {
            _is_neg = true;
            new_string.erase(0, 1);
            --length;
        }
        else {
            _is_neg = false;
        }
        if (dot_count == 1) {
            int64_t dot_pos = new_string.find('.');
            while (new_string[length - 1] == '0') {
                if (length - 1 == dot_pos) {
                    new_string.pop_back();
                    --length;
                    break;
                }
                new_string.pop_back();
                --length;
            }
            _fraction_shift = length - dot_pos;
            --length;
            new_string = new_string.substr(0, dot_pos) + new_string.substr(dot_pos + 1, length - dot_pos);
        }
        else {
            _fraction_shift = 0;
        }
        for (long long int i = length; i > 0; i -= CHUNK_LEN) {
            _chunks.push_back(std::stoll(new_string.substr(std::max(0ll, i - CHUNK_LEN), std::min(static_cast<long long>(CHUNK_LEN), i))));

        }
    }
}
