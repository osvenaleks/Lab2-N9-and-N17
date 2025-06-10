#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <cstdint>
#include <cstdlib>

void InputStr(std::string& s);
int32_t CountZerosInWord(std::string s);
bool IsStringHasWordsWithZeros(std::string* arr, size_t arrSize);
bool IsOnlyOneWordWithMostZeros(std::string* arr, size_t arrSize,std::string wordWhithMaxZeros);
std::string PreLastOneWordWithMaxZeros(std::string* arr, size_t arrSize,std::string wordWhithMaxZeros);
std::string ReturnWordWithMaxZero(std::string * digitWordsArr,size_t arrSize);
void strNumTok(std::string str,std::string* digitWordsArr, size_t & arrSize);
void PrintOnlyNumericWordOrPreLastOne(std::string str, std::string* digitWordsArr, size_t arrSize);

#endif
