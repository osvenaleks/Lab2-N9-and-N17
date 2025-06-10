#include "Header.h"

void InputStr(std::string& s) {
	try {
		std::cout << "Input your sentense\n";
		getline(std::cin, s);
		if (s.empty()) {
			throw std::invalid_argument("string is empty");
		}
		else if (s.find(' ') == std::string::npos) {
			throw std::invalid_argument("it is word,must be string(between words must be 1 or more space)");
		}
		else if (s[0] == ' ') {
			throw std::invalid_argument("string must start not whith space");
		}
	}
	catch (std::invalid_argument& e) {
		std::cerr << "error " << e.what();
		std::exit(1);
	}
}

void strNumTok(std::string str, std::string* digitWordsArr, size_t& arrSize) {
	try {
		size_t start = {};
		size_t countWordsWithOnlyNum = {};
		while (start < arrSize) {

			while (start < arrSize && str[start] == ' ') {
				++start;
			}

			if (start >= arrSize) {
				break;
			}

			size_t end = { start };

			while (end < arrSize && str[end] != ' ') {
				++end;
			}

			std::string word = { str.substr(start, end - start) };

			bool allDigits = true;
			for (char ch : word) {
				if (!isdigit(ch)) {
					allDigits = false;
					break;
				}
			}
			if (allDigits == true) {
				digitWordsArr[countWordsWithOnlyNum] = word;
				++countWordsWithOnlyNum;
			}

			start = end;
		}
		arrSize = countWordsWithOnlyNum;
		if (digitWordsArr[0].empty() == true) {
			throw std::invalid_argument("must be 1 word which has only digits with zero");
		}
	}
	catch (std::invalid_argument& e) {
		std::cerr << "error " << e.what();
		std::exit(1);
	}

}

bool IsStringHasWordsWithZeros(std::string* arr, size_t arrSize) {
	int32_t counter = {};
	for (int32_t i = {};i < arrSize;++i) {
		if (CountZerosInWord(arr[i]) == 0) {
			counter++;
		}
	}
	if (counter == arrSize) {
		return false;
	}
	else {
		return true;
	}
}

int32_t CountZerosInWord(std::string s) {
	int32_t counter = {};
	for (char ch : s) {
		if (ch == '0') {
			++counter;
		}
	}
	return counter;
}

bool IsOnlyOneWordWithMostZeros(std::string* arr, size_t arrSize, std::string wordWhithMaxZeros) {
	int32_t counter = {};
	for (int32_t i = {};i < arrSize;++i) {
		if (CountZerosInWord(arr[i]) == CountZerosInWord(wordWhithMaxZeros)) {
			++counter;
		}
	}
	if (counter == 1) {
		return true;
	}
	else {
		return false;
	}
}

std::string PreLastOneWordWithMaxZeros(std::string* arr, size_t arrSize, std::string wordWhithMaxZeros) {
	int32_t counter = {};
	for (size_t i = { arrSize - 1 };i >= 0;--i) {
		if (CountZerosInWord(arr[i]) == CountZerosInWord(wordWhithMaxZeros)) {
			++counter;
				if (counter == 2 && CountZerosInWord(arr[i]) == CountZerosInWord(wordWhithMaxZeros)) {
					return arr[i];
				}
		}
	}
}

std::string ReturnWordWithMaxZero(std::string* digitWordsArr, size_t arrSize) {
	std::string wordWhithMaxZeros = digitWordsArr[0];
	for (int32_t i = {};i < arrSize;++i) {
		if (CountZerosInWord(digitWordsArr[i]) >= CountZerosInWord(wordWhithMaxZeros)) {
			wordWhithMaxZeros = digitWordsArr[i];
		}
	}
	return wordWhithMaxZeros;
}

void PrintOnlyNumericWordOrPreLastOne(std::string str, std::string* digitWordsArr, size_t arrSize) {
	try {
		if (IsStringHasWordsWithZeros(digitWordsArr, arrSize) == true) {
			std::string wordWhithMaxZeros = ReturnWordWithMaxZero(digitWordsArr,arrSize);
			if (IsOnlyOneWordWithMostZeros(digitWordsArr,arrSize, wordWhithMaxZeros) == true) {
				std::cout << "Word whith max zeros is " << wordWhithMaxZeros;
			}
			else {
				wordWhithMaxZeros = PreLastOneWordWithMaxZeros(digitWordsArr, arrSize, wordWhithMaxZeros);
				std::cout << "Pre last word whith max zeros is " << wordWhithMaxZeros;
			}
		}
		else {
				throw std::invalid_argument("must be 1 word which has only digits with zeros");
		}
	}
	catch (std::invalid_argument& e) {
		std::cerr << "error " << e.what();
		std::exit(1);
	}
}