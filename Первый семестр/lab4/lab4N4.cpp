#include <iostream>
#include <cstdint>

void MergeSortedArrays(const int32_t* arr1, size_t size1, const int32_t* arr2, size_t size2, int32_t* mergedArr);

void PrintArray(const int32_t* arr, std::size_t size);

int main() {
    const int32_t arr1[]{ 3, 15, 22, 34, 41, 52, 68, 75, 89, 97 };
    const int32_t arr2[]{ 51, 56, 63, 72, 84, 92, 101, 110, 119, 125, 133, 140, 145, 148, 150 };

    const size_t size1{ sizeof(arr1) / sizeof(arr1[0]) }; 
    const size_t size2{ sizeof(arr2) / sizeof(arr2[0]) }; 

    int32_t mergedArr[size1 + size2];

    MergeSortedArrays(arr1, size1, arr2, size2, mergedArr);

    PrintArray(mergedArr, size1 + size2);

    return 0;
}

void MergeSortedArrays(const int32_t* arr1, size_t size1, const int32_t* arr2, size_t size2, int32_t* mergedArr) {
    size_t i{}; 
    size_t j{}; 
    size_t k{}; 

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            mergedArr[k++] = arr1[i++]; 
        }
        else {
            mergedArr[k++] = arr2[j++]; 
        }
    }

    while (i < size1) {
        mergedArr[k++] = arr1[i++];
    }

    while (j < size2) {
        mergedArr[k++] = arr2[j++];
    }
}

void PrintArray(const int32_t* arr, size_t size) {
    std::cout << "Merged array:\n"; 
    for (size_t i{}; i < size; ++i) {
        std::cout << "[" << arr[i] << "] "; 
    }
}
