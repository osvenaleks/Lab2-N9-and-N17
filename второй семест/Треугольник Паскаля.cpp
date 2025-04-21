#include <iostream>
#include <cstdint>



int main() {

	int32_t trianglePower = {};

	std::cout << "Input power of Pascal Triangle\n";
	try {
		std::cin >> trianglePower;
		if (trianglePower < 0) {
		throw std::invalid_argument("Incorect power");
		}
	}
	catch(std::invalid_argument& e){
		std::cerr << "error: " << e.what();
		return 0;
	}

	int32_t** trianglePascal = new int32_t* [trianglePower];

	for (int32_t i = {}; i < trianglePower; ++i) {
		trianglePascal[i] = new int32_t [i + 1];
	}

	for (int32_t i = {}; i < trianglePower; ++i) {
		for (int32_t j = {}; j < trianglePower; ++j) {
			if (j == 0 ||  j == i) {
				trianglePascal[i][j] = 1;
			}
			else if (j > 0 && j < i) {
				trianglePascal[i][j] = trianglePascal[i - 1][j] + trianglePascal[i - 1][j - 1];
			}
		}
	}

	std::cout << "Pascal Trianfle of Power " << trianglePower << ":\n";
	for (int32_t i = {}; i < trianglePower; ++i) {
		for (int32_t j = {}; j < trianglePower; ++j) {
			if (j <= i) {
				std::cout << trianglePascal[i][j] << "  ";
			}
		}
		std::cout << "\n";
	}

	for (int32_t i = {}; i < trianglePower; ++i) {
		delete [] trianglePascal[i];
		trianglePascal[i] = nullptr;
	}
	delete[] trianglePascal;
	trianglePascal = nullptr;
	return 0;
}