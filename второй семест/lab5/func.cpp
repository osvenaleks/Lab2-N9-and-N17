#include "Header.h"


void InputMtrSize(int32_t& rows, int32_t& cols) {
	try {
		std::cout << "Input number of rows\n";
		std::cin >> rows;
		if (rows <= 0) {
			throw std::invalid_argument("number of rows must be more then 0");
		}
		std::cout << "Input number of cols\n";
		std::cin >> cols;
		if (cols <= 0) {
			throw std::invalid_argument("number of cols must be more then 0");
		}
	}
	catch(std::invalid_argument& e){
		std::cerr << "error: " << e.what();
		std::exit(1);
	}
}

void InputElementsInMtr(double **& mtr, int32_t rows, int32_t cols) {
	std::cout << "Input elements in matrix\n";
	for (int32_t i = {}; i < rows;++i) {
		for (int32_t j = {}; j < cols;++j) {
			std::cout << "elemet on index [" << i + 1 << ';' << j + 1 << "] = ";
			std::cin >> mtr[i][j];
			std::cout << '\n';
		}
	}
}

void InputBorders(int32_t& a, int32_t& b) {
	try {
		std::cout << "Input first border a for random filling ";
		std::cin >> a;
		std::cout << "Input first border b for random filling ";
		std::cin >> b;
		if (a == b) {
			throw std::invalid_argument("a and b must be different");
		}
		if (a > b) {
			std::swap(a, b);
		}
	}
	catch (std::invalid_argument& e) {
		std::cerr << "error: " << e.what();
		std::exit(1);
	}
}

void FillMtrWithRandomNumbers(double **& mtr, int32_t rows, int32_t cols) {
	int32_t a = {};
	int32_t b = {};
	InputBorders(a, b);
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<>dist(a, b);
	for (int32_t i = {}; i < rows;++i) {
		for (int32_t j = {}; j < cols;++j) {
			mtr[i][j] = dist(gen);
			std::cout << "elemet on index [" << i + 1 << ';' << j + 1 << "] = " << mtr[i][j] << '\n';
		}
	}

}

void ChooseMethod(double **& mtr, int32_t rows, int32_t cols) {
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
		InputElementsInMtr(mtr,rows,cols);
	}
	else if (method == 2) {
		FillMtrWithRandomNumbers(mtr, rows,cols);
	}
}

void FindFirstRowsWithZero(double **& mtr,int32_t rows, int32_t cols) {
	int32_t indexOfFirstRowsWithZero = {-1};
	for (int32_t i = {}; i < rows; ++i) {
		for (int32_t j = {}; j < cols;++j) {
			if (mtr[i][j] == 0) {
				indexOfFirstRowsWithZero = i;
				break;
			}
		}
	}
	if (indexOfFirstRowsWithZero == -1) {
		std::cout << "all rows not include zero\n";
	}
	else {
		std::cout << "index of first row with zero:= " << indexOfFirstRowsWithZero << "\n";
	}
}

bool IsMinNumInRow(double**& mtr, int32_t cols,double num,int32_t numRow) {
	for (int32_t i = {};i < cols;++i) {
		if (num > mtr[numRow][i]) {
			return false;
		}
	}
	return true;
}

bool IsMaxNumInColl(double**& mtr, int32_t rows, double num, int32_t numColl) {
	for (int32_t i = {};i < rows;++i) {
		if (num < mtr[i][numColl]) {
			return false;
		}
	}
	return true;
}

void FindCoordsOfAllSaddlePoints(double**& mtr, int32_t rows, int32_t cols) {
	int32_t saddlePointsCounter = {};
	for (int32_t i = {}; i < rows;++i) {
		for (int32_t j = {}; j < cols;++j) {
			if (IsMinNumInRow(mtr, cols, mtr[i][j], i) == true) {
				if (IsMaxNumInColl(mtr, rows, mtr[i][j], j) == true) {
					++saddlePointsCounter;
					std::cout <<"Index of saddle point Number " << saddlePointsCounter  << " = " << '[' << i << ';' << j << "]\n";
				}
			}
		}
	}
	if (saddlePointsCounter == 0) {
		std::cout << "matrix don't has a saddle points\n";
	}
}

