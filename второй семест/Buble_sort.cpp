#include<iostream>

void BubleSort(int64_t* arr, int32_t arrSize) {
	for (int32_t i = {};i + 1 < arrSize;++i) {
		for (int32_t j = {}; j + 1 < arrSize - i;++j) {
		if (arr[j] < arr[j + 1]){ 
		std::swap(arr[j], arr[j + 1]);
		}
	}


}

