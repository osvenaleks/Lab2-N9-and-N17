#ifndef Header_H
#define Header_H

#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <random>

void InputMtrSize(int32_t& rows, int32_t& cols);
void InputBorders(int32_t& a, int32_t& b);
void ChooseMethod(double**& mtr, int32_t rows, int32_t cols);
void InputElementsInMtr(double **& mtr, int32_t rows,int32_t cols);
void FillMtrWithRandomNumbers(double**& mtr, int32_t rows, int32_t cols1);
void FindFirstRowsWithZero(double **& mtr, int32_t rows, int32_t cols);
bool IsMinNumInRow(double**& mtr, int32_t cols, double num, int32_t numRow);
bool IsMaxNumInColl(double**& mtr, int32_t rows, double num, int32_t numColl);
bool IsMaxNumInColl(double**& mtr, int32_t rows, double num, int32_t numColl);
void FindCoordsOfAllSaddlePoints(double**& mtr, int32_t rows, int32_t cols);
void FindCollOfMaxElementInMtr(double**& mtr, int32_t rows, int32_t cols, int32_t& maxColl);
void FindRowOfMinElementInMtr(double**& mtr, int32_t rows, int32_t cols, int32_t& minRow);
void CountDotProduct(double**& mtr, int32_t rows, int32_t cols);
int64_t FindFirstIntegerElementInMtr(double**& mtr, int32_t rows, int32_t cols);
void FindMinIntegerElementInMtr(double**& mtr, int32_t rows, int32_t cols, int64_t& firstMinIntegerElementInMtr);
void FindFirstMinIntegerElementInMtr(double**& mtr, int32_t rows, int32_t cols);
#endif