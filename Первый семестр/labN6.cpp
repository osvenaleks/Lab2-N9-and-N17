#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdint>


double func1(double x);
double func2(double x);
double func3(double x);


template <typename T>
void InputAccurancy(T& accuracy);

void ChooseMethod(int64_t& methodChoice);

void ChooseFunction(int64_t& indexOfFunction);

void InputNumberOfPartitions(int64_t& n, int64_t methodChoice);

double integrateBySimpson(double (*func)(double), double a, double b, int64_t n);
double integrateByTrapezoid(double (*func)(double), double a, double b, int64_t n);
double integrateByMidRectangles(double (*func)(double), double a, double b, int64_t n);
double integrateByLeftRectangles(double (*func)(double), double a, double b, int64_t n);
double integrateByRightRectangles(double (*func)(double), double a, double b, int64_t n);

void InputIntervals(double& a, double& b, int64_t indexOfFunction, double intervalsA[], double intervalsB[]);

int main() {
    
    double (*functions[])(double) { func1, func2, func3 };
    
    double (*methods[])(double (*func)(double), double, double, int64_t) {
        integrateByLeftRectangles,
            integrateByRightRectangles,
            integrateByMidRectangles,
            integrateByTrapezoid,
            integrateBySimpson
    };

    double intervalsA[]{ 0.0, 0.0, -2.0 };
    double intervalsB[]{ 1.7, 2.0, -1.2 };

    int64_t indexOfFunction{};  
    int64_t methodChoice{};     
   
    ChooseFunction(indexOfFunction);
    ChooseMethod(methodChoice);

    
    double a{}, b{};
    InputIntervals(a, b, methodChoice, intervalsA, intervalsB);

    int64_t n{};  
    InputNumberOfPartitions(n, methodChoice);

    
    double result = { methods[methodChoice](functions[indexOfFunction], a, b, n) };

    
    int64_t accuracy{};
    std::cout << "How many numbers after dots do you want to see?\n";
    InputAccurancy(accuracy);

    
    std::cout << "integrate meaning:= " << std::setprecision(accuracy) << result;

    return 0;
}

void ChooseFunction(int64_t& indexOfFunction) {
    std::cout << "Select the function to calculate (enter the function number):\n";
    std::cout << "0: x * arctan(x)\n";
    std::cout << "1: 1 /4 (1 + sqrt(x))\n";
    std::cout << "2: 2 / (1 - 4 * x)\n";
    std::cin >> indexOfFunction;

    if (indexOfFunction < 0 || indexOfFunction > 2) {
        std::cout << "Invalid function number. Try again.\n";
        return ChooseFunction(indexOfFunction);
    }
}

void ChooseMethod(int64_t& methodChoice) {
    std::cout << "Select the calculation method (enter the method number):\n";
    std::cout << "0: Left Rectangles\n";
    std::cout << "1: Right Rectangles\n";
    std::cout << "2: Midpoint Rectangles\n";
    std::cout << "3: Trapezoid Method\n";
    std::cout << "4: Simpson's Method\n";
    std::cin >> methodChoice;

    if (methodChoice < 0 || methodChoice > 4) {
        std::cout << "Invalid method number. Try again.\n";
        return ChooseMethod(methodChoice);
    }
}

void InputIntervals(double& a, double& b, int64_t indexOfFunction, double intervalsA[], double intervalsB[]) {
    a = { intervalsA[indexOfFunction] };
    b = { intervalsB[indexOfFunction] };
}

void InputNumberOfPartitions(int64_t& n, int64_t methodChoice) {
    std::cout << "Enter the number of partitions:=  ";
    std::cin >> n;

    if (n < 1) {
        std::cout << "Invalid number. Try again.\n";
        return InputNumberOfPartitions(n, methodChoice);
    }
 
    if (n % 2 != 0 && methodChoice == 4) {
        std::cout << "For Simpson method partitions must be even. Try again.\n";
        return InputNumberOfPartitions(n, methodChoice);
    }
}

template <typename T>
void InputAccurancy(T& accuracy) {
    std::cin >> accuracy;
    while (accuracy < 0) {
        std::cout << "Invalid accuracy. Try again.\n";
    }
}

double func1(double x) {
    return x * atan(x);
}

double func2(double x) {
    return 1 / (1 + sqrt(x));
}

double func3(double x) {
    return 2 / (1 - 4 * x);
}

double integrateByLeftRectangles(double (*func)(double), double a, double b, int64_t n) {
    double h{ (b - a) / n };  
    double result{ };
    for (int64_t i{ }; i < n; ++i) {
        result += func(a + i * h);
    }
    result *= h;  
    return result;
}

double integrateByRightRectangles(double (*func)(double), double a, double b, int64_t n) {
    double h{ (b - a) / n };  
    double result{ };
    for (int64_t i{ 1 }; i <= n; ++i) {
        result += func(a + i * h);
    }
    result *= h;  
    return result;
}

double integrateByMidRectangles(double (*func)(double), double a, double b, int64_t n) {
    double accuracy{};  
    std::cout << "Input accuracy for Mid Rectangles Method\n";
    InputAccurancy(accuracy);

    double leftSum = { integrateByLeftRectangles(func,a,b,n) };
    double rightSum = { integrateByLeftRectangles(func,a,b,n) };
    double midSum{};
    while (std::abs(leftSum - rightSum) > accuracy) {
        n *= 2;  
        leftSum = { integrateByLeftRectangles(func,a,b,n) };
        rightSum = { integrateByLeftRectangles(func,a,b,n) };
    }
    midSum = (leftSum + rightSum) / 2.0; 
    return midSum;
}

double integrateByTrapezoid(double (*func)(double), double a, double b, int64_t n) {
    double h = { (b - a) / n };  
    double result = { (func(a) + func(b)) / 2.0 };  
    for (int64_t i = { 1 }; i < n; ++i) {
        result += func(a + i * h);  
    }
    result *= h;  
    return result;
}

double integrateBySimpson(double (*func)(double), double a, double b, int64_t n) {
    double h{ (b - a) / n };  
    double result{ func(a) + func(b) };  
    for (int64_t i{ 1 }; i < n; ++i) {
        double x{ a + i * h };
        result += (i % 2 == 0 ? 2 : 4) * func(x);  
        
    }
    result *= h / 3.0;  
    return result;
}
