#include <iostream>
#include <iomanip>
#include <cstdint>
#include <stdexcept>

int main() {

	int32_t rows1 = {};
	int32_t cols1 = {};
	int32_t rows2 = {};
	int32_t cols2 = {}; 

	try {
		std::cout << "input number of rows matrix1\n";
		std::cin >> rows1;
		if (rows1 <= 0) {
			throw std::invalid_argument("cols and rows must be more then 0");
		}
		std::cout << "input number of cols matrix1\n";
		std::cin >> cols1;
		if (cols1 <= 0) {
			throw std::invalid_argument("cols and rows must be more then 0");
		}
		std::cout << "input number of rows matrix2\n";
		std::cin >> rows2;
		if (rows2 <= 0) {
			throw std::invalid_argument("cols and rows must be more then 0");
		}
		std::cout << "input number of cols matrix2\n";
		std::cin >> cols2;
		if (cols2 <= 0) {
			throw std::invalid_argument("cols and rows must be more then 0");
		}
		if (cols1 != rows2) {

			throw std::invalid_argument("cols matrix 1 must be equal rows matrix2\n");
		}
	}
	catch(std::invalid_argument& e){
		std::cerr << "Eror " << e.what();
		return 1;
	}
	
	int32_t** ptr1 = new int32_t* [rows1];
	int32_t** ptr2 = new int32_t* [rows2];
	int32_t** ptr3 = new int32_t* [rows1];

	for (int32_t i = {}; i < rows1; ++i) {
		ptr1[i] = new int32_t[cols1];
	}

	for (int32_t i = {}; i < rows2;++i) {
		ptr2[i] = new int32_t[cols2];
	}

	for (int32_t i = {}; i < rows1; ++i) {
		ptr3[i] = new int32_t[cols2];
	}

	std::cout << "input elements in matrix1\n";

	for (int32_t i = {}; i < rows1; ++i) {
		for (int32_t j = {};j < cols1; ++j) {
			std::cin >> ptr1[i][j];
			
		}
	}

	std::cout << "input elements in matrix2\n";
	for (int32_t i = {}; i < rows2; ++i) {
		for (int32_t j = {};j < cols2; ++j) {
			std::cin >> ptr2[i][j];
		}
	}

	for (int32_t i = {};i < rows1;++i) {
		for (int32_t j = {}; j < cols2; ++j) {
			ptr3[i][j] = {};
			for (int32_t k = {}; k < cols2; ++k) {
				ptr3[i][j] += ptr1[i][k] * ptr2[k][i];
			}
		}
		
	}
	std::cout << "\n";

	for (int32_t i = {}; i < rows1; ++i) {
		for (int32_t j = {};j < cols1; ++j) {
			std::cout << ptr1[i][j] << std::setw(8);
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	for (int32_t i = {}; i < rows2; ++i) {
		for (int32_t j = {};j < cols2; ++j) {
			std::cout << ptr2[i][j] << std::setw(8);
		}
		std::cout << "\n";
	}
	std::cout << "multiply matrix1 and matrix2\n";
	for (int32_t i = {}; i < rows1; ++i) {
		for (int32_t j = {};j < cols2; ++j) {
			std::cout << ptr3[i][j] << std::setw(8);
		}
		std::cout << "\n";
	}

	for (int32_t i = {}; i < rows1; ++i) {
		delete[] ptr1[i];
		ptr1[i] = nullptr;
	}

	for (int32_t i = {}; i < rows2; ++i) {
		delete[] ptr2[i];
		ptr2[i] = nullptr;
	}

	for (int32_t i = {}; i < rows1; ++i) {
		delete[] ptr3[i];
		ptr3[i] = nullptr;
	}

	delete[] ptr1;
	delete[] ptr2;
	delete[] ptr3;

	ptr1 = nullptr;
	ptr2 = nullptr;
	ptr3 = nullptr;

	return 0;

}