#ifndef N9_H
#define N9_H

#include <iostream>
#include <stdexcept>
#include <stdint>
#include <cstdlib>
#include <cstime>

void FillArrayWithRandomNumbers(int64_t* arr, int32_t arrSize);
void InputP(double& P);
void InputElementsInArray(double* arr, int32_t MaxSize);
void InputArrSize(int32_t MaxSize, int32_t n);
int32_t LastNegative(int32_t arrSize, double arr[]);
int32_t SumIntNumAfterLastNegative(int32_t arrSize, double arr[]);

#endif