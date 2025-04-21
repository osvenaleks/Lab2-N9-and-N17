// программа находящая совершенные числа на промежутке
#include <iostream>
#include <cstdint> 

void InputRange(int64_t& a, int64_t& b);
bool IsPositive(int64_t a, int64_t b);
bool IsPerfectNumber(int64_t number);
void FindPerfectNumbersInRange(int64_t a, int64_t b);

int main() {
    int64_t a{};
    int64_t b{};
    InputRange(a, b);
    if (IsPositive(a, b) == false) {
        std::cout << "Incorrect a and b\n";
        return 0;
    }
    else {
        FindPerfectNumbersInRange(a, b);
    }


    return 0;
}
//функция на ввод промежутка
void InputRange(int64_t& a, int64_t& b) {
    std::cout << "Enter the range [a, b]:\n";
    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;

    if (a > b) {     //если a > b то скорее всего пользователь перепутал и программа сама подправит
        std::swap(a, b);
    }
}

//Проверка на неотрицательность
bool IsPositive(int64_t a, int64_t b) {
    return a >= 0 && b >= 0;
}

//Функция проверяющая является ли число совершенным
bool IsPerfectNumber(int64_t number) {
    if (number < 2) { //числа меньшие 2 не подходят под определение соворшенных
        return false;
    }
    //работает по тому же принципу что и в номере 9
    int64_t sumOfDivisors{ 1 };
    for (int64_t i{ 2 }; i * i <= number; ++i) {
        if (number % i == 0) {
            sumOfDivisors += i;
            if (i != number / i) {
                sumOfDivisors += number / i;
            }
        }
    }
    //если сумма собственных натуральных делителей равна числу то оно совершенное
    return sumOfDivisors == number;
}

//функция для нахождения совершенных чисел на промежутке
void FindPerfectNumbersInRange(int64_t a, int64_t b) {
    bool found{ false };//ставим флаг
    std::cout << "Perfect numbers in the range [" << a << ", " << b << "]:\n";
    for (a; a <= b; ++a) { //если находим на промежутке совершенное число ты выводим его
        if (IsPerfectNumber(a)) {
            std::cout << a << " ";
            found = true;
        }
    }
    //если не нашли совершенных чисел пишем результат
    if (!found) {
        std::cout << "No perfect numbers found.\n";
    }
}

