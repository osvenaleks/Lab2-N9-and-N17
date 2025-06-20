#include<iostream>

void StalinSort(double* arr, int32_t& arrSize) {
    if (arrSize <= 1) return;

    int32_t newSize = {1};
    for (int32_t i = { 1 }; i < arrSize; ++i) {
        if (arr[i] >= arr[newSize - 1]) {
            arr[newSize] = arr[i];
            ++newSize;
        }
    }

    arrSize = newSize;
}



