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
            // std::string left_whole, right_whole, left_frac, right_frac;

            // if (left._abs() >= right._abs()) {
            //     left_whole = left._whole(), left_frac = left._frac();
            //     right_whole = right._whole(), right_frac = right._frac();
            // }
            // else {
            //     left_whole = right._whole(), left_frac = right._frac();
            //     right_whole = left._whole(), right_frac = left._frac();
            // }
            // while (left_frac.size() != right_frac.size()) {
            //     if (left_frac.size() < right_frac.size()) {
            //         left_frac += "0";
            //     }
            //     else {
            //         right_frac += "0";
            //     }
            // }
            // std::string sub_whole = BigNum::_str_sub(left_whole, right_whole),
            //             sub_frac = BigNum::_str_sub(left_frac, right_frac);
            // if (sub_frac[0] == '-') {
            //     sub_frac.erase(0, 1);
            //     std::string tmp = "1";
            //     for (int i = 0; i < sub_frac.size(); ++i) {
            //         tmp += "0";
            //     }
            //     sub_frac = BigNum::_str_sub(tmp, sub_frac);
            //     if (left._abs() < right._abs()) {
            //         sub_whole.erase(0, 1);
            //         sub_whole = BigNum::_str_sum(sub_whole, "1");
            //         sub_whole.insert('-', 0);
            //     }
            //     else {
            //         sub_whole = BigNum::_str_sub(sub_whole, "1");
            //     }
            // }
            // to_ret = sub_whole + "." + sub_frac;

            std::string left_whole = left._whole(), right_whole = right._whole(), left_frac = left._frac(), right_frac = right._frac();
            while (left_whole.size() != right_whole.size()) {
                if (left_whole.size() <  right_whole.size()) {
                    left_whole = "0" + left_whole;
                }
                else {
                    right_whole = "0" + left_whole;
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
            // std::cout << left._abs().to_string() << std::endl;
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
        std::string to_ret(tmp_left.size() + tmp_right.size(), '0');
        for (size_t i = 0; i < tmp_left.size(); ++i) {
        	for (int j = 0, carry = 0; j < (int) tmp_right.size() || carry; ++j) {
        		unsigned long long cur = (to_ret[i + j] - '0') + (to_ret[i] - '0') * 1ull * (j < (int)tmp_right.size() ? tmp_right[j] : 0) + carry;
        		to_ret[i + j] = '0' + (cur % 10);
        		carry = int (cur / 10);
        	}
        }
        if (left._is_neg != right._is_neg) {
            to_ret = "-" + to_ret;
        }
        if (left._fraction_shift + right._fraction_shift != 0) {
            to_ret.insert(to_ret.size() - left._fraction_shift - right._fraction_shift + 1, ".");
        }
        return BigNum(to_ret);
    }

}
