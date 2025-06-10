#include "Header.h"

//file and Input
void InputArrSizeFromConsole(int32_t& arrSize) {
	try {
		std::cout << "input arr size\n";
		std::cin >> arrSize;
		if (arrSize <= 0) {
			throw std::invalid_argument("Array size must be bigger then 0");
		}
	}
	catch (std::invalid_argument& e) {
		std::cerr << "error: " << e.what();
		std::exit(1);
	}
}

void FindArrSizeFromFile(std::ifstream& file, int32_t& arrSize) {
	std::size_t pos = {};
	std::string token;
	double num = {};
	int32_t counter = {};
	while (file >> token) {
		try {
			num = std::stod(token,&pos);
			if (pos == token.length()) {
				++counter;
			}
		}
		catch (const std::invalid_argument&) {

		}
		catch (const std::out_of_range&) {
			std::cerr << "your namber out of range";
			std::exit(1);
		}
	}
	arrSize = counter;
	try {
		if (arrSize == 0) {
			throw std::invalid_argument("your file must have a number");
		}
	}
	catch (std::invalid_argument& e) {
		std::cerr << "error" << e.what();
		std::exit(1);
	}
	file.clear();
	file.seekg(0, std::ios::beg);
}

bool IsValidDouble(double& number,const std::string token) {
	std::size_t pos = {};
   try {
       number = std::stod(token, &pos);
       return pos == token.length(); 
    } 
    catch (const std::invalid_argument&) {
	return false;
    }
    catch (const std::out_of_range&) {
	return false;
    }
}

void InputArrfromFile(std::ifstream& file, double*& arr,int32_t arrSize) {
	std::string token;
	double num = {};
	int32_t i = {};
	while (file >> token && i < arrSize) {
		if (IsValidDouble(num,token) == true) {
		  arr[i] = num;
		  ++i;
		}	
	}
}

void InputArrfromConsole(double*& arr, int32_t arrSize) {
	std::cout << "Input elements im arr\n";
	for (int32_t i = {};i < arrSize;++i) {
		std::cin >> arr[i];
	}
}

void OutputArrInConsole(double*& arr, int32_t arrSize) {
	std::cout << "Your sorted array:\n";
	for (int32_t i = {};i < arrSize;++i) {
		std::cout << arr[i] << '\n';
	}
}

void OutputArrInFile(std::ofstream& file,double*& arr, int32_t arrSize) {
	for (int32_t i = {}; i < arrSize; ++i) {
		file << arr[i];
		if (i < arrSize - 1) {
			file << " ";
		}
	}
	std::cout << "Arr record in fale outText.txt\n";
}

void ChooseHowFillArr(int32_t & numOfVariant) {
	std::cout << "Chose How you fill Array:\n";
	std::cout << "Variant 1:From console\n";
	std::cout << "Variant 2:From File\n";
	try {
		std::cin >> numOfVariant;
		if (numOfVariant != 1 && numOfVariant != 2) {
			throw std::invalid_argument("Incorect chose,must be 1 or 2");
		}
	}
	catch (std::invalid_argument& e) {
		std::cerr << "error " << e.what();
		std::exit(1);
	}
}

void FindArrSize(std::ifstream& file,int32_t& arrSize, int32_t numOfVariant) {
	if (numOfVariant == 1) {
		InputArrSizeFromConsole(arrSize);
	}
	else {
		FindArrSizeFromFile(file, arrSize);
	}
}

void FillArr(std::ifstream& file,double*& arr, int32_t arrSize, int32_t numOfVariant) {
	if (numOfVariant == 1) {
		InputArrfromConsole(arr, arrSize);
	}
	else {
		InputArrfromFile(file, arr, arrSize);
	}
}

void ChooseSort(int32_t& numOfVariant) {
	std::cout << "Chose How you sort Array:\n";
	std::cout << "Variant 1:Bubble Sort\n";
	std::cout << "Variant 2: SelectionSort\n";
	std::cout << "Variant 3:InsertionSort\n";
	std::cout << "Variant 4:QuickSort\n";
	std::cout << "Variant 5: MergeSort\n";
	std::cout << "Variant 6: qsort(numbers after dot)\n";
	try {
		std::cin >> numOfVariant;
		if (numOfVariant < 1 && numOfVariant > 6) {
			throw std::invalid_argument("Incorect chose,must be from 1 to 6");
		}
	}
	catch (std::invalid_argument& e) {
		std::cerr << "error" << e.what();
		std::exit(1);
	}
}

void ChooseTipeOfSort(int32_t& numOfVariant) {
	std::cout << "Chose How you sort the array:\n";
	std::cout << "Variant 1:From lowest to biggest\n";
	std::cout << "Variant 2:From biggest to lowest\n";
	try {
		std::cin >> numOfVariant;
		if (numOfVariant != 1 && numOfVariant != 2) {
			throw std::invalid_argument("Incorect chose,must be 1 or 2");
		}
	}
	catch (std::invalid_argument& e) {
		std::cerr << "error" << e.what();
		std::exit(1);
	}
}

void SortArr(double * arr,int32_t arrSize,int32_t & numOfVariant) {
	void (*simpleSorts[3])(double*, int32_t) = { BubbleSort, SelectionSort,InsertionSort };
	void (*compositeFunctions[2])(double*, int32_t, int32_t) = { QuickSort,MergeSort };

	if (numOfVariant <= 3) {
		simpleSorts[numOfVariant - 1](arr,arrSize);
	}
	else if(numOfVariant <= 5) {
		compositeFunctions[numOfVariant - 4](arr,0,arrSize - 1);
	}
	else {
		std::qsort(arr, static_cast<size_t>(arrSize), sizeof(double), CompareByFractionDigits);
	}

	ChooseTipeOfSort(numOfVariant);
	if (numOfVariant == 2) {
		FromBiggerToLower(arr,arrSize);
	}
}

