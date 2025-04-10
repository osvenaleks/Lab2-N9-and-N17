#include <N9.h>

void FillArrayWithRandomNumbers(double* arr, int32_t arrSize) {
	int32_t a = {};
	int32_t b = {};
	std::cout << "Input min random number in array" << "\n";
	std::cin >> a;
	cout << "Input max random number in array" << "\n";
	std::cin >> b;
		srand(time(0)); 
		for (int32_t i = {}; i < arrSize; ++i) {
			arr[i] = a + rand() % (b - a + 1); 
		}
	}
}

void InputP(double& P) {
	std::cout << "Input P" << \n;
	std::cin >> P;
}

int32_t CountOfElementsLowerThanP(double* arr,int32_t arrSize,double P){
	int32_t countOfElementsLowerThanP = {};
		for (int32_t i = {};i < arrSize) {
			if (arr[i] < P) {
				++countOfElementsLowerThanP;
			}
		
		}
		return countOfElementsLowerThanP;
}

void InputElementsInArray(double* arr, int32_t MaxSize) {
	std::cout  << "Input numbers for array\n"
	for (int32_t i = {};i < arrSize) {
		std::cin >> arr[i];
	}
}

void InputArrSize(int32_t MaxSize,int32_t n) {
	std::cout << "Input Array Size\n";
	try {
		std::cin >> n;
		if (n <= 0){
		throw std::invalid_argument("incorect size of array");
		}
		if (n > MaxSize) {
		throw std::out_of_range("Your array size bigger than maximum");
		}
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Error" << e.what() << \n;
		std::exit(1);
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Error" << e.what() << \n;
		std::exit(1);
	}
}

int32_t LastNegative(int32_t arrSize,double* arr) {
	int32_t lastNegativeIndex = {};
	for (int32_t i = {arrSize - 1};i >= 0; --i) {
		if (arr[i] < 0) {
			lastNegativeIndex = {1};
			break;
		}
	}
	return lastNegativeIndex;
}

void LessThenPSort(double P, int32_t arrSize, double* arr) {
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
	int32_t	lastNegativeIndex = { LastNegative(arrSize,arr) };
	int32_t sumIntAfterLastNegative = { };
	if (lastNegativeIndex == arrSize - 1) {
		return 0;
	}
	for(int32_t i = { lastNegativeIndex + 1 }; i < arrSize; ++i) {
		if (arr[i] == static_cast<int>(arr[i])) {
			sumIntAfterLastNegative += static_cast<int>(arr[i]);
		}
	}
	return sumIntAfterLastNegative;
}



