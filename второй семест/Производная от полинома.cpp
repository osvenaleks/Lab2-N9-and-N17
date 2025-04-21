#include <iostream>
void AutputArray(double* arr, int32_t degree)
{
	const int32_t counter = degree + 1;
	for (int32_t i = {};i < counter;++i) {
		if (arr[i] != 0)
		{
			if (i != 0)
			{
				if (arr[i] < 0)
				{
					std::cout << "- ";
				}
				else
				{
					std::cout << "+ ";

				}
				if (arr[i] != 1 && arr[i] != -1)
				{
					std::cout << abs(arr[i]);
				}
			}
			else
			{
				std::cout << arr[i];
			}
			if (degree == 1)
			{
				std::cout << "x ";
			}
			else if (degree == 0)
			{
				std::cout << ' ';
			}
			else
			{
				std::cout << "x^" << degree << ' ';
			}

		}
		degree -= 1;
	}
}

void FindDerivativePolinom(double* arr, const int32_t degree) {
	double* dereviate = new double[degree];
	for (int32_t i = { degree };i > 0; --i) {
		dereviate[i - 1] = i * arr[i];
	} 
	AutputArray(dereviate, degree - 1);
	}

