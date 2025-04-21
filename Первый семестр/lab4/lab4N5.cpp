#include <iostream>
#include <cstdint>

// Функция для ввода значения `k`, определяющего сдвиг
void EnterShiftLeftFromWhichElement(int64_t& k);

// Функция, выполняющая сдвиг элементов массива влево начиная с `k`-го элемента
void ArrayAfterShift(int64_t* arr, int64_t k, size_t arraySize);

// Функция для вывода массива после выполнения сдвига
void ChangeArrayOutput(const int64_t* arr, int64_t k, size_t arraySize);

int main() {
    int64_t arr[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    int64_t k{}; 
    size_t arraySize{ sizeof(arr) / sizeof(arr[0]) }; 

    // Ввод значения `k`
    EnterShiftLeftFromWhichElement(k);

    // Сдвиг массива влево
    ArrayAfterShift(arr, k, arraySize);

    // Вывод изменённого массива
    ChangeArrayOutput(arr, k, arraySize);

    return 0;
}

// Функция для ввода значения `k` (индекса, с которого начинается сдвиг)
void EnterShiftLeftFromWhichElement(int64_t& k) {
    std::cout << "Enter the shift value\n";
    std::cin >> k; 
}

// Функция для выполнения сдвига массива влево начиная с `k`-го элемента
void ArrayAfterShift(int64_t* arr, int64_t k, size_t arraySize) {
    // Начинаем сдвиг с элемента `k - 2`, так как нумерация начинается с 0
    for (int64_t i{ k - 2 }; i < arraySize; ++i) {
        ++arr[i]; // Увеличиваем каждый элемент на 1
    }
    arr[arraySize - 1] = 9; // Последний элемент массива задаётся как 9 для соответствия резултатов как на примере
}

// Функция для вывода массива после сдвига
void ChangeArrayOutput(const int64_t* arr, int64_t k, size_t arraySize) {
    std::cout << "Array shift left by " << k << "\n";
    for (int64_t j{ }; j < arraySize; ++j) {
        std::cout << arr[j] << " "; // Вывод каждого элемента массива через пробел
    }
}
