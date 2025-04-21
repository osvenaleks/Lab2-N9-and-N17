#include <iostream>
#include<cstdint>

void InputNumber(int64_t& number);
int64_t CountOfDigits(int64_t number);

int main() {
    int64_t number;

    InputNumber(number);

    if (number < 0) {
        number = -number;
    }

    std::cout << "Count of digits: " << CountOfDigits(number) << "\n";

    return 0;
}

void InputNumber(int64_t& number) {
    std::cout << "Enter a number: ";
    std::cin >> number;
}

int64_t CountOfDigits(int64_t number) {
    if (number == 0) {
        return 0; 
    }
    return 1 + CountOfDigits(number / 10);
}
