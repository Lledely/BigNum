#include <BigNum.h>

namespace bignum {
  
    const BigNum operator+(const BigNum &left, const BigNum &right) {
       
        std::vector<uint64_t> tmp = std::vector<uint64_t>(std::max(left._chunks.size(), right._chunks.size()) + 1);
        std::string to_ret = "";

        std::vector<uint64_t> left_tmp = std::vector<uint64_t>(left._chunks.size() + right._fraction_shift), right_tmp = std::vector<uint64_t>(right._chunks.size() + left._fraction_shift);

        for (int i = 0; i < left._chunks.size(); ++i) {
            left_tmp[i] = left._chunks[i];
        }
        for (int i = 0; i < right._chunks.size(); ++i) {
            right_tmp[i] = right._chunks[i];
        }

        for (int i = tmp.size() - left_tmp.size(); i < tmp.size(); ++i) {
            tmp[i] = left_tmp[i + left_tmp.size() - tmp.size()];
        }

        if (left._is_neg == right._is_neg) {
            for (int i = 1; i <= right_tmp.size(); ++i) {
                tmp[tmp.size() - i] += right_tmp[right_tmp.size() - i];
                if (tmp[tmp.size() - i] > 999999999ull) {
                    tmp[tmp.size() - i - 1] += 1;
                    tmp[tmp.size() - i] -= 1000000000;
                }
            }

            for (int i = 0; i < tmp.size(); ++i) {
                long long tmp_num = 10, tmp_deg = 1;
                while (tmp_num < tmp[i]) {
                    tmp_num *= 10;
                    ++tmp_deg;
                }
                for (int _ = 0; _ < 9 - tmp_deg; ++_) {
                    to_ret += '0';
                }
            }
            std::cout << to_ret << std::endl;
            to_ret.insert(to_ret.size() - left._fraction_shift - right._fraction_shift + 1, ".");
            if (left._is_neg) {
                to_ret.insert(0, "-");
            }
        } 
        else {

        }
        return BigNum(to_ret);
    }

}
