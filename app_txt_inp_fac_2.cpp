#include "app_txt_inp_fac_2.h"

void app_txt_inp_fac_2(double a, double b, double c)
{
	str.app("Уравнение вида: a*x^2 + b*x + c = 0\n");
	str.app("Введите коэффициент \'a\': ");
	str.app_num(a);
	str.endl();
	str.app("Введите коэффициент \'b\': ");
	str.app_num(b);
	str.endl();
	str.app("Введите коэффициент \'c\': ");
	str.app_num(c);
	str.endl();
	str.endl();
	str.app_num(a);
	str.app("*x^2 ");
	if (b >= 0)
	{
		str.app("+ ");
		str.app_num(b);
		str.app("*x ");
	}
	else
	{
		str.app("- ");
		str.app_num(-b);
		str.app("*x ");
	}
	if (c >= 0)
	{
		str.app("+ ");
		str.app_num(c);
		str.app(" = 0\n");
	}
	else
	{
		str.app("- ");
		str.app_num(-c);
		str.app(" = 0\n");
	}
}