#include <BigNum.h>
#include <iostream>

int main() {
    bignum::BigNum a = bignum::BigNum(std::string("69.420"));
    std::cout << a.to_string() << std::endl;
    return 0;
}
