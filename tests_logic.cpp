#include <BigNum.h>

int main() {
    bignum::BigNum a("420.69");
    bignum::BigNum b(0);
    bignum::BigNum c = "-0."_bn;
    bignum::BigNum d(-1231231233ll);

    std::vector<bignum::BigNum> nums = {a, b, c, d};

    for (bignum::BigNum i: nums) {
        for (bignum::BigNum j: nums) {
            std::cout << i.to_string() << " <= " << j << " - " << ((i <= j) ? "true" : "false") << std::endl;
            std::cout << i.to_string() << " < " << j << " - " << ((i < j) ? "true" : "false") << std::endl;
            std::cout << i.to_string() << " >= " << j << " - " << ((i >= j) ? "true" : "false") << std::endl;
            std::cout << i.to_string() << " > " << j << " - " << ((i > j) ? "true" : "false") << std::endl;
            std::cout << i.to_string() << " == " << j << " - " << ((i == j) ? "true" : "false") << std::endl;
            std::cout << i.to_string() << " != " << j << " - " << ((i != j) ? "true" : "false") << std::endl;
        }
    }

    return 0;
}