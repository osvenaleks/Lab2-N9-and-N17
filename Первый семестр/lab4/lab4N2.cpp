
#include <iostream>
#include <cstdint>

static void InputArray(size_t& const size, const size_t maxSize);

static bool IsSizeOfArrayIsCorrect(size_t const size, const size_t maxSize);

static void InputElementsOfTheArray(int32_t* const arr, const size_t size);

static double ArithmeticMeanOfArray(const int32_t* arr, size_t size);

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

    double arithmeticMean{ ArithmeticMeanOfArray(arr, size) };

    std::cout << "The arithmetic mean of the array is: " << arithmeticMean << "\n";

    return 0;
}

static void InputArray(size_t& const size, const size_t maxSize) {
    std::cout << "Enter size of array := ";
    std::cin >> size; 
}

static bool IsSizeOfArrayIsCorrect(size_t const size, const size_t maxSize) {
    return maxSize > size; 
}

static void InputElementsOfTheArray(int32_t* const arr, const size_t size) {
    for (size_t i{}; i < size; ++i) {
        std::cout << "Element " << i + 1 << ": "; 
        std::cin >> arr[i]; 
    }
}

static double ArithmeticMeanOfArray(const int32_t* arr, size_t size) {
    int64_t sum{};          
    int32_t divisorSum{};   

    for (size_t i{}; i < size; ++i) {
        sum += arr[i]; 
        if (arr[i] > 0) { 
            ++divisorSum; 
        }
    }

    return static_cast<double>(sum) / static_cast<double>(divisorSum);
}
