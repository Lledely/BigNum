#include <BigNum.h>
#include <chrono>
#include <ctime>

bignum::BigNum calculate_pi(int accuracy=100) {
    std::string special_addition = "0.";
    for (int i = 0; i < accuracy / 8; ++i) {
        special_addition += "0";
    }
    special_addition += "1";
    bignum::BigNum sp_add(special_addition);
    bignum::BigNum pow16 = "1"_bn, num4 = "4"_bn + special_addition, num2 = "2"_bn + special_addition, 
    num16 = "16"_bn + special_addition, num1 = "1"_bn + special_addition, result = "0"_bn;
    for (int i = 0; i < accuracy; i++) {
        bignum::BigNum frac1 = num4 / bignum::BigNum(8 * i + 1), frac2 = num2 / bignum::BigNum(8 * i + 4), 
        frac3 = num1 / bignum::BigNum(8 * i + 5), frac4 = num1 / bignum::BigNum(8 * i + 6);
        result += pow16 * ( frac1 - frac2 - frac3 - frac4);
        pow16 /= num16;
    }
    return  result;
}

int main() {

    int accuracy;
    std::cin >> accuracy;

    const auto start{std::chrono::steady_clock::now()};
    std::string ans = calculate_pi(std::max(3, accuracy)).to_string().substr(0,accuracy + 2);
    const auto end{std::chrono::steady_clock::now()};

    const std::chrono::duration<double> elapsed_seconds{end - start};
    std::cout << "Pi: " << ans << std::endl;
    std::cout << "Time: " << elapsed_seconds.count() << "seconds" << std::endl;
    
    return 0;
}