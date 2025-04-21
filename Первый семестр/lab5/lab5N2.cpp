#include <iostream>
#include <cstdint>


size_t CountElements(size_t index, size_t size);
void InputArray(int64_t arr[], size_t size);
void InputArraySize(size_t& size);
bool IsSizeValid(size_t size);

int main() {
    size_t size{};
    InputArraySize(size);

    if (!IsSizeValid(size)) {
        std::cout << "Array size exceeds the limit of 100 elements.\n";
        return 0;
    }

   const int64_t arr[100]; 

    InputArray(arr, size);

    size_t count{ CountElements(0, size) };


    std::cout << "Number of elements in the array: " << count << "\n";

    return 0;
}

void InputArraySize(size_t& size) {
    std::cout << "Enter the size of the array: ";
    std::cin >> size;

}

void InputArray(int64_t arr[], size_t size) {
    std::cout << "Enter " << size << " elements of the array:\n";
    for (size_t i = {}; i < size; ++i) {
        std::cin >> arr[i];
    }
}

bool IsSizeValid(size_t size) {
    return size <= 100;
}

size_t CountElements(size_t index, size_t size) {
    if (index == size) {
        return 0;
    }
    return 1 + CountElements(index + 1, size);
}
