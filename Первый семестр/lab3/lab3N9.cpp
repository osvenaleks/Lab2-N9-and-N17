//программа котора€ находит число дружественное и не превышающее число N
#include <iostream>
#include <cstdint>

void InputNumber(int64_t& N);
int64_t sumOfDivisors(int64_t N);
void FindFriendlyNumbers(int64_t N);

int main() {
    int64_t N{};

    InputNumber(N);

    FindFriendlyNumbers(N);

    return 0;
}

//функци€ дл€ ввода числа дл€ которого будем искать дружелюбное
void InputNumber(int64_t& N) {
    std::cout << "Enter the number N: ";
    std::cin >> N;
}

//функци€ котора€ находит сумму делителей числа N
int64_t sumOfDivisors(int64_t N) {
    int64_t sum{ 1 }; //добавили единицу в сумму заранее чтобы в псоледующем коде в сумму не добавилось само наше число N,по условию оно не должно учитыватьс€
    for (int64_t i{ 2 }; i * i <= N; i++) { //до квадрата потомучто после его числа повтор€ютс€
        if (N % i == 0) {   // если делитель добовл€ем в сумму
            sum += i;
            if (i != N / i) { // если делитель не равен частному то добавл€ем частное
                sum += N / i; 
            }
        }
    }
    return sum;
}

//функци€ котора€ находит число дружественное и не прывышащее N
void FindFriendlyNumbers(int64_t N) {
    bool foundFriendly = false; //ставим флаг

    for (int64_t i{ 1 }; i < N; ++i) {
        if (sumOfDivisors(i) == N) {
            std::cout << "Friendly number for " << N << ": " << i << "\n";
            foundFriendly = true;
        }
    }
    //если не находит дружественных чисел то сообщает об этом
    if (!foundFriendly) {
        std::cout << "There are no friendly numbers less than " << N << " for " << N << ".\n";
    }
}
