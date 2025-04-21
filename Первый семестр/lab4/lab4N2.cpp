//static тут не играет никакой роли,statiс перед функцией означает что функция относится только к этому файлу
#include <iostream>
#include <cstdint>

// Функция для ввода размера массива от пользователя
static void InputArray(size_t& const size, const size_t maxSize);

// Проверяет, корректен ли введённый размер массива
static bool IsSizeOfArrayIsCorrect(size_t const size, const size_t maxSize);

// Функция для ввода элементов массива
static void InputElementsOfTheArray(int32_t* const arr, const size_t size);

// Вычисляет среднее арифметическое массива
static double ArithmeticMeanOfArray(const int32_t* arr, size_t size);

int main() {
    const size_t maxSize{ 100 }; 
    size_t size{};              
    int32_t arr[maxSize];      

    // Ввод размера массива
    InputArray(size, maxSize);

    // Проверка корректности введённого размера массива
    if (!IsSizeOfArrayIsCorrect(size, maxSize)) {
        std::cout << "Incorrect size (size must be less than 100)";
        return 0; 
    }

    // Ввод элементов массива
    InputElementsOfTheArray(arr, size);

    // Вычисление среднего арифметического массива
    double arithmeticMean{ ArithmeticMeanOfArray(arr, size) };

    // Вывод результата
    std::cout << "The arithmetic mean of the array is: " << arithmeticMean << "\n";

    return 0;
}

// Функция для ввода размера массива
static void InputArray(size_t& const size, const size_t maxSize) {
    std::cout << "Enter size of array := ";
    std::cin >> size; // Ввод размера массива от пользователя
}

// Проверяет, корректен ли введённый размер массива
static bool IsSizeOfArrayIsCorrect(size_t const size, const size_t maxSize) {
    return maxSize > size; 
}

// Функция для ввода элементов массива
static void InputElementsOfTheArray(int32_t* const arr, const size_t size) {
    for (size_t i{}; i < size; ++i) {
        std::cout << "Element " << i + 1 << ": "; 
        std::cin >> arr[i]; 
    }
}

// Вычисляет среднее арифметическое элементов массива
static double ArithmeticMeanOfArray(const int32_t* arr, size_t size) {
    int64_t sum{};          
    int32_t divisorSum{};   // Количество положительных элементов

    for (size_t i{}; i < size; ++i) {
        sum += arr[i]; 
        if (arr[i] > 0) { 
            ++divisorSum; 
        }
    }

    // Вычисляем среднее арифметическое:
    // делим сумму элементов на количество положительных элементов.
    // Используем static_cast для преобразования типов, чтобы избежать целочисленного деления.
    return static_cast<double>(sum) / static_cast<double>(divisorSum);
}
