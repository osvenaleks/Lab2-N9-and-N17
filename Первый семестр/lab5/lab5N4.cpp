#include <iostream>
#include <cstdint> 


void InputNumber(int64_t& number);
int64_t FibonacciSum(int64_t number);
int64_t Fibonacci(int64_t number);
bool IsPositive(int64_t number);

int main() {
    int64_t number{}; 

    InputNumber(number);

    if (IsPositive(number) == false) {
        std::cout << "incorect number";
        return 0;
    }

    int64_t sum{ FibonacciSum(number) };

    std::cout << "Sum of the first " << number << " Fibonacci numbers is: " << sum << "\n";

    return 0;
}

void InputNumber(int64_t& number) {
    std::cout << "Enter the number of Fibonacci terms: ";
    std::cin >> number;
}

int64_t FibonacciSum(int64_t number) {
    int64_t sum{};
    for (int64_t i{ 1 }; i < number + 1; ++i) {
        sum += Fibonacci(i); 
    }
    return sum;
}

int64_t Fibonacci(int64_t number) {
    if (number == 1) return 0;
    if (number == 2) return 1;
    return Fibonacci(number - 1) + Fibonacci(number - 2);
}
