#include <iostream>
#include <cstdint> 


void InputNumber(int64_t& number);
int64_t FibonacciSum(int64_t number);
int64_t Fibonacci(int64_t number);
bool IsPositive(int64_t number);

int main() {
    int64_t number{}; 

    // Ввод числа number
    InputNumber(number);

    //проверка на неотрицательность
    if (IsPositive(number) == false) {
        std::cout << "incorect number";
        return 0;
    }

    // Вычисляем сумму первых  чисел Фибоначчи
    int64_t sum{ FibonacciSum(number) };

    // Выводим результат
    std::cout << "Sum of the first " << number << " Fibonacci numbers is: " << sum << "\n";

    return 0;
}

// Функция для ввода числа number
void InputNumber(int64_t& number) {
    std::cout << "Enter the number of Fibonacci terms: ";
    std::cin >> number;
}

// Функция для вычисления суммы первых чисел фибоначчи
int64_t FibonacciSum(int64_t number) {
    int64_t sum{};
    for (int64_t i{ 1 }; i < number + 1; ++i) {
        sum += Fibonacci(i); // Добавляем к сумме число Фибоначчи
    }
    return sum;
}

// Рекурсивная функция для вычисления n-ого числа Фибоначи
int64_t Fibonacci(int64_t number) {
    if (number == 1) return 0;
    if (number == 2) return 1;
    return Fibonacci(number - 1) + Fibonacci(number - 2);
}
