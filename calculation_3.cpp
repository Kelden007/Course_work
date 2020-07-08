#include "calculation_3.h"

void calculation_3(double& a, double& b, double& c, double& d)
{
	b_old = b, c_old = c, d_old = d;
	if (a != 1)
	{
		std::cout << "\n��� ��� ����. \"a\" �� ��������� 1, ��:\n";
		std::cout << "b = b / a = " << b << " / " << a << " = ";
		b /= a, std::cout << b << std::endl;
		std::cout << "c = c / a = " << c << " / " << a << " = ";
		c /= a, std::cout << c << std::endl;
		std::cout << "d = d / a = " << d << " / " << a << " = ";
		d /= a, std::cout << d << std::endl;
	}
	double disc, q, r, dum1, s, t, term1, r13;
	std::cout << "\n����� ��������� ������, ����� ��������� ��������� ��������: Q = (b^2-3*c)/9, R = (2*b^3-9*b*c+27*d)/54.\n";
	q = (3.0 * c - (b * b)) / 9.0;
	std::cout << "Q = " << q;
	r = -(27.0 * d) + b * (9.0 * c - 2.0 * (b * b));
	r /= 54.0;
	std::cout << "\nR = " << r;
	disc = q * q * q + r * r;
	std::cout << "\n\n����� ������� ��������� �������� D (������������ ����������� ���������), ������� ����������� �� �������:\nD = Q^3 + R^2\n";
	std::cout << "��� D > 0 ������� ���� �������������� ������ � ��� �����������. ��� D <= 0 ��� ����� ��������������.\nD = " << disc;
	term1 = (b / 3.0);
	std::cout << "\n\n������� ��� ���� �������� Ter (������������� ��������): Ter = b / 3\nTer = " << term1;

	double x1_real, x2_real, x3_real, x2_imag, x3_imag;
	if (disc > 0)   // ���� ������ ��������������, ��� �����������
	{
		std::cout << "\n\n��� ��� D > 0, �� ��� ���������� x ����������� ��� ��� ��������� S � T\n";
		s = r + sqrt(disc);
		s = s < 0 ? -cbrt(-s) : cbrt(s);
		std::cout << "S = (R + D^(1/2))^(1/3) = " << s;
		t = r - sqrt(disc);
		t = t < 0 ? -cbrt(-t) : cbrt(t);
		std::cout << "\nT = (R - D^(1/2))^(1/3) = " << t << "\n\n���������� ��������������� �����:";
		x1_real = -term1 + s + t;
		std::cout << "\nx1 = -Ter + S + T = " << x1_real;
		term1 += (s + t) / 2.0;
		std::cout << "\n\n���������� ����������� ������:\nTer = Ter + (S + T) / 2 = " << term1 << ";";
		if (term1 == 0)
			x3_real = x2_real = term1;
		else
			x3_real = x2_real = -term1;
		std::cout << "\nx2_r = x3_r = -Ter = " << x2_real;
		term1 = sqrt(3.0) * (-t + s) / 2;
		std::cout << "\nTer  = 3^(1/2)*(-T + S) / 2 = " << term1 << ";";
		x2_imag = term1;
		x3_imag = -term1;
		std::cout << "\nx2_i = " << x2_imag << "\nx3_i = " << x3_imag << std::endl;
	}
	// ��������� ����� ��������������
	else if (disc == 0)  // ��� ����� ������������� � ��� �����
	{
		std::cout << "\n\n��� ��� D = 0, �� ����������� ����� ����� 0.\n";
		x3_imag = x2_imag = 0;
		std::cout << "\nx2_i = 0; x3_i = 0;\n";
		r13 = r < 0 ? -cbrt(-r) : cbrt(r);
		std::cout << "\n����� ��������� ���������� t.\nt = R^(1/3) = " << r13 << ";\n";
		x1_real = -term1 + 2.0 * r13;
		std::cout << "\nx1 = -Ter + 2*t = " << x1_real << ";\n";
		x3_real = x2_real = -(r13 + term1);
		std::cout << "x2 = -(t + Ter) = " << x2_real << ";\nx3 = -(t + Ter) = " << x3_real << ";\n";
	}
	// ������������ ���������� ������� - ��� ����� ������������� � ������� (����� ������� ����, q < 0)
	else
	{
		std::cout << "\n\n��� ��� D < 0, �� ����������� ����� ����� 0 � ��� ����� ��������.\n";
		x3_imag = x2_imag = 0;
		std::cout << "\nx2_i = 0; x3_i = 0;\n";
		q = -q;
		std::cout << "Q = -Q;\n";
		dum1 = q * q * q;
		dum1 = acos(r / sqrt(dum1));
		r13 = 2.0 * sqrt(q);
		std::cout << "\n������� ��� ���������� Dum � t:\nt = 2*R^(1/2) = " << r13 << ";\nDum = arccos(t / Q^3) = " << dum1 << ";\n";
		x1_real = -term1 + r13 * cos(dum1 / 3.0);
		std::cout << "\nx1 = -Ter + t * cos(Dum / 3) = " << x1_real << ";\n";
		x2_real = -term1 + r13 * cos((dum1 + 2.0 * M_PI) / 3.0);
		std::cout << "x2 = -Ter + t * cos(Dum  + 2*PI) / 3 = " << x2_real << ";\n";
		x3_real = -term1 + r13 * cos((dum1 + 4.0 * M_PI) / 3.0);
		std::cout << "x3 = -Ter + t * cos(Dum + 4*PI) / 3 = " << x3_real << ";\n";
	}
	if (x2_imag != 0 && x3_imag != 0)
		std::cout << "\n�����: x1 = " << x1_real << "; x2 = " << x2_real << " + " << x2_imag << "*i; x3 = " << x3_real << " + " << x3_imag << "*i.\n";
	else
		std::cout << "\n�����: x1 = " << x1_real << "; x2 = " << x2_real << "; x3 = " << x3_real << ".\n";
}