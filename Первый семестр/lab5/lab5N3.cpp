#include <iostream>
#include<cstdint>

void InputNumber(int64_t& number);
int64_t CountOfDigits(int64_t number);

int main() {
    int64_t number;

    // Ввод числа
    InputNumber(number);

    // Обработка отрицательных чисел
    if (number < 0) {
        number = -number;
    }

    // Вычисление количества цифр в числе
    std::cout << "Count of digits: " << CountOfDigits(number) << "\n";

    return 0;
}

// Функция для ввода числа
void InputNumber(int64_t& number) {
    std::cout << "Enter a number: ";
    std::cin >> number;
}

// Рекурсивная функция для нахождения количества цифр в числе
int64_t CountOfDigits(int64_t number) {
    if (number == 0) {
        return 0; 
    }
    return 1 + CountOfDigits(number / 10);
}
