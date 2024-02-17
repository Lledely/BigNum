#include <BigNum.h>

namespace bignum {

    std::string BigNum::to_string() const {
        std::string to_ret = "";
        if (_is_neg) {
            to_ret += '-';
        }
        for (long long i = 0; i <  _chunks.size(); ++i) {
            if (i != 0) {
                long long tmp = 10, tmp_cnt = 0;
                while (tmp < _chunks[i]) {
                    tmp *= 10;
                    ++tmp_cnt;
                }
                for (int _ = 0; _ < 10 - tmp_cnt; ++_) {
                    to_ret += '0';
                }
            }
            to_ret += std::to_string(_chunks[i]);
        }
        if (_fraction_shift != 0) {
            to_ret.insert(to_ret.size() - _fraction_shift + 1, ".");
        }
        return to_ret;
    }

    BigNum::operator bool() const {
        return true; 
    }
}
