#include <BigNum.h>

namespace bignum {
  
    const BigNum operator+(const BigNum &left, const BigNum &right) {
       
        std::string to_ret = "";

        if (left._is_neg == right._is_neg) {
            std::string left_whole = left._whole(), left_frac = left._frac(),
                        right_whole = right._whole(), right_frac = right._frac();
            if (left_frac.size() > right_frac.size()) {
                while (left_frac.size() > right_frac.size()) {
                    right_frac += '0';
                }
            }
            else if (left_frac.size() < right_frac.size()) {
                while (left_frac.size() < right_frac.size()) {
                    left_frac += '0';
                }
            }
            std::string sum_whole = BigNum::_str_sum(left_whole, right_whole), 
                        sum_frac = BigNum::_str_sum(left_frac, right_frac);
            if (sum_frac.size() > left_frac.size()) {
                sum_whole = BigNum::_str_sum(sum_whole, "1");
                sum_frac.erase(0, 1);
            }
            to_ret = sum_whole + "." + sum_frac;
        } 
        else {
            std::string left_whole = left._whole(), right_whole = right._whole(), left_frac = left._frac(), right_frac = right._frac();
            while (left_whole.size() != right_whole.size()) {
                if (left_whole.size() <  right_whole.size()) {
                    left_whole = "0" + left_whole;
                }
                else {
                    right_whole = "0" + right_whole;
                }
            }
            while (left_frac.size() != right_frac.size()) {
                if (left_frac.size() <  right_frac.size()) {
                    left_frac += "0";
                }
                else {
                    right_frac += "0";
                }
            }
            std::string tmp_left = left_whole + left_frac, tmp_right = right_whole + right_frac;
            // std::cout << tmp_left << " " << tmp_right << std::endl;
            // std::cout << left._abs().to_string() << " " << right._abs().to_string() << std::endl;
            if (left._abs() >= right._abs()) {
                tmp_left = BigNum::_str_sub(tmp_left, tmp_right);
            }
            else {
                to_ret = "-";
                tmp_left = BigNum::_str_sub(tmp_right, tmp_left);
            }
            to_ret += tmp_left.substr(0, tmp_left.size() - left_frac.size()) + "." + tmp_left.substr(tmp_left.size() - left_frac.size(), left_frac.size());
        }
        return BigNum(to_ret);
    }

    const BigNum operator-(const BigNum &left, const BigNum &right) {
        return (left + (-right));
    }

    const BigNum operator*(const BigNum &left, const BigNum &right) {

        std::string tmp_left = left._whole() + left._frac(), tmp_right = right._whole() + right._frac();
        int n1 = tmp_left.size(), n2 = tmp_right.size();
        std::string result(n1 + n2, '0');
        for (int i = n1 - 1; i >= 0; i--) {
            int carry = 0;
            for (int j = n2 - 1; j >= 0; j--) {
                int product = (tmp_left[i] - '0') * (tmp_right[j] - '0') + carry + (result[i + j + 1] - '0');
                result[i + j + 1] = product % 10 + '0';
                carry = product / 10;
            }
            result[i] += carry;
        }

        if (left._fraction_shift == 0 && right._fraction_shift == 0) {
            result.insert(result.size() - 2, ".");
        }
        else if (left._fraction_shift == 0) {
            result.insert(result.size() - right._fraction_shift, ".");
        }
        else if (right._fraction_shift == 0) {
            result.insert(result.size() - left._fraction_shift, ".");
        }
        else {
            result.insert(result.size() - left._fraction_shift - right._fraction_shift + 2, ".");
        }

        if (left._is_neg != right._is_neg) {
            result = "-" + result;
        }

        return BigNum(result);

    }

    const BigNum operator/(const BigNum &left, const BigNum &right) {
        if (!right) {
            throw std::runtime_error("Can't divide by 0");
        }
        int accuracy = std::max(left._fraction_shift, right._fraction_shift);
        std::string check = "0.";
        for (int i = 0; i < accuracy; ++i) {
            check += "0";
        }
        check += "1";
        BigNum acc(check);
        
        BigNum special_num("0.5"), special_one("1"), special_ten("10"), left_abs = left._abs(), right_abs = right._abs(), l("0"), r = left._abs(), right_copy = right;
        while (right_copy < special_one) {
            right_copy = right_copy * special_ten;
            r = r * special_ten;
        }
        while ((r - l)._abs() > acc) {
        // std::cout << (r - l)._abs().to_string() << std::endl;
            BigNum mid = (l + r) * special_num;
            if (mid * right_abs <= left_abs) {
                l = mid;
            }
            else {
                r = mid;
            }
        }

        l = BigNum::_round(l.to_string(), std::count(check.begin(), check.end(), '0'));

        if (left._is_neg != right._is_neg) {
            return (-l);
        }
        return l;
    }

    BigNum& BigNum::operator+=(const BigNum &right) {
        (*this) = ((*this) + right);
        return (*this);
    }

    BigNum& BigNum::operator-=(const BigNum &right) {
        (*this) = ((*this) - right);
        return (*this);
    }

    BigNum& BigNum::operator*=(const BigNum &right) {
        (*this) = ((*this) * right);
        return (*this);
    }

    BigNum& BigNum::operator/=(const BigNum &right) {
        (*this) = ((*this) / right);
        return (*this);
    }

}
