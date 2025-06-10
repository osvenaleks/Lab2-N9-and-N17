#include "Header.h"

int main() {
	try {
		char* str = new char[300];
		char* delim = new char[300];
		int32_t minLength = {};
		int32_t maxLength = {};
		size_t minWordIndex = {};
		size_t maxWordIndex = {};
		InputStr(str);
		InputDelim(delim);
		if (CountWordsInStr(str, delim) == 0) {
			throw std::invalid_argument("empty line");
		}
		if (CountWordsInStr(str, delim) < 2) {
			throw std::domain_error("There are not enough words in the line to process,must be more than 2");
		}
		FindLastShortestWord(str, delim, minLength,minWordIndex);
		FindLongestWord(str, delim, maxLength,maxWordIndex);
		SwapLongWithShortWord(str, minWordIndex, maxWordIndex, minLength, maxLength);
	}
	catch (std::invalid_argument& e) {
		std::cerr << "error " << e.what();
	}
	catch (std::domain_error& e) {
		std::cerr << "error " << e.what();
	}
	return 0;
}