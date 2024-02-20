#include <BigNum.h>
#include <iostream>

int main() {
    bignum::BigNum a = bignum::BigNum(std::string("2"));
    bignum::BigNum b = bignum::BigNum("2");
    std::cout << "a = " << a.to_string() << std::endl;
    std::cout << "b = " << b.to_string() << std::endl;
    std::cout << a.to_string() << " + " << b.to_string() << " = " << (a + b).to_string() << std::endl;
    // std::cout << (a <= b) << std::endl;
    // std::cout << (a == b) << std::endl;
    // std::cout << (a >= b) << std::endl;

    return 0;
}
