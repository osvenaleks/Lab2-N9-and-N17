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

void Inputlimit(int64_t& N) {
    std::cout << "Input limit for Pihagorean triples\n";
    std::cin >> N;


}

int64_t gcd(int64_t m, int64_t n) {
    while (n != 0) {
        int64_t temp{ n };
        n = { m % n };
        m = { temp };
    }
    return m;
}

void FindPythagoreanTriples(int64_t N) {
    std::cout << "Pythagorean triples up to " << N << ":\n";

    for (int64_t m{1}; m * m <= N; ++m) { 
        for (int64_t n{1}; n < m; ++n) {
            if ((m - n) % 2 == 1 && gcd(m, n) == 1) {
                
                int64_t a{ m * m - n * n };
                int64_t b{ 2 * m * n };
                int64_t c{ m * m + n * n };
                
                for (int64_t k{ 1 }; k * c <= N; ++k) {
                    
                        std::cout << "(" << k * a << ", " << k * b << ", " << k * c << ")\n";
                }
            }
        }
    }
}
