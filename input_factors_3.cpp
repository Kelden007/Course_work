#include "input_factors_3.h"

void input_factors_3(double& a, double& b, double& c, double& d)
{
	std::cout << "Уравнение вида: a*x^3 + b*x^2 + c*x + d = 0\n";
	std::cout << "Введите коэффициент \'a\': ";
	a = input_num();
	std::cout << "\nВведите коэффициент \'b\': ";
	b = input_num();
	std::cout << "\nВведите коэффициент \'c\': ";
	c = input_num();
	std::cout << "\nВведите коэффициент \'d\': ";
	d = input_num();
	SetColor(Cyan, Black);
	std::cout << "\n\n" << a << "*x^3 ";
	if (b >= 0)
		std::cout << "+ " << b << "*x^2 ";
	else
		std::cout << "- " << -b << "*x^2 ";
	if (c >= 0)
		std::cout << "+ " << c << "*x ";
	else
		std::cout << "- " << -c << "*x ";
	if (d >= 0)
		std::cout << "+ " << d << " = 0\n";
	else
		std::cout << "- " << -d << " = 0\n";
}