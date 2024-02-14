#include <BigNum.h>

const bignum::BigNum& bignum::BigNum::operator+=(const BigNum &right){

    _chunks.resize(std::max(_chunks.size(), right._chunks.size()));
    
    // if ()

    return *this;

}