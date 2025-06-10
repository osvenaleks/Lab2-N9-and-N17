#include<iostream>

void ShakerSort(int64_t* arr, int32_t arrSize) {
    int32_t left = {};
    int32_t right = { arrSize - 1 };
    bool swapped = { true };

    while (swapped == true) {
        swapped = false;

        for (int32_t i = { left }; i < right; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        --right;

        for (int32_t i = { right }; i > left; --i) {
            if (arr[i - 1] > arr[i]) {
                std::swap(arr[i - 1], arr[i]);
                swapped = true;
            }
        }
        ++left;
    }
}
