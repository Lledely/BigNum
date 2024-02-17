#include <BigNum.h>

namespace bignum{
  
    BigNum::BigNum(const std::string &num) {
    
        size_t dot_count = std::count(num.begin(), num.end(), '.');

        if (dot_count > 1) {
            throw std::runtime_error("Can not convert non-number string to BigNum");
        }
        if (num[0] == '-') {
            _is_neg = true;
        }
        else {
            _is_neg = false;
        }
        size_t length = num.size();
        if (dot_count == 1) {
            int64_t dot_pos = num.find('.');
            _fraction_shift = length - dot_pos;
            --length;
            // std::cout << dot_pos << " " << length << std::endl;
            std::string new_string = num.substr(0, dot_pos); 
            new_string += num.substr(dot_pos + 1, length - dot_pos - 1);
        }
        else {
            _fraction_shift = 0;
            std::string new_string = num;
        }
        for (long long int i = length; i > 0; i -= CHUNK_LEN) {
            _chunks.push_back(std::stoll(num.substr(std::max(0ll, i - CHUNK_LEN), std::min(static_cast<long long>(CHUNK_LEN), i))));

        }
        // std::cout << "Done" << std::endl;
    }
}
