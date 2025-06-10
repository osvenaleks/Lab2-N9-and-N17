#include "Header.h"

int main() {
	std::string str = {};
	InputStr(str);
	std::string* digitWordsArr = new std::string[str.length()];
	size_t arrSize = { str.length() };
	strNumTok(str, digitWordsArr, arrSize);
	PrintOnlyNumericWordOrPreLastOne(str, digitWordsArr, arrSize);
	return 0;
}