#include "calculation_1.h"

void calculation_1(double& x, double a, double b)
{
	if (a != 0)
	{
		if (b != 0)
		{
			x = -b / a;
			std::cout << "\n" << a << "*x = " << -b;
			std::cout << "\nx = " << -b << " / " << a << " = " << x << std::endl;
		}
		else
		{
			x = b / a;
			std::cout << "\n" << a << "*x = " << b;
			std::cout << "\nx = " << b << " / " << a << " = " << x << std::endl;
		}
		std::cout << "\nОтвет: x = " << x << ".\n";
	}
	else if (a == 0 && b != 0)
		std::cout << "\nОтвет: уравнение не имеет корней.\n";
	else
		std::cout << "\nОтвет: x может принимать любое вещественное значение.\n";
}