#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdint>
#include<cstring>

void InputStr(char* str);
void InputDelim(char* delim);
int32_t CountWordsInStr(char* str, char* delim);
void FindLastShortestWord(char* str, char* delim, int32_t& minLength,size_t& minWordIndex);
void FindLongestWord(char* str, char* delim, int32_t& maxLength,size_t& maxWordIndex);
void SwapLongWithShortWord(char*& str, size_t minWordIndex, size_t maxWordIndex,int32_t& minLength, int32_t& maxLength);