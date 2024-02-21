#include <BigNum.h>

namespace bignum {
    bool operator<=(const BigNum &left, const BigNum &right) {

        if (left._is_neg == true and right._is_neg == false) {
            return true;
        }
        if (left._is_neg == false and right._is_neg == true) {
            return false;
        }

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
        return tmp_left <= tmp_right;

        // if (left._chunks.size() > right._chunks.size()) {
        //     if (left._is_neg) {
        //         return true;
        //     }
        //     return false;
        // }
        // else if (left._chunks.size() < right._chunks.size()) {
        //     if (left._is_neg) {
        //         return false;
        //     }
        //     return true;
        // }

        // int tmp = left._is_neg ? -1 : 1;
        // for (int i = 0; i < left._chunks.size(); ++i) {
        //     int tmp_chunk = 0;
        //     tmp_chunk += left._chunks[i];
        //     tmp_chunk -= right._chunks[i];
        //     if (tmp * tmp_chunk < 0) {
        //         return false;
        //     }
        // }
        // return true;
    }
    
    bool operator==(const BigNum &left, const BigNum &right) {
        if (left._is_neg != right._is_neg) {
            return false;
        }
        if (left._chunks.size() != right._chunks.size()) {
            return false;
        }
        for (int i = 0; i < left._chunks.size(); ++i) {
            if (left._chunks[i] != right._chunks[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator>=(const BigNum &left, const BigNum &right) {
        return !(left <= right) or (left == right);
    }

    bool operator!=(const BigNum &left, const BigNum &right) {
        return !(left == right);
    }
    
    bool operator<(const BigNum &left, const BigNum &right) {
        return !(left >= right);
    }
    
    bool operator>(const BigNum &left, const BigNum &right) {
        return !(left <= right);
    }

}
