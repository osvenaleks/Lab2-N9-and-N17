#include <iostream>
#include <cstdint>

static void InputArray(size_t& const size, const size_t maxSize);

static bool IsSizeOfArrayIsCorrect(size_t const size, const size_t maxSize);

static void InputElementsOfTheArray(int32_t* const arr, size_t size);

static void ReplaceNegativesWithZero(int32_t* const arr, const size_t size);

static void PrintArray(const int32_t* const arr, const size_t size);

int main() {
    const size_t maxSize{ 100 }; 
    size_t size{};              
    int32_t arr[maxSize];       

    InputArray(size, maxSize);

    if (!IsSizeOfArrayIsCorrect(size, maxSize)) {
        std::cout << "Incorrect size (size must be lower than 100)";
        return 0; 
    }

    InputElementsOfTheArray(arr, size);

    ReplaceNegativesWithZero(arr, size);

    PrintArray(arr, size);

    return 0;
}

static void InputArray(size_t& const size, const size_t maxSize) {
    std::cout << "Enter size of array := ";
    std::cin >> size; 
}

static bool IsSizeOfArrayIsCorrect(size_t const size, const size_t maxSize) {
    return maxSize > size; 

static void InputElementsOfTheArray(int32_t* const arr, const size_t size) {
    for (size_t i{}; i < size; ++i) {
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> arr[i]; 
    }
}

static void ReplaceNegativesWithZero(int32_t* const arr, const size_t size) {
    for (size_t i{ 0 }; i < size; ++i) {
        if (arr[i] < 0) { 
            arr[i] = 0; 
        }
    }
}

static void PrintArray(const int32_t* const arr, const size_t size) {
    std::cout << "Array after replacing negative elements with zero:\n";
    for (size_t i{
