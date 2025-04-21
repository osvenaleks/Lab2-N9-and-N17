#include <iostream>
#include <cstdint>

// Функция для ввода размера массива от пользователя
static void InputArray(size_t& const size, const size_t maxSize);

// Проверяет, корректен ли введённый размер массива
static bool IsSizeOfArrayIsCorrect(size_t const size, const size_t maxSize);

// Функция для ввода элементов массива
static void InputElementsOfTheArray(int32_t* const arr, size_t size);

// Заменяет все отрицательные элементы массива на ноль
static void ReplaceNegativesWithZero(int32_t* const arr, const size_t size);

// Печатает содержимое массива на экран
static void PrintArray(const int32_t* const arr, const size_t size);

int main() {
    const size_t maxSize{ 100 }; 
    size_t size{};              
    int32_t arr[maxSize];       

    // Ввод размера массива
    InputArray(size, maxSize);

    // Проверка корректности введённого размера массива
    if (!IsSizeOfArrayIsCorrect(size, maxSize)) {
        std::cout << "Incorrect size (size must be lower than 100)";
        return 0; 
    }

    // Ввод элементов массива
    InputElementsOfTheArray(arr, size);

    // Замена отрицательных элементов массива на ноль
    ReplaceNegativesWithZero(arr, size);

    // Вывод массива на экран
    PrintArray(arr, size);

    return 0;
}

// Функция для ввода размера массива
static void InputArray(size_t& const size, const size_t maxSize) {
    std::cout << "Enter size of array := ";
    std::cin >> size; 
}

// Проверяет, что введённый размер массива меньше максимального
static bool IsSizeOfArrayIsCorrect(size_t const size, const size_t maxSize) {
    return maxSize > size; 

// Функция для ввода элементов массива
static void InputElementsOfTheArray(int32_t* const arr, const size_t size) {
    for (size_t i{}; i < size; ++i) {
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> arr[i]; 
    }
}

// Заменяет отрицательные элементы массива на ноль
static void ReplaceNegativesWithZero(int32_t* const arr, const size_t size) {
    for (size_t i{ 0 }; i < size; ++i) {
        if (arr[i] < 0) { 
            arr[i] = 0; 
        }
    }
}

// Печатает содержимое массива
static void PrintArray(const int32_t* const arr, const size_t size) {
    std::cout << "Array after replacing negative elements with zero:\n";
    for (size_t i{
