
#include <iostream>
#include <cstdint> 

void InputRange(int64_t& a, int64_t& b);
bool IsPositive(int64_t a, int64_t b);
bool IsPerfectNumber(int64_t number);
void FindPerfectNumbersInRange(int64_t a, int64_t b);

int main() {
    int64_t a{};
    int64_t b{};
    InputRange(a, b);
    if (IsPositive(a, b) == false) {
        std::cout << "Incorrect a and b\n";
        return 0;
    }
    else {
        FindPerfectNumbersInRange(a, b);
    }


    return 0;
}

void InputRange(int64_t& a, int64_t& b) {
    std::cout << "Enter the range [a, b]:\n";
    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;

    if (a > b) {     
        std::swap(a, b);
    }
}

bool IsPositive(int64_t a, int64_t b) {
    return a >= 0 && b >= 0;
}

bool IsPerfectNumber(int64_t number) {
    if (number < 2) { 
        return false;
    }
    
    for (int64_t i{ 2 }; i * i <= number; ++i) {
        if (number % i == 0) {
            sumOfDivisors += i;
            if (i != number / i) {
                sumOfDivisors += number / i;
            }
        }
    }
    
    return sumOfDivisors == number;
}

void FindPerfectNumbersInRange(int64_t a, int64_t b) {
    bool found{ false };
    std::cout << "Perfect numbers in the range [" << a << ", " << b << "]:\n";
    for (a; a <= b; ++a) { 
        if (IsPerfectNumber(a)) {
            std::cout << a << " ";
            found = true;
        }
    }
    
    if (!found) {
        std::cout << "No perfect numbers found.\n";
    }
}

