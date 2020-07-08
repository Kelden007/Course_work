#include "app_txt_inp_fac_1.h"

void app_txt_inp_fac_1(double a, double b)
{
	str.app("Уравнение вида: a*x + b = 0\n");
	str.app("Введите коэффициент \'a\': ");
	str.app_num(a);
	str.endl();
	str.app("Введите коэффициент \'b\': ");
	str.app_num(b);
	str.endl();
	str.endl();
	str.app_num(a);
	str.app("*x ");
	if (b >= 0)
	{
		str.app("+ ");
		str.app_num(b);
		str.app(" = 0\n");
	}
	else
	{
		str.app("- ");
		str.app_num(-b);
		str.app(" = 0\n");
	}
}