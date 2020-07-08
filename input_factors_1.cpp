#include "input_factors_1.h"

void input_factors_1(double& a, double& b)
{
	std::cout << "Уравнение вида: a*x + b = 0\n";
	std::cout << "Введите коэффициент \'a\': ";
	a = input_num();
	std::cout << "\nВведите коэффициент \'b\': ";
	b = input_num();
	SetColor(Cyan, Black);
	std::cout << "\n\n" << a << "*x ";
	if (b >= 0)
		std::cout << "+ " << b << " = 0\n";
	else
		std::cout << "- " << -b << " = 0\n";
}