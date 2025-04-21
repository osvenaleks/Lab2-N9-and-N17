#include <iostream>
#include <cstdint>

void PrintMatrixSpiral(int32_t** matrix, int32_t rows, int32_t cols) {
    int32_t top = {};
    int32_t down = { rows - 1 };
    int32_t left = {};
    int32_t right = { cols - 1 };

    std::cout << "Matrix Spiral Output:\n";

    while (top <= down && left <= right) {

        for (int32_t i = { left }; i <= right; ++i) {
            std::cout << matrix[top][i] << " ";
        }
        ++top;


        for (int32_t i = { top }; i <= down; ++i) {
            std::cout << matrix[i][right] << " ";
        }
        --right;


        if (top <= down) {
            for (int32_t i = { right }; i >= left; --i) {
                std::cout << matrix[down][i] << " ";
            }
            --down;
        }


        if (left <= right) {
            for (int32_t i = { down }; i >= top; --i) {
                std::cout << matrix[i][left] << " ";
            }
            ++left;
        }
    }

    std::cout << "\n";
}