#include "calculation_x_2.h"

void calculation_x_2(double& x, double a, double b, double c)
{
	if (a != 0)
	{
		x = -b / (2 * a);
		std::cout << "\nx = -b / (2*a);";
	}
	if (b > 0 && a > 0)
	{
		std::cout << "\nx = -" << b << " / (2*" << a << ")";
		std::cout << " = -" << b << " / " << 2 * a << " = " << x << ";\n";
	}
	else if (b < 0 && a > 0)
	{
		std::cout << "\nx = -(" << b << ") / (2*" << a << ")";
		std::cout << " = " << -b << " / " << 2 * a << " = " << x << ";\n";
	}
	else if (b > 0 && a < 0)
	{
		std::cout << "\nx = -" << b << " / (2*(" << a << "))";
		std::cout << " = -" << b << " / (" << 2 * a << ") = " << x << ";\n";
	}
	else if (b < 0 && a < 0)
	{
		std::cout << "\nx = -(" << b << ") / (2*(" << a << "))";
		std::cout << " = " << -b << " / (" << 2 * a << ") = " << x << ";\n";
	}
	else
		std::cout << "\nx = 0\n";
	std::cout << "Ответ: x = " << x << ".\n";
}