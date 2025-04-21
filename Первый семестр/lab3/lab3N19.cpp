//программа для нахождения пифогоровфх троек меньших за N
#include <cstdint>
#include <iostream>

void Inputlimit(int64_t& N);
void FindPythagoreanTriples(int64_t N);
int64_t gcd(int64_t m, int64_t n);

int main() {
    int64_t N;

    Inputlimit(N);

    FindPythagoreanTriples(N);

    return 0;
}
//функция для ввода лимита для чисел пифагоровых троек
void Inputlimit(int64_t& N) {
    std::cout << "Input limit for Pihagorean triples\n";
    std::cin >> N;


}

//Функция для нахлждения НОД чисел по алгоритму евклида
int64_t gcd(int64_t m, int64_t n) {
    while (n != 0) {
        int64_t temp{ n };
        n = { m % n };
        m = { temp };
    }
    return m;
}
//функция для нахождения пифагоровых троек до N,перебором не еффективно поэтому буду использовать формулу Еклида
void FindPythagoreanTriples(int64_t N) {
    std::cout << "Pythagorean triples up to " << N << ":\n";

    for (int64_t m{1}; m * m <= N; ++m) { //по формуле для нахождения простых пифогоровых троек нам надо натуральные числа m и n такие что m < n их НОД = 1 и ещё они разной четности
        for (int64_t n{1}; n < m; ++n) {
            if ((m - n) % 2 == 1 && gcd(m, n) == 1) {
                //если условия соблюдены то числа a,d,c имеют такую формулу
                int64_t a{ m * m - n * n };
                int64_t b{ 2 * m * n };
                int64_t c{ m * m + n * n };
                //чтобы получить все остальные пифогоровы тройки нам нужно домножить a,b,c на натуральное k
                for (int64_t k{ 1 }; k * c <= N; ++k) {
                    
                        std::cout << "(" << k * a << ", " << k * b << ", " << k * c << ")\n";
                }
            }
        }
    }
}
