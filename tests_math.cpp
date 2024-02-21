#include <BigNum.h>

int main() {

    bignum::BigNum a("420.69");
    bignum::BigNum b(-5);
    bignum::BigNum c = "0"_bn;
    bignum::BigNum d(1ll);

    std::vector<bignum::BigNum> nums = {a, b, c, d};

    std::vector<std::vector<std::string>> sum_ans = {
        {"841.38", "415.69", "420.69", "421.69"},
        {"415.69", "-10", "-5", "-4"},
        {"420.69", "-5", "0", "1"},
        {"421.69", "-4", "1", "2"}
    };
    std::vector<std::vector<std::string>> sub_ans = {
        {"0", "425.69", "420.69", "419.69"},
        {"-425.69", "0", "-5", "-6"},
        {"-420.69", "5", "0", "-1"},
        {"-419.69", "6", "1", "0"}
    };
    std::vector<std::vector<std::string>> mult_ans = {
        {"176980.0761", "-2103.45", "0", "420.69"},
        {"-2103.45", "25", "0", "-5"},
        {"0", "0", "0", "0"},
        {"420.69", "-5", "0", "1"}
    };
    std::vector<std::vector<std::string>> div_ans = {
        {"1", "-84.138", "we can't divide by zero", "420.69"},
        {"-0.0119", "1", "we can't divide by zero", "-5"},
        {"0", "0", "we can't divide by zero", "0"},
        {"0.0023", "-0.1", "we can't divide by zero", "1"}
    };

    std::cout << "Sums" << std::endl;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < nums.size(); ++j) {
            std::cout << nums[i].to_string() << " + " << nums[j] << " = " << (nums[i] + nums[j]) << std::endl;
            std::cout << "Correct answer: " << sum_ans[i][j] << std::endl;
        }
    }

    std::cout << "Subs" << std::endl;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < nums.size(); ++j) {
            std::cout << nums[i].to_string() << " - " << nums[j] << " = " << (nums[i] - nums[j]) << std::endl;
            std::cout << "Correct answer: " << sub_ans[i][j] << std::endl;
        }
    }

    std::cout << "Mults" << std::endl;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < nums.size(); ++j) {
            std::cout << nums[i].to_string() << " * " << nums[j] << " = " << (nums[i] * nums[j]) << std::endl;
            std::cout << "Correct answer: " << mult_ans[i][j] << std::endl;
        }
    }

    std::cout << "Divs" << std::endl;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < nums.size(); ++j) {
            if (nums[j] == c) {
                std::cout << "we can't divide by zero" << std::endl;
                continue;
            }
            std::cout << nums[i].to_string() << " / " << nums[j] << " = " << (nums[i] / nums[j]) << std::endl;
            std::cout << "Correct answer: " << div_ans[i][j] << std::endl;
        }
    }

    return 0;
}