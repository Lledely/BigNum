#include <BigNum.h>
#include <iostream>

int main() {
    bignum::BigNum a = bignum::BigNum(std::string("1.52"));
    bignum::BigNum b = bignum::BigNum("16");
    // bignum::BigNum d = bignum::BigNum("0.1");
    std::cout << "a = " << a.to_string() << std::endl;
    std::cout << "b = " << b.to_string() << std::endl;

    // a += b;
    // std::cout << a << std::endl;
    bignum::BigNum c = a / b;
    // std::cout << ((a - b) <= d);
    std::cout << a.to_string() << " / " << b.to_string() << " = " << c.to_string() << std::endl;
    // std::cout << (a - b).to_string() << " " << d.to_string() << " " << ((a - b) <= d) << std::endl;

    // bignum::BigNum x = bignum::BigNum("2.0000000");
    // std::cout << x.to_string() << std::endl;

    return 0;
}
