#include <BigNum.h>
#include <iostream>

int main() {
    bignum::BigNum a = bignum::BigNum(std::string("12300000000045667"));
    bignum::BigNum b = bignum::BigNum(std::string("123"));
    std::cout << "a = " << a.to_string() << "\n";
    std::cout << "b = " << b.to_string() << "\n";
    std::cout << (a <= b) << std::endl;
    std::cout << (a == b) << std::endl;
    std::cout << (a >= b) << std::endl;

    return 0;
}