void FindCollOfMaxElementInMtr(double**& mtr, int32_t rows, int32_t cols,int32_t& maxColl) {
	int32_t maxRow = {};
	for (int32_t i = {1}; i < rows;++i) {
		for (int32_t j = {0}; j < cols;++j) {
			if (mtr[i][j] > mtr[maxRow][maxColl]) {
				maxRow = i;
				maxColl = j;
			}
		}
	}
}

void FindRowOfMinElementInMtr(double**& mtr, int32_t rows, int32_t cols, int32_t& minRow) {
	int32_t minColl = {};
	for (int32_t i = { 1 }; i < rows;++i) {
		for (int32_t j = { 0 }; j < cols;++j) {
			if (mtr[i][j] > mtr[minRow][minColl]) {
				minRow = i;
				minColl = j;
			}
		}
	}
}

void CountDotProduct(double**& mtr, int32_t rows, int32_t cols) {
	try {
		if (rows != cols) {
			throw std::invalid_argument("rows must be = cols for Count Dot Ptoduct");
		}
	}
	catch (std::invalid_argument& e) {
		std::cerr << "error " << e.what();
		std::exit(1);
	}
	int32_t maxColl = {};
	int32_t minRow = {};
	FindCollOfMaxElementInMtr(mtr, rows, cols, maxColl);
	FindRowOfMinElementInMtr(mtr, rows, cols, minRow);	
	double dotProduct = {};
	for (int32_t i = {};i < rows;++i) {
		dotProduct += (mtr[minRow][i] * mtr[i][maxColl]);
	}
	std::cout << "Dot ptoduct of row with min element and coll with max element = " << dotProduct << '\n';
}

int64_t FindFirstIntegerElementInMtr(double**& mtr, int32_t rows, int32_t cols) {
	try {
		bool isExist = false;
		for (int32_t i = {  }; i < rows;++i) {
			for (int32_t j = { }; j < cols;++j) {
				if (mtr[i][j] == static_cast<int64_t>(mtr[i][j])) {
					isExist = true;
					return mtr[i][j];
				}
			}
		}
		if (isExist == false) {
			throw std::invalid_argument("must be one integer element in the matrix");
		}
	}
	catch (std::invalid_argument& e) {
		std::cerr << "error " << e.what();
	}
}

void FindMinIntegerElementInMtr(double**& mtr, int32_t rows, int32_t cols, int64_t& firstMinIntegerElementInMtr) {
	for (int32_t i = { }; i < rows;++i) {
		for (int32_t j = { }; j < cols;++j) {
			if (mtr[i][j] == static_cast<int64_t>(mtr[i][j])) {
				if (mtr[i][j] < firstMinIntegerElementInMtr) {
					firstMinIntegerElementInMtr = mtr[i][j];
				}
			}
		}
	}
}

void FindFirstMinIntegerElementInMtr(double**& mtr, int32_t rows, int32_t cols) {
	bool isExist = false;
	int64_t firstMinIntegerElementInMtr = { FindFirstIntegerElementInMtr(mtr, rows, cols) };
	FindMinIntegerElementInMtr(mtr, rows, cols, firstMinIntegerElementInMtr);
	for (int32_t i = { }; i < rows;++i) {
		if (IsMinNumInRow(mtr, cols,firstMinIntegerElementInMtr,i) == true) {
			isExist = true;
		}
	}
	if (isExist == true) {
		std::cout << "the smallest integer for which at least one row of the matrix has all its elements less than this number is = " << firstMinIntegerElementInMtr << '\n';
	}
	else {
		std::cout << "the smallest integer for which at least one row of the matrix has all its elements less than this number NOT exist\n";
	}
}