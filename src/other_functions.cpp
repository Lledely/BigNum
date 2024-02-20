#include <BigNum.h>

namespace bignum {

    std::string BigNum::to_string() const {
        std::string to_ret = "";
        if (_is_neg) {
            to_ret += '-';
        }
        for (long long i = 0; i <  _chunks.size(); ++i) {
            if (i != 0) {
                long long tmp = 10, tmp_cnt = 1;
                while (tmp < _chunks[i]) {
                    tmp *= 10;
                    ++tmp_cnt;
                }
                for (int _ = 0; _ < 9 - tmp_cnt; ++_) {
                    to_ret += '0';
                }
            }
            to_ret += std::to_string(_chunks[i]);
        }
        if (_fraction_shift != 0) {
            to_ret.insert(to_ret.size() - _fraction_shift + 1, ".");
        }
        if (to_ret[0] == '.') {
            to_ret.insert(0, "0");
        }
        if (to_ret[to_ret.size() - 1] == '.') {
            to_ret.pop_back();
        }
        return to_ret;
    }

    BigNum::operator bool() const {
        for (auto i: _chunks) {
            if (i != 0) {
                return true;
            }
        } 
        return false;
    }

    const BigNum BigNum::operator -() {
        BigNum tmp = *this;
        tmp._is_neg = !(tmp._is_neg);
        return tmp;
    }

    const BigNum operator""_bn(const char* num) {
        return BigNum(num);
    }

    const std::string _whole() {
        std::string num = this;
    }

    const std::string _frac() {

    }
}
