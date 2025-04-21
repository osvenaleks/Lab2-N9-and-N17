//на этой программе я изучал const и старался вставлять его везде где это имеет значение
#include <iostream>
#include <cstdint>

// Функция для ввода размера массива от пользователя
void InputArray(size_t& const size, const size_t maxSize);

// Проверяет, корректен ли введённый размер массива
bool IsSizeOfArrayIsCorrect(size_t const size, const size_t maxSize);

// Функция для ввода элементов массива
void InputElementsOfTheArray(int32_t* arr, size_t size);

// Вычисляет сумму элементов массива с чётными индексами
int64_t SumEvenIndices(const int32_t* arr, size_t size);

int main() {
    const size_t maxSize{ 100 };
    size_t size{};              
    int32_t arr[maxSize];       

    
    InputArray(size, maxSize);

   
    if (!IsSizeOfArrayIsCorrect(size, maxSize)) {
        std::cout << "Incorrect size (size must be less than 100)";
        return 0; 
    }

    
    InputElementsOfTheArray(arr, size);

    // Вычисление суммы элементов с чётными индексами и вывод результата
    std::cout << "The sum of elements with even indices is: " << SumEvenIndices(arr, size) << "\n";

    return 0;
}

// Ввод размера массива
static void InputArray(size_t& const size, const size_t maxSize) {
    std::cout << "Enter size of array := ";
    std::cin >> size; // Ввод размера массива
}

// Проверка на корректность размера массива
static bool IsSizeOfArrayIsCorrect(size_t const size, const size_t maxSize) {
    return maxSize > size; 
}

// Ввод элементов массива
static void InputElementsOfTheArray(int32_t* const arr, const size_t size) {
    for (size_t i{}; i < size; ++i) {
        std::cout << "Element " << i + 1 << ": "; // Запрашиваем элемент с индексом i
        std::cin >> arr[i]; // Сохраняем введённое значение в массив
    }
}

// Вычисление суммы элементов с чётными индексами
int64_t SumEvenIndices(const int32_t* arr, size_t size) {
    std::int64_t sum{}; 
    for (size_t i{}; i < size; ++++i) { // Увеличиваем i на 2 за каждую итерацию
        sum += arr[i]; // Добавляем элемент с чётным индексом к сумме
    }
    return sum; 
}
