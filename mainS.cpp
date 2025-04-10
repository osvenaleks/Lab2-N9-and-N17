int main() {
	const int32_t MaxSize = 1000;
	int32_t n = {};
	double arr[MaxSize] = {};

	InputArrSize(MaxSize, n);

	int32_t inputMode = {};
	std::cout << "Choose input method:\n";
	std::cout << "1 — Manual input\n";
	std::cout << "2 — Random fill\n";
	std::cin >> inputMode;

	if (inputMode == 1) {
		InputElementsInArray(arr, n);
	}
	else if (inputMode == 2) {
		
		FillArrayWithRandomNumbers(arr,n);
	}
	else {
		std::cerr << "Invalid input method.\n";
		return 1;
	}

	double P = {};
	InputP(P);

	int32_t countLessThanP = CountOfElementsLowerThanP(arr, n, P);
	std::cout << "Count of elements less than P: " << countLessThanP << "\n";

	int32_t sumIntAfterLastNeg = SumIntNumAfterLastNegative(n, arr);
	std::cout << "Sum of integer parts after last negative element: " << sumIntAfterLastNeg << "\n";

	LessThenPSort(P, n, arr);

	std::cout << "Array after transformation:\n";
	for (int32_t i = 0; i < n; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";

	return 0;
}
