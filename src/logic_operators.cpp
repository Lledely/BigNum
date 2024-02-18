#include <BigNum.h>

namespace bignum {
    bool operator<=(const BigNum &left, const BigNum &right) {

        if (left._is_neg == true and right._is_neg == false) {
            return true;
        }
        if (left._is_neg == false and right._is_neg == true) {
            return false;
        }

        if (left._chunks.size() > right._chunks.size()) {
            if (left._is_neg) {
                return true;
            }
            return false;
        }
        else if (left._chunks.size() < right._chunks.size()) {
            if (left._is_neg) {
                return false;
            }
            return true;
        }

        int tmp = left._is_neg ? -1 : 1;
        for (int i = 0; i < left._chunks.size(); ++i) {
            int tmp_chunk = 0;
            tmp_chunk += left._chunks[i];
            tmp_chunk -= right._chunks[i];
            if (tmp * tmp_chunk > 0) {
                return false;
            }
        }
        return true;
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
