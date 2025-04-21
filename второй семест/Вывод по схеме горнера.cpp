#include <iostream>

char returnSign(double number);

void GornerAutput(double* arr, int32_t degree);

void InputArrSize(int32_t& arrSize);

void FillArr(double*& arr, int32_t arrSize);

int main() {
	int32_t arrSize = {};
	try {
		InputArrSize(arrSize);
		if (arrSize <= 0) {
			throw std::invalid_argument("Size must be more then 0");
		}
	}
	catch (std::invalid_argument& e) {
		std::cerr << "error: " << e.what();
	}

	double* arr = new double[arrSize];

	FillArr(arr, arrSize);

	GornerAutput(arr, arrSize - 1);

	delete[] arr;
	arr = nullptr;
}

void InputArrSize(int32_t& arrSize) {
	std::cout << "Input arr size\n";
	std::cin >> arrSize;
}

void FillArr(double*& arr, int32_t arrSize) {
	std::cout << "input elements in array\n";
	for (int32_t i = {}; i < arrSize; ++i) {
		std::cin >> arr[i];
	}
}

char returnSign(double number)
{
	return number >= 0 ? '+' : '-';
}

void GornerAutput(double* arr, int32_t degree) {
	for (int32_t i = {};i < degree - 1; ++i) {
		if (arr[i] != 0) {
			std::cout << "(";
		}
	}
	if (arr[0] != 1 && arr[0] != -1)
	{
		std::cout << arr[0];
	}
	else if (arr[0] == -1)
	{
		std::cout << returnSign(arr[0]);
	}
	std::cout << "x ";
	for (int32_t i = 1; i <= degree; ++i)
	{
		std::cout << returnSign(arr[i]) << ' ' << abs(arr[i]);
		(i != degree) ? std::cout << ")x " : std::cout << " ";
	}
}