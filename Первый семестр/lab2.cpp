#include <iostream>
#include <cstdint>
#include <iomanip>


void InputX(double& x);
void InputK(int32_t& k);
bool IsValidPrecision(int32_t k);
double NormalizeAngle(double x);
double CalculateCos(double x, int32_t k);


int main() {
    double x; // Угол в радианах
    int32_t k; // Количество знаков после запятой

    
    InputX(x);
    InputK(k);

    if (!IsValidPrecision(k)) {
        std::cout << "Error: Precision (k) must be a positive value.\n";
        return 0;
    }

    x = NormalizeAngle(x);

    double result = CalculateCos(x, k);

    std::cout << std::fixed << std::setprecision(k) << "cos(" << x << ") = " << result << "\n";

    return 0;
}

void InputX(double& x) {
    std::cout << "Enter the value of x (in radians): ";
    std::cin >> x;
}

void InputK(int32_t& k) {
    std::cout << "Enter the desired precision (number of decimal places): ";
    std::cin >> k;
}

bool IsValidPrecision(int32_t k) {
    return k > 0;
}

double NormalizeAngle(double x) {
    const double twoPi = 2.0 * 3.14159;

    while (x >= twoPi) {
        x -= twoPi;
    }
    while (x < 0) {
        x += twoPi;
    }

    return x;
}

double CalculateCos(double x, int32_t k) {
    double cosValue{ 1.0 }; 
    double term{ 1.0 }; 
    int32_t n{  }; 

    double threshold = 1.0; 
    for (int32_t i{ }; i < k; ++i) {
        threshold *= 0.1; 
    }

    while (term > threshold || term < -threshold) {
        term *= -1.0 * x * x / ((2 * n + 1) * (2 * n + 2)); 
        cosValue += term; 
        n++;
    }

    return cosValue;
}
