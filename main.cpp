#include <BigNum.h>
#include <iostream>

int main() {
    bignum::BigNum a = bignum::BigNum(std::string("-69.1230"));
    std::cout << a.to_string() << std::endl;
    return 0;
}
