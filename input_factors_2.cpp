#include "input_factors_2.h"

void input_factors_2(double& a, double& b, double& c)
{
	std::cout << "��������� ����: a*x^2 + b*x + c = 0\n";
	std::cout << "������� ����������� \'a\': ";
	a = input_num();
	std::cout << "\n������� ����������� \'b\': ";
	b = input_num();
	std::cout << "\n������� ����������� \'c\': ";
	c = input_num();
	SetColor(Cyan, Black);
	std::cout << "\n\n" << a << "*x^2 ";
	if (b >= 0)
		std::cout << "+ " << b << "*x ";
	else
		std::cout << "- " << -b << "*x ";
	if (c >= 0)
		std::cout << "+ " << c << " = 0\n";
	else
		std::cout << "- " << -c << " = 0\n";
}