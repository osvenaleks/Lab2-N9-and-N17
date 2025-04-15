#include "N9.h"

void InputP(double& P) {
	std::cout << "Input P\n";
	std::cin >> P;
}

void ChooseMethod(double* arr, int32_t arrSize) {
	std::cout << "Choose input method:\n1 - From keyboard\n2 - Random values\n";
	int32_t method = {};
	try {
		std::cin >> method;
		if (method != 1 && method != 2) {
			throw std::invalid_argument("Incorect method");
		}
	}
	catch (std::invalid_argument& e) {
		std::cerr << "error" << e.what();
		exit(1);
	}
	if (method == 1) {
		InputElementsInArray(arr, arrSize);
	}
	else if (method == 2) {
		FillArrayWithRandomNumbersD(arr, arrSize);
	}
}

void InputArrSize(int32_t maxSize, int32_t& arrSize) {
	std::cout << "Input Array Size\n";
	try {
		std::cin >> arrSize;
		if (arrSize <= 0) {
			throw std::invalid_argument("incorect size of array\n");
		}
		if (arrSize > maxSize) {
			throw std::out_of_range("Your array size bigger than maximum\n");
		}
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Error" << e.what();
		std::exit(1);
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Error" << e.what();
		std::exit(1);
	}
}

void FillArrayWithRandomNumbersD(double* arr, int32_t arrSize) {
	int32_t a = {};
	int32_t b = {};
	std::cout << "Input min random number in array\n";
	std::cin >> a;
	std::cout << "Input max random number in array\n";
	std::cin >> b;
	srand(time(0));
	for (int32_t i = {}; i < arrSize; ++i) {
		arr[i] = a + (static_cast<double>(rand()) / RAND_MAX) * (b - a);
	}
}


void InputElementsInArray(double* arr, int32_t arrSize) {
	std::cout << "Input numbers for array\n";
	for (int32_t i = {};i < arrSize;++i) {
		std::cin >> arr[i];
	}
}

int32_t CountOfElementsLowerThanP(double* arr, int32_t arrSize, double P) {
	int32_t countOfElementsLowerThanP = {};
	for (int32_t i = {};i < arrSize;++i) {
		if (arr[i] < P) {
			++countOfElementsLowerThanP;
		}

	}
	return countOfElementsLowerThanP;
}

int32_t LastNegative(double* arr, int32_t arrSize) {
	int32_t lastNegativeIndex = {};
	for (int32_t i = { arrSize - 1 };i >= 0; --i) {
		if (arr[i] < 0) {
			lastNegativeIndex = { i };
			break;
		}
	}
	return lastNegativeIndex;
}

void LessThenPSort(double* arr, int32_t arrSize, double P) {
	size_t sortIndex = {};
	for (size_t i = {}; i < static_cast<size_t>(arrSize); ++i) {
		if (arr[i] < P) {
			double temp = { arr[i] };
			arr[i] = arr[sortIndex];
			arr[sortIndex] = temp;
			++sortIndex;
		}
	}
}


int32_t SumIntNumAfterLastNegative(int32_t arrSize, double arr[]) {
	int32_t	lastNegativeIndex = { LastNegative(arr,arrSize) };
	int32_t sumIntAfterLastNegative = { };
	if (lastNegativeIndex == arrSize - 1) {
		return 0;
	}
	for (int32_t i = { lastNegativeIndex + 1 }; i < arrSize; ++i) {
		if (arr[i] == static_cast<int>(arr[i])) {
			sumIntAfterLastNegative += arr[i];
		}
	}
	return sumIntAfterLastNegative;
}

void FillArrayWithRandomNumbers(int64_t* arr, int32_t arrSize) {
	int32_t a = {};
	int32_t b = {};
	try {
		std::cout << "Input min random number in array" << "\n";
		std::cin >> a;
		if (a < 0) {
			throw std::invalid_argument("a must be more than 0");
		}
		std::cout << "Input max random number in array" << "\n";
		std::cin >> b;
		if (b < 0) {
			throw std::invalid_argument("b must be more than 0");
		}
		if (a > b) {
			std::swap(a, b);
		}
	}
	catch (std::invalid_argument& e) {
		std::cerr << "error" << e.what();
		exit(1);
	}
	srand(time(0));
	for (int32_t i = {}; i < arrSize; ++i) {
		arr[i] = a + rand() % (b - a + 1);
	}
}

void ChooseMethod(int64_t* arr, int32_t arrSize) {
	std::cout << "Choose input method:\n1 - From keyboard\n2 - Random values\n";
	int32_t method = {};
	try {
		std::cin >> method;
		if (method != 1 && method != 2) {
			throw std::invalid_argument("Incorect method");
		}
	}
	catch (std::invalid_argument& e) {
		std::cerr << "error" << e.what();
		exit(1);
	}
	if (method == 1) {
		InputElementsInArray(arr, arrSize);
	}
	else if (method == 2) {
		FillArrayWithRandomNumbers(arr, arrSize);
	}
}

void InputElementsInArray(int64_t* arr, int32_t arrSize) {
	std::cout << "Input numbers for array\n";
	try {
		for (int32_t i = {};i < arrSize;++i) {
			std::cin >> arr[i];
			if (arr[i] < 0) {
				throw std::invalid_argument(" must be more than 0");
			}
		}
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "error" << e.what();
		exit(1);
	}
}



void InputP(int32_t& P) {
	std::cout << "Input P\n";
	std::cin >> P;
}

void MoreThenPSort(int64_t* arr, int32_t arrSize, int32_t P) {
	size_t sortIndex = {};
	for (size_t i = {}; i < arrSize; ++i) {
		if (arr[i] > P) {
			int64_t temp = { arr[i] };
			arr[i] = arr[sortIndex];
			arr[sortIndex] = temp;
			++sortIndex;
		}
	}
}

void MaxNumsIndex(int64_t* arr, int32_t arrSize) {
	int32_t maxElement = {};
	for (int32_t i = {};i < arrSize; ++i) {
		if (arr[i] > maxElement) {
			maxElement = arr[i];
		}
	}
	for (int32_t i = {};i < arrSize; ++i) {
		std::cout << "Max nams Index: ";
		if (arr[i] == maxElement) {
			std::cout << i;
		}
	}
}

void SelectionSort(int64_t* arr, int32_t arrSize) {
	for (int32_t i = {}; i < arrSize - 1; ++i) {
		int32_t minIdx = { i };
		for (int32_t j = { i + 1 }; j < arrSize; ++j)
			if (arr[j] < arr[minIdx])
				minIdx = { j };
		std::swap(arr[i], arr[minIdx]);
	}
}


int32_t MinNaturalNumberNotInArray(int64_t* arr, int32_t arrSize) {
	SelectionSort(arr, arrSize);
	for (int32_t i = {}; i < arrSize; ++i) {
		if (arr[i] != i + 1) {
			return i + 1;
		}
	}
	return arrSize + 1;
}