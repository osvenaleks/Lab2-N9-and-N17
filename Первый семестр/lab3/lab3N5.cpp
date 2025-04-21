//Программа которая считает сумму чисел фибоначчи до определенного числа N
#include <iostream>
#include<cstdint> //для того чтобы тип int определенной разрядности воспринимался на разных платформах(кроссплатформенность)
//Прототипы функций
void InputNumber(int64_t& N);//работало бы корректно и при  int64_t* N
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

//функция для ввода числа 
 void InputNumber(int64_t& N) {
    std::cout << "Input Number: ";
    std::cin >> N;
}

 //Проверка на неотрицательность
 bool IsNatural(int64_t N) {
    return N >= 0;
}

 //переходит к следующей паре чисел фибоначчи,пример: из первого и второго числа фибоначи к второму и третьему
void NextNumFib(int64_t& firstNumberFibanachi, int64_t& nextNumFib) {
    std::swap(firstNumberFibanachi, nextNumFib);
    nextNumFib += firstNumberFibanachi;
}
//Функция которая считает сумму чиселфибоначчи не превышающую число N
void CountSumOfFibanachiLessThenN(int64_t& firstNumberFibanachi, int64_t& nextNumberFibanachi, int64_t N) {
    int64_t sumFibanachi{1};
    while (sumFibanachi + nextNumberFibanachi <= N) { //Проверяет:если мы к нашей сумме добавим следующий элемент фтбоначчи, он не будет превышать число N?
        sumFibanachi += nextNumberFibanachi;
        NextNumFib(firstNumberFibanachi, nextNumberFibanachi);
    }
    std::cout << "Sum of Fibonacci numbers not bigger than " << N << ": " << sumFibanachi << "\n";//Вывод конечного результата

}