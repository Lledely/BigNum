#include <BigNum.h>

namespace bignum {

    std::string BigNum::to_string() const {
        std::string to_ret = "";
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
        while (_fraction_shift > to_ret.size()) {
            to_ret = "0" + to_ret;
        }
        if (_fraction_shift != 0) {
            to_ret.insert(to_ret.size() - _fraction_shift + 1, ".");
        }
        if (_is_neg) {
            to_ret = "-" + to_ret;
        }
        if (to_ret[0] == '.') {
            to_ret.insert(0, "0");
        }
        else if (to_ret[1] == '.' && to_ret[0] == '-') {
            to_ret.insert(1, "0");
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

    BigNum BigNum::operator-() const {
        BigNum tmp = *this;
        tmp._is_neg = !(tmp._is_neg);
        return tmp;
    }

    const std::string BigNum::_whole() const {
        std::string num = (*this).to_string();
        if (num[0] == '-') {
            num.erase(0, 1);
        }
        if (std::count(num.begin(), num.end(), '.') == 0) {
            return num;
        }
        int pos = num.find('.');
        return num.substr(0, pos);
    }

    const std::string BigNum::_frac() const {
        std::string num = (*this).to_string();
        if (std::count(num.begin(), num.end(), '.') == 0) {
            return std::string("0");
        }
        int pos = num.find('.');
        return num.substr(pos + 1, num.size() - pos);
    }

    const std::string BigNum::_str_sum(const std::string left, const std::string right) {
        std::string a = left, b = right;
        while (a.size() != b.size()) {
            if (a.size() > b.size()) {
                b = "0" + b;
            }
            else {
                a = "0" + a;
            }
        }

        int j = a.size() - 1;
        for(int i=b.size() - 1; i >= 0; --i, --j) {
            a[j]+=(b[i] - '0');
        }

        for(int i = a.size() - 1; i > 0; --i) {
            if(a[i] > '9')
            {
                int tmp_left = a[i] - '0';
                a[i-1] = ((a[i - 1] - '0') + tmp_left / 10) + '0';
                a[i] = (tmp_left % 10)+'0';
            }
        }

        if(a[0] > '9') {
            std::string tmp;
            tmp += a[0];
            a[0] = ((a[0] - '0') % 10) + '0';
            tmp[0] = ((tmp[0] - '0') / 10) + '0';
            a = tmp + a;
        }
        return a;
    }

    const std::string BigNum::_str_sub(const std::string left, const std::string right) {
        std::string a = left, b = right;
        std::string to_ret = "";
        // std::cout << a << " " << b << std::endl;

        bool mider = false;
        for (int i = a.size() - 1; i >= 0; --i) {
            int res = (a[i] - '0') - (b[i] - '0');
            if (mider) {
                --res;
                mider = false;
            }
            if (res < 0) {
                res += 10;
                mider = true;
            }
            to_ret += std::to_string(res);
        }
        if (mider) {
            to_ret.push_back('-');
        }
        std::reverse(to_ret.begin(), to_ret.end());

        return to_ret;
    }

    const BigNum BigNum::_abs() const {
        return this->_is_neg ? -(*this) : *this;
    }

    std::ostream& operator<<(std::ostream& os, const BigNum& num) {
        os << num.to_string();
        return os;
    }

    const BigNum BigNum::_round(const std::string num, int accuracy) {
        if (num.size() < accuracy) {
            return BigNum(num);
        }
        if (std::count(num.begin(), num.end(), '.') == 0) {
            return BigNum(num);
        }

        int dot_pos = num.find('.');
        if (num.size() - dot_pos < accuracy) {
            return BigNum(num);
        }

        std::string to_ret = num;
        if ((num[dot_pos + accuracy] - '0') >= 5) {
            std::string frac = num.substr(dot_pos + 1, accuracy - 1);
            frac = BigNum::_str_sum(frac, "1");
            // std::cout << frac << std::endl;
            if (frac.size() > accuracy - 1) {
                frac.erase(0, 1);
                std::string whole = num.substr(0, dot_pos);
                whole = BigNum::_str_sum(whole, "1");
                to_ret = whole + "." + frac;
            }
            else {
                to_ret = num.substr(0, dot_pos + 1) + frac;
            }
        }
        else {
            to_ret = to_ret.substr(0, dot_pos + accuracy);
        }
        return BigNum(to_ret);
    }
    
}

bignum::BigNum operator""_bn(const char* num, size_t sz) {
    bignum::BigNum res(num);
    return res;
}