#include "calculation_x1i_x2i_2.h"

void calculation_x1i_x2i_2(double& x_real, double a, double b, double D, double& x1_i, double& x2_i)
{
	std::cout << "D = " << abs(D) << "*i^2 (где i - это мнимая единица, квадрат которой равняется -1)";
	x_real = -b / (2 * a);
	x1_i = sqrt(abs(D)) / (2 * a);
	x2_i = -sqrt(abs(D)) / (2 * a);
	std::cout << "\nx1_i = (-b - D^0.5) / (2*a);";
	std::cout << "\nx2_i = (-b + D^0.5) / (2*a);\n";
	if (b > 0 && a > 0)
	{
		std::cout << "\nx1_i = (" << -b << " + (" << abs(D) << "*i^2)^0.5) / (2*" << a << ")";
		std::cout << " = " << x_real << " + " << x1_i << "*i;";
		std::cout << "\nx2_i = (" << -b << " - (" << abs(D) << "*i^2)^0.5) / (2*" << a << ")";
		std::cout << " = " << x_real << " - " << abs(x2_i) << "*i.";
	}
	else if (b < 0 && a > 0)
	{
		std::cout << "\nx1_i = (-(" << b << ") + (" << abs(D) << "*i^2)^0.5) / (2*" << a << ")";
		std::cout << " = " << x_real << " + " << x1_i << "*i;";
		std::cout << "\nx2_i = (-(" << b << ") - (" << abs(D) << "*i^2)^0.5) / (2*" << a << ")";
		std::cout << " = " << x_real << " - " << abs(x2_i) << "*i.";
	}
	else if (b > 0 && a < 0)
	{
		std::cout << "\nx1_i = (" << -b << " + (" << abs(D) << "*i^2)^0.5) / (2*(" << a << "))";
		std::cout << " = " << x_real << " + " << x1_i << "*i;";
		std::cout << "\nx2_i = (" << -b << " - (" << abs(D) << "*i^2)^0.5) / (2*(" << a << "))";
		std::cout << " = " << x_real << " - " << abs(x2_i) << "*i.";
	}
	else if (b < 0 && a < 0)
	{
		std::cout << "\nx1_i = (-(" << b << ") + (" << abs(D) << "*i^2)^0.5) / (2*(" << a << "))";
		std::cout << " = " << x_real << " + " << x1_i << "*i;";
		std::cout << "\nx2_i = (-(" << b << ") - (" << abs(D) << "*i^2)^0.5) / (2*(" << a << "))";
		std::cout << " = " << x_real << " - " << abs(x2_i) << "*i.";
	}
	std::cout << "\nОтвет: x1_i = " << x_real << " + " << x1_i << "*i; x2_i = " << x_real << " - " << abs(x2_i) << "*i.\n";
}