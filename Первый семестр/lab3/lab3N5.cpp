
#include <iostream>
#include<cstdint> 

void InputNumber(int64_t& N);
bool IsNatural(int64_t N);
void NextNumFib(int64_t& firstNumberFibanachi, int64_t& secondNumberFibanachi);
void CountSumOfFibanachiLessThenN(int64_t& FirstNumFib, int64_t& SecondNumFib, int64_t N);

int main() {
    int64_t N{};
    int64_t FirstNumberFibanachi{ 1 };
    int64_t NextNumberFibanachi{ 1 };

    InputNumber(N);

    if (!IsNatural(N)) {
        std::cout << "Incorrect N\n";
        return 0;
    }
    else {
        CountSumOfFibanachiLessThenN(FirstNumberFibanachi, NextNumberFibanachi, N);
    }

    return 0;
}

 void InputNumber(int64_t& N) {
    std::cout << "Input Number: ";
    std::cin >> N;
}

 bool IsNatural(int64_t N) {
    return N >= 0;
}

void NextNumFib(int64_t& firstNumberFibanachi, int64_t& nextNumFib) {
    std::swap(firstNumberFibanachi, nextNumFib);
    nextNumFib += firstNumberFibanachi;
}

void CountSumOfFibanachiLessThenN(int64_t& firstNumberFibanachi, int64_t& nextNumberFibanachi, int64_t N) {
    int64_t sumFibanachi{1};
    while (sumFibanachi + nextNumberFibanachi <= N) { 
        sumFibanachi += nextNumberFibanachi;
        NextNumFib(firstNumberFibanachi, nextNumberFibanachi);
    }
    std::cout << "Sum of Fibonacci numbers not bigger than " << N << ": " << sumFibanachi << "\n";

}