#include <BigNum.h>

namespace bignum {
  
    const BigNum operator+(const BigNum &left, const BigNum &right) {
       
        // std::vector<uint64_t> tmp = std::vector<uint64_t>(std::max(left._chunks.size(), right._chunks.size()) + 1);
        std::string to_ret = "";

        // std::vector<uint64_t> left_tmp = std::vector<uint64_t>(left._chunks.size() + (right._fraction_shift + 8) / 9), right_tmp = std::vector<uint64_t>(right._chunks.size() + (left._fraction_shift + 8) / 9);

        // for (int i = 0; i < left._chunks.size(); ++i) {
        //     left_tmp[i] = left._chunks[i];
        // }
        // for (auto i: left_tmp) std::cout << i << std::endl;
        // std::cout << left_tmp.size() << std::endl;
        // for (int i = 0; i < right._chunks.size(); ++i) {
        //     right_tmp[i] = right._chunks[i];
        // }

        // for (int i = 0; i < left_tmp.size(); ++i) {
        //     tmp[i + tmp.size() - left_tmp.size()] = left_tmp[i];
        // }

        // // for (auto i: tmp) {
        // //     std::cout << i << std::endl;
        // // }

        if (left._is_neg == right._is_neg) {
        //     for (int i = 1; i <= right_tmp.size(); ++i) {
        //         tmp[tmp.size() - i] += right_tmp[right_tmp.size() - i];
        //         if (tmp[tmp.size() - i] > 999999999ull) {
        //             tmp[tmp.size() - i - 1] += 1;
        //             tmp[tmp.size() - i] -= 1000000000;
        //         }
        //     }

        //     for (int i = 0; i < tmp.size(); ++i) {
        //         long long tmp_num = 10, tmp_deg = 1;
        //         while (tmp_num < tmp[i]) {
        //             tmp_num *= 10;
        //             ++tmp_deg;
        //         }
        //         for (int _ = 0; _ < 9 - tmp_deg; ++_) {
        //             to_ret += '0';
        //         }
        //         to_ret += std::to_string(tmp[i]);
        //     }
        //     if (left._fraction_shift + right._fraction_shift != 0) {
        //         to_ret.insert(to_ret.size() - left._fraction_shift - right._fraction_shift + 1, ".");
        //     }
        //     if (left._is_neg) {
        //         to_ret.insert(0, "-");
        //     }

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
            std::string sub_whole = BigNum::_str_sub(left_whole, right_whole), 
                        sub_frac = BigNum::_str_sub(left_frac, right_frac);
            if (left._is_neg) {
                std::string sub_whole = BigNum::_str_sub(right_whole, left_whole), 
                            sub_frac = BigNum::_str_sub(right_whole, left_whole);
            }
            else {
                std::string sub_whole = BigNum::_str_sub(left_whole, right_whole), 
                            sub_frac = BigNum::_str_sub(left_frac, right_frac);
            }
            if (sub_frac[0] == '-') {
                sub_frac.erase(0, 1);
                sub_whole = BigNum::_str_sub(sub_whole, "1");
            }
            if (sub_whole[0] =='-') {
                sub_whole.erase(0, 1);
            }
            to_ret = sub_whole + "." + sub_frac;
        }
        return BigNum(to_ret);
    }

}
