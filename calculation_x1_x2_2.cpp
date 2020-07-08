#include "calculation_x1_x2_2.h"

void calculation_x1_x2_2(double& x, double& x2, double a, double b, double D)
{
	x = (-b - sqrt(D)) / (2 * a);
	x2 = (-b + sqrt(D)) / (2 * a);
	std::cout << "\nx1 = (-b - D^0.5) / (2*a);" << "\nx2 = (-b + D^0.5) / (2*a);\n";
	if (b > 0 && a > 0)
	{
		std::cout << "\nx1 = (" << -b << " - " << D << "^0.5) / (2*" << a << ")";
		std::cout << " = " << -b - sqrt(D) << " / " << 2 * a << " = " << x << ";";
		std::cout << "\nx2 = (" << -b << " + " << D << "^0.5) / (2*" << a << ")";
		std::cout << " = " << -b + sqrt(D) << " / " << 2 * a << " = " << x2 << ";\n";
	}
	else if (b < 0 && a > 0)
	{
		std::cout << "\nx1 = (-(" << b << ") - " << D << "^0.5) / (2*" << a << ")";
		std::cout << " = " << -b - sqrt(D) << " / " << 2 * a << " = " << x << ";";
		std::cout << "\nx2 = (-(" << b << ") + " << D << "^0.5) / (2*" << a << ")";
		std::cout << " = " << -b + sqrt(D) << " / " << 2 * a << " = " << x2 << ";\n";
	}
	else if (b > 0 && a < 0)
	{
		std::cout << "\nx1 = (" << -b << " - " << D << "^0.5) / (2*(" << a << "))";
		std::cout << " = " << -b - sqrt(D) << " / (" << 2 * a << ") = " << x << ";";
		std::cout << "\nx2 = (" << -b << " + " << D << "^0.5) / (2*(" << a << "))";
		std::cout << " = " << -b + sqrt(D) << " / (" << 2 * a << ") = " << x2 << ";\n";
	}
	else if (b < 0 && a < 0)
	{
		std::cout << "\nx1 = (-(" << b << ") - " << D << "^0.5) / (2*(" << a << "))";
		std::cout << " = " << -b - sqrt(D) << " / (" << 2 * a << ") = " << x << ";";
		std::cout << "\nx2 = (-(" << b << ") + " << D << "^0.5) / (2*(" << a << "))";
		std::cout << " = " << -b + sqrt(D) << " / (" << 2 * a << ") = " << x2 << ";\n";
	}
	std::cout << "\nОтвет: x1 = " << x << "; x2 = " << x2 << ".\n";
}