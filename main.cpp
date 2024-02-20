#include <BigNum.h>
#include <iostream>

int main() {
    bignum::BigNum a = bignum::BigNum(std::string("-1.5"));
    bignum::BigNum b = bignum::BigNum("2.5");
    std::cout << "a = " << a.to_string() << std::endl;
    std::cout << "b = " << b.to_string() << std::endl;
    std::cout << a.to_string() << " + " << b.to_string() << " = " << (a + b).to_string() << std::endl;

    // bignum::BigNum x = bignum::BigNum("2.0000000");
    // std::cout << x.to_string() << std::endl;

    return 0;
}
