#include "calculation_dis.h"

void calculation_dis(double& D, double a, double b, double c)
{
	D = pow(b, 2) - 4 * a * c;
	std::cout << "\nD = b^2 - 4*a*c;\n";
	if (b > 0 && a > 0 && c > 0)
		std::cout << "D = " << b << "^2 - 4*" << a << "*" << c << " = " << pow(b, 2) << " - " << 4 * a * c << " = " << D << ";\n";
	else if (b > 0 && a < 0 && c > 0)
		std::cout << "D = " << b << "^2 - 4*(" << a << ")*" << c << " = " << pow(b, 2) << " - (" << 4 * a * c << ") = " << D << ";\n";
	else if (b > 0 && a > 0 && c < 0)
		std::cout << "D = " << b << "^2 - 4*" << a << "*(" << c << ") = " << pow(b, 2) << " - (" << 4 * a * c << ") = " << D << ";\n";
	else if (b > 0 && a < 0 && c < 0)
		std::cout << "D = " << b << "^2 - 4*(" << a << ")*(" << c << ") = " << pow(b, 2) << " - " << 4 * a * c << " = " << D << ";\n";

	else if (b < 0 && a > 0 && c > 0)
		std::cout << "D = (" << b << ")^2 - 4*" << a << "*" << c << " = " << pow(b, 2) << " - " << 4 * a * c << " = " << D << ";\n";
	else if (b < 0 && a < 0 && c > 0)
		std::cout << "D = (" << b << ")^2 - 4*(" << a << ")*" << c << " = " << pow(b, 2) << " - (" << 4 * a * c << ") = " << D << ";\n";
	else if (b < 0 && a > 0 && c < 0)
		std::cout << "D = (" << b << ")^2 - 4*" << a << "*(" << c << ") = " << pow(b, 2) << " - (" << 4 * a * c << ") = " << D << ";\n";
	else if (b < 0 && a < 0 && c < 0)
		std::cout << "D = (" << b << ")^2 - 4*(" << a << ")*(" << c << ") = " << pow(b, 2) << " - " << 4 * a * c << " = " << D << ";\n";
}