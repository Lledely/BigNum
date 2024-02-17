#include <BigNum.h>

namespace bignum {

    std::string BigNum::to_string() const {
        std::string to_ret = "";
        for (auto i: _chunks) {
            to_ret += i;
        }
        return to_ret;
    }

    BigNum::operator bool() const {
  
    }
}
