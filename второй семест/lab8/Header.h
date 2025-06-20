#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>

//file and other
void CheckIfstreamFile(std::ifstream file);
void CheckOfstreamFile(std::ifstream file);
bool IsValidDouble(double& number, const std::string token);
void InputArrfromFile(std::ifstream& file, double* arr, int32_t arrSize);
void InputArrSizeFromConsole(int32_t& arrSize);
void InputArrfromConsole(double* arr, int32_t arrSize);
void ChooseHowFillArr(int32_t & numOfVariant);
void FindArrSize(std::ifstream& file, int32_t& arrSize, int32_t numOfVariant);
void FillArr(std::ifstream& file, double* arr, int32_t arrSize, int32_t numOfVariant);
void ChooseSort(int32_t& numOfVariant);
void ChooseTipeOfSort(int32_t& numOfVariant);
void OutputArrInConsole(double* arr, int32_t arrSize);
void OutputArrInFile(std::ofstream& file, double* arr, int32_t arrSize);
void SortArr(double* arr, int32_t arrSize, int32_t& numOfVariant);
void ChooseOutput(int32_t& numOfVariant);
void OutputArr(int32_t& numOfVariant, std::ofstream & outFile, double* arr, int32_t arrSize);
//sorts

void BubbleSort(double* arr,int32_t arrSize);

void SelectionSort(double* arr, int32_t arrSize);

void InsertionSort(double* arr, int32_t arrSize);

void Merge(double * arr, int32_t left, int32_t mid, int32_t right);

void MergeSort(double * arr, int32_t left, int32_t right);
int32_t CountDigitAfterDot(double num);
int32_t CompareByFractionDigits(const void* a, const void* b);

template<typename T>
void FromBiggerToLower(T* arr, int32_t arrSize) {
	int32_t i = {};
	while (i != arrSize || i < arrSize) {
		std::swap(arr[i], arr[arrSize - 1]);
		++i;
		--arrSize;
	}
}
//struct
struct Student {
	std::string name;
	std::string surname;
	std::string group;
	std::string clas;
	int32_t marks[5];

	double CountAverageMark() const {
		double everageMark = {};
		for (int32_t i = {};i < 5;++i) {
			everageMark += marks[i];
		}
		return everageMark / 5;
	}

	bool operator<(const Student& other) const {
		return CountAverageMark() < other.CountAverageMark();
	}

	bool operator>(const Student& other) const {
		return CountAverageMark() > other.CountAverageMark();
	}

	bool operator==(const Student& other) const {
		return CountAverageMark() == other.CountAverageMark();
	}

	bool operator<=(const Student& other) const {
		return CountAverageMark() <= other.CountAverageMark();
	}

	bool operator>=(const Student& other) const {
		return CountAverageMark() >= other.CountAverageMark();
	}

};

template<typename T>
int32_t Partitions(T* arr, int32_t startIndex, int32_t endIndex) {
	T pivot = arr[endIndex];
	int32_t i = startIndex - 1;
	for (int32_t j = startIndex; j < endIndex; ++j) {
		if (arr[j] < pivot) {
			++i;
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[i + 1], arr[endIndex]);
	return i + 1;
}

template<typename T>
void QuickSort(T* arr, int32_t startIndex, int32_t endIndex) {
	if (startIndex < endIndex) {
		int32_t pivotIndex = Partitions(arr, startIndex, endIndex);
		QuickSort(arr, startIndex, pivotIndex - 1);
		QuickSort(arr, pivotIndex + 1, endIndex);
	}
}

void InputNumberOfStudents(int32_t& numberOfStudents);
void InputInfoAboutStudents(Student * students,int32_t arrSize);
double CountAverageMark(Student& student);
void OutputStudent(Student* students, int32_t arrSize);

#endif