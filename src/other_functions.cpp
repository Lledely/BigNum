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
        if(a.size() < b.size()) {
            swap(a, b);
        }

        int j = a.size() - 1;
        for(int i=b.size() - 1; i>=0; --i, --j) {
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
        int n = a.length(), m = b.length();
        int diff = n - m;

        if (diff < 0) {
            swap(a, b);
            diff = -diff;
        }

        while (diff--) {
            b = '0' + b;
        }

        std::string to_ret;
        int borrow = 0;
        for (int i = n - 1; i >= 0; i--) {
            int d1 = a[i] - '0';
            int d2 = b[i] - '0';
            int sub = d1 - d2 - borrow;
            if (sub < 0) {
                sub += 10;
                borrow = 1;
            } 
            else {
                borrow = 0;
            }
            to_ret = std::to_string(sub) + to_ret;
        }

    while (to_ret[0] == '0' && to_ret.length() > 1) {
        to_ret.erase(0, 1);
    }
    if (a < b) {
        to_ret = '-' + to_ret;
    }
    return to_ret;
}
    
}
