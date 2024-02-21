#pragma once

#include <vector>
#include <string>
#include <cmath>
#include <inttypes.h>
#include <algorithm>
#include <stdexcept>
#include <iostream>

#define CHUNK 64
#define CHUNK_LEN 9
#define CHUNK_TYPE uint64_t

namespace bignum{

    class BigNum {

        public:

            BigNum(const std::string &num);
            BigNum(const int);
            BigNum(const long);
            BigNum(const long long);
            BigNum(const float);
            BigNum(const double);
            BigNum(const char*);

            friend const BigNum operator+(const BigNum &left, const BigNum &right);
            friend const BigNum operator-(const BigNum &left, const BigNum &right);
            friend const BigNum operator*(const BigNum &left, const BigNum &right);
            friend const BigNum operator/(const BigNum &left, const BigNum &right);

            const BigNum& operator+=(const BigNum &right);
            const BigNum& operator-=(const BigNum &right);
            const BigNum& operator*=(const BigNum &right);
            const BigNum& operator/=(const BigNum &right);

            BigNum operator-() const;

            friend bool operator<=(const BigNum &left, const BigNum &right);
            friend bool operator>=(const BigNum &left, const BigNum &right);
            friend bool operator==(const BigNum &left, const BigNum &right);
            friend bool operator!=(const BigNum &left, const BigNum &right);
            friend bool operator<(const BigNum &left, const BigNum &right);
            friend bool operator>(const BigNum &left, const BigNum &right);

            friend const BigNum operator""_bn(const char*);
            std::string to_string() const;
            explicit operator bool() const;

        private:

            std::vector<CHUNK_TYPE> _chunks;
            int64_t _fraction_shift;
            bool _is_neg;

            const std::string _whole() const;
            const std::string _frac() const;
            const BigNum _abs() const;

            static const std::string _str_sum(const std::string, const std::string);
            static const std::string _str_sub(const std::string, const std::string);

    };
    const BigNum operator""_bn(long double);
}
