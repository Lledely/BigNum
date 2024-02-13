#pragma once

#include <vector>
#include <string>
#include <cmath>
#include <inttypes.h>

#define CHUNK 64
#define CHUNK_LEN 9
#define CHUNK_TYPE uint64_t

namespace bignum{

    class BigNum {

        public:

            BigNum(const std::string &num);

        private:

            std::vector<CHUNK_TYPE> _chunks;

    };

}