#include "N9.h"

int main() {
	std::cout << "Variant 9: Working with a static array of real numbers\n";
	const int32_t maxSize = { 100 };
	int32_t size9 = {};

	InputArrSize(maxSize, size9);

	double* dinamicArr9 = new double[size9];

	ChooseMethod(dinamicArr9,size9);

	double P9 = {};
	InputP(P9);

	int32_t countLessThanP = CountOfElementsLowerThanP(dinamicArr9, size9, P9);
	std::cout << "Number of elements less than P: " << countLessThanP << "\n";

	int32_t sumAfterLastNegative = SumIntNumAfterLastNegative(size9, dinamicArr9);
	std::cout << "Sum of integer parts after the last negative element: " << sumAfterLastNegative << "\n";

	LessThenPSort(dinamicArr9, size9, P9);

	std::cout << "Array after transformation:\n";
	for (int32_t i = {}; i < size9; ++i) {
		std::cout << dinamicArr9[i] << " ";
	}
	std::cout << "\n";

	delete[] dinamicArr9;

	dinamicArr9 = nullptr;

	std::cout << "Variant 17: Processing a static array of natural numbers\n";
	
	int32_t size17 = {};

	InputArrSize(maxSize, size17);

	int64_t* dinamicArr17 = new int64_t[size17];

	ChooseMethod(dinamicArr17, size17);

	for (int32_t i = {}; i < size17; ++i) {
		std::cout << dinamicArr17[i] << " ";
	}

	int32_t maxValue = dinamicArr17[0];
	for (int32_t i = {1}; i < size17; ++i) {
		if (dinamicArr17[i] > maxValue) {
			maxValue = dinamicArr17[i];
		}
	}

	std::cout << "Indices of all maximum elements: ";
	for (int32_t i = {}; i < size17; ++i) {
		if (dinamicArr17[i] == maxValue) {
			std::cout << i << " ";
		}
	}
	std::cout << "\n";

	int32_t minMissing = MinNaturalNumberNotInArray(dinamicArr17, size17);
	std::cout << "Smallest missing natural number: " << minMissing << "\n";

	int32_t P17 = {};
	InputP(P17);

	MoreThenPSort(dinamicArr17, size17, P17);

	std::cout << "Array after transformation:\n";
	for (int32_t i = {}; i < size17; ++i) {
		std::cout << dinamicArr17[i] << " ";
	}
	std::cout << "\n";

	delete[] dinamicArr17;
	dinamicArr17 = nullptr;

	return 0;
}