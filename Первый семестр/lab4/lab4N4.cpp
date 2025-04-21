#include <iostream>
#include <cstdint>

// Функция объединяет два отсортированных массива в один отсортированный массив
// mergedArr - указатель на итоговый массив, в который будет помещён результат
void MergeSortedArrays(const int32_t* arr1, size_t size1, const int32_t* arr2, size_t size2, int32_t* mergedArr);

// Функция выводит массив на экран
void PrintArray(const int32_t* arr, std::size_t size);

int main() {
    // Два отсортированных массива
    const int32_t arr1[]{ 3, 15, 22, 34, 41, 52, 68, 75, 89, 97 };
    const int32_t arr2[]{ 51, 56, 63, 72, 84, 92, 101, 110, 119, 125, 133, 140, 145, 148, 150 };

    // Вычисление размеров массивов
    const size_t size1{ sizeof(arr1) / sizeof(arr1[0]) }; // Размер первого массива
    const size_t size2{ sizeof(arr2) / sizeof(arr2[0]) }; // Размер второго массива

    // Итоговый массив, в который будет помещён результат
    int32_t mergedArr[size1 + size2];

    // Объединение двух массивов в один
    MergeSortedArrays(arr1, size1, arr2, size2, mergedArr);

    // Вывод объединённого массива
    PrintArray(mergedArr, size1 + size2);

    return 0;
}

// Объединяет два отсортированных массива в один отсортированный массив
void MergeSortedArrays(const int32_t* arr1, size_t size1, const int32_t* arr2, size_t size2, int32_t* mergedArr) {
    size_t i{}; // Индекс для обхода первого массива
    size_t j{}; // Индекс для обхода второго массива
    size_t k{}; // Индекс для записи в итоговый массив

    // Сравнение элементов двух массивов и помещение меньшего элемента в итоговый массив
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            mergedArr[k++] = arr1[i++]; // Берем элемент из первого массива
        }
        else {
            mergedArr[k++] = arr2[j++]; // Берем элемент из второго массива
        }
    }

    // Если остались неиспользованные элементы в первом массиве, берем их в итоговый массив
    while (i < size1) {
        mergedArr[k++] = arr1[i++];
    }

    // Если остались неиспользованные элементы во втором массиве, ,берем их в итоговый массив
    while (j < size2) {
        mergedArr[k++] = arr2[j++];
    }
}

// Выводит массив на экран
void PrintArray(const int32_t* arr, size_t size) {
    std::cout << "Merged array:\n"; // Заголовок вывода
    for (size_t i{}; i < size; ++i) {
        std::cout << "[" << arr[i] << "] "; 
    }
}
