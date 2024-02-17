#include <BigNum.h>

namespace bignum {

    std::string BigNum::to_string() const {
        std::string to_ret = "";
        if (_is_neg) {
            to_ret += '-';
        }
        for (auto i: _chunks) {
            to_ret += std::to_string(i);
        }
        return to_ret;
    }

    BigNum::operator bool() const {
        return true; 
    }
}
