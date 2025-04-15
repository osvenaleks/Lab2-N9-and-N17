#ifndef N9_H
#define N9_H

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <cstdint>

// Общие функции
void InputArrSize(int32_t maxSize, int32_t& arrSize);

// Выбор метода заполнения
void ChooseMethod(int64_t* arr, int32_t arrSize);
void ChooseMethod(double* arr, int32_t arrSize);

// Работа с массивом double
void FillArrayWithRandomNumbersD(double* arr, int32_t arrSize);
void InputElementsInArray(double* arr, int32_t arrSize);
void InputP(double& P);
int32_t LastNegative(double* arr, int32_t arrSize);
int32_t CountOfElementsLowerThanP(double* arr, int32_t arrSize, double P);
int32_t SumIntNumAfterLastNegative(int32_t arrSize, double arr[]);
void LessThenPSort(double* arr, int32_t arrSize, double P);

// Работа с массивом int64_t (натуральные числа)
void InputElementsInArray(int64_t* arr, int32_t arrSize);
void FillArrayWithRandomNumbers(int64_t* arr, int32_t arrSize);
void InputP(int32_t& P);
void MoreThenPSort(int64_t* arr, int32_t arrSize, int32_t P);
void MaxNumsIndex(int64_t* arr, int32_t arrSize);
void SelectionSort(int64_t* arr, int32_t arrSize);
int32_t MinNaturalNumberNotInArray(int64_t* arr, int32_t arrSize);

#endif
