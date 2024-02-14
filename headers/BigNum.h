#pragma once

#include <vector>
#include <string>
#include <cmath>
#include <inttypes.h>

#define CHUNK 64
#define CHUNK_LEN 9
#define CHUNK_TYPE uint64_t

namespace bignum{

    // std::string operator ""_bn();

    class BigNum {

        public:

            BigNum(const std::string &num);
            BigNum(const int);
            BigNum(const long);
            BigNum(const long long);
            BigNum(const float);
            BigNum(const double);

            friend const BigNum operator+(const BigNum &a, const BigNum &b);
            friend const BigNum operator-(const BigNum &a, const BigNum &b);
            friend const BigNum operator*(const BigNum &a, const BigNum &b);
            friend const BigNum operator/(const BigNum &a, const BigNum &b);
            const BigNum operator-();

        private:

            std::vector<CHUNK_TYPE> _chunks;
            bool _is_neg;

    };

}