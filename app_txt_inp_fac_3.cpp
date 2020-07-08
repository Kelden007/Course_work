#include "app_txt_inp_fac_3.h"

void app_txt_inp_fac_3(double a, double b, double c, double d)
{
	str.app("Уравнение вида: a*x^3 + b*x^2 + c*x + d = 0\n");
	str.app("Введите коэффициент \'a\': ");
	str.app_num(a);
	str.endl();
	str.app("Введите коэффициент \'b\': ");
	str.app_num(b);
	str.endl();
	str.app("Введите коэффициент \'c\': ");
	str.app_num(c);
	str.endl();
	str.app("Введите коэффициент \'d\': ");
	str.app_num(d);
	str.endl();
	str.endl();
	str.app_num(a);
	str.app("*x^3 ");
	if (b >= 0)
	{
		str.app("+ ");
		str.app_num(b);
		str.app("*x^2 ");
	}
	else
	{
		str.app("- ");
		str.app_num(-b);
		str.app("*x^2 ");
	}
	if (c >= 0)
	{
		str.app("+ ");
		str.app_num(c);
		str.app("*x ");
	}
	else
	{
		str.app("- ");
		str.app_num(-c);
		str.app("*x ");
	}
	if (d >= 0)
	{
		str.app("+ ");
		str.app_num(d);
		str.app(" = 0\n");
	}
	else
	{
		str.app("- ");
		str.app_num(-d);
		str.app(" = 0\n");
	}
}