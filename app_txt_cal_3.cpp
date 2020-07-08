#include "app_txt_cal_3.h"

void app_txt_cal_3(double a, double b, double c, double& d)
{
	double disc, q, r, dum1, s, t, term1, r13, x1_real, x2_real, x3_real, x2_imag, x3_imag;
	q = (3.0 * c - (b * b)) / 9.0;
	r = -(27.0 * d) + b * (9.0 * c - 2.0 * (b * b)), r /= 54.0;
	disc = q * q * q + r * r;
	term1 = (b / 3.0);
	if (a != 1)
	{
		str.app("\nТак как коэф. \"a\" не равняется 1, то:\n");
		str.app("b = b / a = ");
		str.app_num(b);
		str.app(" / ");
		str.app_num(a);
		str.app(" = ");
		str.app_num(b);
		str.endl();
		str.app("c = c / a = ");
		str.app_num(c);
		str.app(" / ");
		str.app_num(a);
		str.app(" = ");
		str.app_num(c);
		str.endl();
		str.app("d = d / a = ");
		str.app_num(d);
		str.app(" / ");
		str.app_num(a);
		str.app(" = ");
		str.app_num(d);
		str.endl();
	}
	str.app("\nЧтобы расчитать корнии, нужно вычислить следуюшие значения: Q = (b^2-3*c)/9, R = (2*b^3-9*b*c+27*d)/54.\n");
	str.app("Q = ");
	str.app_num(q);
	str.app("\nR = ");
	str.app_num(r);
	str.app("\n\nДалее заводим следующий параметр D (дискриминант кубического уравнения), который вычисляется по формуле:\nD = Q^3 + R^2\n");
	str.app("При D > 0 имеется один действительный корень и два комплексных. При D <= 0 все корни действительные.\nD = ");
	str.app_num(disc);
	str.app("\n\nДобавим ещё один параметр Ter (промежуточное значение): Ter = b / 3\nTer = ");
	str.app_num(term1);
	if (disc > 0)
	{
		s = r + sqrt(disc);
		s = s < 0 ? -cbrt(-s) : cbrt(s);
		str.app("\n\nТак как D > 0, то для вычисление x понадобится ещё два параметра S и T\n");
		str.app("S = (R + D^(1/2))^(1/3) = ");
		str.app_num(s);
		t = r - sqrt(disc);
		t = t < 0 ? -cbrt(-t) : cbrt(t);
		str.app("\nT = (R - D^(1/2))^(1/3) = ");
		str.app_num(t);
		str.app("\n\nВычисление действительного корня:");
		x1_real = -term1 + s + t;
		str.app("\nx1 = -Ter + S + T = ");
		str.app_num(x1_real);
		term1 += (s + t) / 2.0;
		str.app("\n\nВычисление комплексных корней:\nTer = Ter + (S + T) / 2 = ");
		str.app_num(term1);
		str.app(";");
		if (term1 == 0)
			x3_real = x2_real = term1;
		else
			x3_real = x2_real = -term1;
		str.app("\nx2_r = x3_r = -Ter = ");
		str.app_num(x2_real);
		term1 = sqrt(3.0) * (-t + s) / 2;
		str.app("\nTer  = 3^(1/2)*(-T + S) / 2 = ");
		str.app_num(term1);
		str.app(";");
		x2_imag = term1, x3_imag = -term1;
		str.app("\nx2_i = ");
		str.app_num(x2_imag);
		str.app("\nx3_i = ");
		str.app_num(x3_imag);
		str.endl();
	}
	else if (disc == 0)
	{
		str.app("\n\nТак как D = 0, то комплексная часть равна 0.\n");
		x3_imag = x2_imag = 0;
		str.app("\nx2_i = 0; x3_i = 0;\n");
		r13 = r < 0 ? -cbrt(-r) : cbrt(r);
		str.app("\nВведём временную переменную t.\nt = R^(1/3) = ");
		str.app_num(r13);
		str.app(";\n");
		x1_real = -term1 + 2.0 * r13;
		str.app("\nx1 = -Ter + 2*t = ");
		str.app_num(x1_real);
		str.app(";\n");
		x3_real = x2_real = -(r13 + term1);
		str.app("x2 = -(t + Ter) = ");
		str.app_num(x2_real);
		str.app(";\nx3 = -(t + Ter) = ");
		str.app_num(x3_real);
		str.app(";\n");
	}
	else
	{
		str.app("\n\nТак как D < 0, то комплексная часть равна 0 и все корни различны.\n");
		x3_imag = x2_imag = 0;
		str.app("\nx2_i = 0; x3_i = 0;\n");
		q = -q;
		str.app("Q = -Q;\n");
		dum1 = q * q * q;
		dum1 = acos(r / sqrt(dum1));
		r13 = 2.0 * sqrt(q);
		str.app("\nДобавим две переменные Dum и t:\nt = 2*R^(1/2) = ");
		str.app_num(r13);
		str.app(";\nDum = arccos(t / Q^3) = ");
		str.app_num(dum1);
		str.app(";\n");
		x1_real = -term1 + r13 * cos(dum1 / 3.0);
		str.app("\nx1 = -Ter + t * cos(Dum / 3) = ");
		str.app_num(x1_real);
		str.app(";\n");
		x2_real = -term1 + r13 * cos((dum1 + 2.0 * M_PI) / 3.0);
		str.app("x2 = -Ter + t * cos(Dum  + 2*PI) / 3 = ");
		str.app_num(x2_real);
		str.app(";\n");
		x3_real = -term1 + r13 * cos((dum1 + 4.0 * M_PI) / 3.0);
		str.app("x3 = -Ter + t * cos(Dum + 4*PI) / 3 = ");
		str.app_num(x3_real);
		str.app(";\n");
	}
	if (x2_imag != 0 && x3_imag != 0)
	{
		str.app("\nОтвет: x1 = ");
		str.app_num(x1_real);
		str.app("; x2 = ");
		str.app_num(x2_real);
		str.app(" + ");
		str.app_num(x2_imag);
		str.app("*i; x3 = ");
		str.app_num(x3_real);
		str.app(" + ");
		str.app_num(x3_imag);
		str.app("*i.\n\r");
	}
	else
	{
		str.app("\nОтвет: x1 = ");
		str.app_num(x1_real);
		str.app("; x2 = ");
		str.app_num(x2_real);
		str.app("; x3 = ");
		str.app_num(x3_real);
		str.app(".\n\r");
	}
}