void ChooseOutput(int32_t & numOfVariant) {
	try {
		std::cout << "Choose when output array\n";
		std::cout << "Variant 1:In file\n";
		std::cout << "Variant 2:In console\n";
		std::cin >> numOfVariant;
		if (numOfVariant != 1 && numOfVariant != 2) {
			throw std::invalid_argument("Incorect chose,must be 1 or 2");
		}
	}
	catch (std::invalid_argument& e) {
		std::cerr << "error" << e.what();
		std::exit(1);
	}
}

void OutputArr(int32_t & numOfVariant,std::ofstream& outFile,double* arr,int32_t arrSize){
	if (numOfVariant == 1) {
		OutputArrInFile(outFile,arr,arrSize);
	}
	else {
		ChooseOutput(numOfVariant);
		if (numOfVariant == 1) {
			OutputArrInFile(outFile, arr, arrSize);
		}
		else {
			OutputArrInConsole(arr,arrSize);
		}
	}
}

//sort

void BubbleSort(double * arr, int32_t arrSize) {
	bool isSwapped = true;
	while (isSwapped == true) {
		isSwapped = false;
		for (int32_t i = {};i < arrSize - 1;++i) {
			if (arr[i] > arr[i + 1]) {
				std::swap(arr[i], arr[i + 1]);
				isSwapped = true;
			}
		}
		arrSize -= 1;
	}
}

void SelectionSort(double * arr, int32_t arrSize) {
	for (int32_t i = {};i < arrSize - 1;++i) {
		int32_t indexOfMin = { i };
		for (int32_t j = { i + 1 };j < arrSize;++j) {
			if (arr[j] < arr[indexOfMin]) {
				indexOfMin = j;
			}
		}
		if (indexOfMin != i) {
			std::swap(arr[i], arr[indexOfMin]);
		}
	}
}

void InsertionSort(double * arr, int32_t arrSize) {
	for (int32_t i = { 1 };i < arrSize;++i) {
		double key = arr[i];
		int32_t j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}

void MergeSort(double * arr, int32_t left, int32_t right) {
	if (left < right) {
		int32_t mid = (left + right) / 2;

		MergeSort(arr, left, mid);

		MergeSort(arr, mid + 1, right);

		Merge(arr, left, mid, right);
	}
}

void Merge(double* arr, int32_t left, int32_t mid, int32_t right) {
	int32_t size1 = mid - left + 1;     
	int32_t size2 = right - mid;        

	double* L = new double[size1];
	double* R = new double[size2];

	for (int32_t i = {}; i < size1; ++i)
		L[i] = arr[left + i];           

	for (int32_t j = {}; j < size2; ++j)
		R[j] = arr[mid + 1 + j];        

	int32_t i = {};
	int32_t j = {};
	int32_t k = { left };

	
	while (i < size1 && j < size2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i]; 
			++i;
		}
		else {
			arr[k] = R[j];
			++j;
		}
		++k; 
	}

	while (i < size1) {
		arr[k] = L[i];
		++i;
		++k;
	}

	while (j < size2) {
		arr[k] = R[j];
		++j;
		++k;
	}

	delete[] L;
	delete[] R;
}

int32_t CountDigitAfterDot(double num) {
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(7) << num;
	std::string str = oss.str();
	int32_t pos = static_cast<int32_t>(str.find('.'));
	if (pos == std::string::npos) {
		return 0;
	}
	int32_t count = str.size() - pos - 1;
	while (count > 0 && str.back() == '0') {
		str.pop_back();
		--count;
	}
	return count;
}

int32_t CompareByFractionDigits(const void* a, const void* b) {
	double da = *(const double*)a;
	double db = *(const double*)b;

	int32_t countA = CountDigitAfterDot(da);
	int32_t countB = CountDigitAfterDot(db);

	return countA - countB;
}


//struct
void InputNumberOfStudents(int32_t& numberOfStudents) {
	std::cout << "Input namber of students\n";
	std::cin >> numberOfStudents;
}

void InputInfoAboutStudents(Student * students,int32_t arrSize) {
	for (int32_t i = {};i < arrSize;++i) {
		std::cout << "Input name of student\n";
		std::cin.ignore();
		getline(std::cin, students[i].name);
		std::cout << "Input surname of student\n";
		getline(std::cin, students[i].surname);
		std::cout << "Input class of student\n";
		getline(std::cin, students[i].clas);
		std::cout << "Input group of student\n";
		getline(std::cin, students[i].group);
		std::cout << "Input 5 marks of student\n";
		for (int32_t j = {};j < 5;++j) {
			std::cout << "input mark namber " << j + 1 << '\n';
			std::cin >> students[i].marks[j];
		}
	}
}

double CountAverageMark(Student & student) {
	double averageMark = {};
	for (int32_t i = {};i < 5;++i) {
		averageMark += student.marks[i];
	}
	return averageMark / 5;
}

void OutputStudent(Student * students,int32_t arrSize) {

	std::cout << "Sorted array By average mark\n";
	for (int32_t i = {};i < arrSize; ++i) {
		std::cout << "Name: " << students[i].name << "\n";
		std::cout << "Surname: " << students[i].surname << "\n";
		std::cout << "Group: " << students[i].group << "\n";
		std::cout << "Class: " << students[i].clas << "\n";
		std::cout << "Marks: ";
		for (int32_t j = {}; j < 5; ++j) {
			std::cout << students[i].marks[j] << " ";
		}
		std::cout << "\n Average mark: " << CountAverageMark(students[i]) << "\n";
	}
}
