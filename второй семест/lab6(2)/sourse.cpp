#include "Header.h"


void InputStr(char* str) {
		std::cout << "Input your sentense\n";
		std::cin.getline(str, 300);
}

void InputDelim(char* str) {
	std::cout << "Input all your separators\n";
	std::cin.getline(str,300);
}

int32_t CountWordsInStr(char* str, char* delim) {
	int32_t counter = {};
	char* copy = new char[300];
	strcpy(copy, str);
	char* token = strtok(copy, delim);
	while (token != NULL) {
		++counter;
		token = strtok(NULL,delim);
		
	}
	delete[]  copy;
	copy = nullptr;
	return counter;
}

void FindLongestWord(char* str, char* delim, int32_t& maxLength, size_t& maxWordIndex) {
	char* copy = new char[300];
	std::strcpy(copy, str);
	char* maxWord = NULL;
	char* token = strtok(copy, delim);
	maxWord = token;
	maxLength = strlen(token);
	while (token != NULL) {
		if (std::strlen(token) > std::strlen(maxWord)) {
			strcpy(maxWord, token);
			maxLength = strlen(token);
		}
		token = strtok(NULL, delim);
	}
	maxWordIndex = strstr(str,maxWord) - str;
	delete[]  copy;
	copy = NULL;
}

void FindLastShortestWord(char* str, char* delim, int32_t& minLength, size_t& minWordIndex) {
	char copy[300];
	strcpy(copy, str);

	char* token = strtok(copy, delim);
	char shortestWord[300];
	strcpy(shortestWord, token);
	minLength = strlen(token);

	while (token != nullptr) {
		if (strlen(token) <= strlen(shortestWord)) {
			strcpy(shortestWord, token);
			minLength = strlen(token);
		}
		token = strtok(nullptr, delim);
	}

	char* lastPos = nullptr;
	char* temp = strstr(str, shortestWord);
	while (temp != nullptr) {
		lastPos = temp;
		temp = strstr(temp + 1, shortestWord);
	}

	minWordIndex = lastPos - str;
	
}



void SwapLongWithShortWord(char*& str, size_t minWordIndex, size_t maxWordIndex, int32_t& minLength, int32_t& maxLength) {
	if (minWordIndex == maxWordIndex) {
		std::cout << str;
		std::exit(1);
	}

	char* newStr = new char[strlen(str) + 1 ]; 
	size_t i = {};
	size_t j = {};

	while (str[i] != '\0') {
		if (i == minWordIndex) {
			for (size_t k = {}; k < maxLength; ++k)
				newStr[j++] = str[maxWordIndex + k];
			i += minLength;
		}
		else if (i == maxWordIndex) {
			for (size_t k = {}; k < minLength; ++k)
				newStr[j++] = str[minWordIndex + k];
			i += maxLength;
		}
		else {
			newStr[j++] = str[i++];
		}
	}

	newStr[j] = '\0'; 

	strcpy(str, newStr);
	std::cout << str;
	delete[] newStr;
}

	


