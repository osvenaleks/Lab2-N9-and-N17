#include <iostream>

bool IsExistRemainder(double* arr, int32_t degree) {
    for (int32_t i = {}; i <= degree; ++i) {
        if (arr[i] != 0.0) {
            return true;
        }
    }
    return false;
}

void AutputArray(double* arr, int32_t degree) {
    bool first = true;

    for (int32_t i = {}; i <= degree; ++i) {
        if (arr[i] != 0) {
            if (!first) {
                std::cout << (arr[i] < 0 ? " - " : " + ");
            }
            else {
                if (arr[i] < 0) {
                    std::cout << "- ";
                }
                first = false;
            }

            if (std::abs(arr[i]) != 1 || (degree - i == 0)) {
                std::cout << std::abs(arr[i]);
            }

            if (degree - i > 0) {
                std::cout << "x";
                if (degree - i > 1) {
                    std::cout << "^" << degree - i;
                }
            }
        }
    }
    if (first) {
        std::cout << "0"; 
    }
    std::cout << "\n";
}

void Delenie(double* arr1, int32_t degree1, double* arr2, int32_t degree2) {
    int32_t degree3 = degree1 - degree2;
    if (degree3 < 0) return;

    double* arr3 = new double[degree3 + 1] {};

    for (int32_t i = {}; i <= degree3; ++i) {
        arr3[i] = arr1[i] / arr2[0];

        for (int32_t j = {}; j <= degree2; ++j) {
            arr1[i + j] -= arr3[i] * arr2[j];
        }
    }

    delete[] arr3;
    arr3 = nullptr;
}

void FindGCFPolinom(double* arr1, double* arr2, int32_t degree1, int32_t degree2) {
    while (IsExistRemainder(arr2, degree2)) {
        Delenie(arr1, degree1, arr2, degree2);

        while (degree1 >= 0 && arr1[degree1] == 0.0) {
            --degree1;
        }

        if (!IsExistRemainder(arr1, degree1)) {
            AutputArray(arr2, degree2);
            return;
        }

        std::swap(arr1, arr2);
        std::swap(degree1, degree2);
    }

    AutputArray(arr1, degree1);
}

int main() {
    int32_t arrSize1 = {};
    try {
        InputArrSize(arrSize1);
        if (arrSize1 <= 0) {
            throw std::invalid_argument("Size must be more then 0");
        }
    }
    catch (std::invalid_argument& e) {
        std::cerr << "error: " << e.what();
    }

    double* arr1 = new double[arrSize];
    FillArr(arr1,arrSize1);

    int32_t arrSize2 = {};
    try {
        InputArrSize(arrSize2);
        if (arrSize2 <= 0) {
            throw std::invalid_argument("Size must be more then 0");
        }
    }
    catch (std::invalid_argument& e) {
        std::cerr << "error: " << e.what();
    }

    double* arr2 = new double[arrSize2];
    FillArr(arr2, arrSize2);

    FindGCFPolinom(arr1, arr2.arrSize1 - 1, arrSize2 - 1);
    delete[] arr1;
    arr1 = nullptr;
    delete[] arr2;
    arr2 = nullptr;
}
