#include "Header.h"

int main() {
	int32_t rows = {};
	int32_t cols = {};
	InputMtrSize(rows,cols);
	double** mtr = new double* [rows];
	for (int32_t i = {};i < rows;++i) {
		mtr[i] = new double[cols];
	}
	ChooseMethod(mtr, rows, cols);
	FindFirstRowsWithZero(mtr,rows,cols);
	FindCoordsOfAllSaddlePoints(mtr,rows, cols);
	CountDotProduct(mtr,rows,cols);
	FindFirstMinIntegerElementInMtr(mtr,rows,cols);
	return 0;
}