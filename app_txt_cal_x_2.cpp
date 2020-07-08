#include "app_txt_cal_x_2.h"

void app_txt_cal_x_2(double x, double a, double b, double c)
{
	if (a != 0)
		str.app("\nx = -b / (2*a);");
	if (b > 0 && a > 0)
	{
		str.app("\nx = -");
		str.app_num(b);
		str.app(" / (2*");
		str.app_num(a);
		str.app(")");
		str.app(" = -");
		str.app_num(b);
		str.app(" / ");
		str.app_num(2 * a);
		str.app(" = ");
		str.app_num(x);
		str.app(";\n");
	}
	else if (b < 0 && a > 0)
	{
		str.app("\nx = -(");
		str.app_num(b);
		str.app(") / (2*");
		str.app_num(a);
		str.app(")");
		str.app(" = -");
		str.app_num(-b);
		str.app(" / ");
		str.app_num(2 * a);
		str.app(" = ");
		str.app_num(x);
		str.app(";\n");
	}
	else if (b > 0 && a < 0)
	{
		str.app("\nx = -");
		str.app_num(b);
		str.app(" / (2*(");
		str.app_num(a);
		str.app("))");
		str.app(" = -");
		str.app_num(b);
		str.app(" / (");
		str.app_num(2 * a);
		str.app(") = ");
		str.app_num(x);
		str.app(";\n");
	}
	else if (b < 0 && a < 0)
	{
		str.app("\nx = -(");
		str.app_num(b);
		str.app(") / (2*(");
		str.app_num(a);
		str.app("))");
		str.app(" = -");
		str.app_num(b);
		str.app(" / (");
		str.app_num(2 * a);
		str.app(") = ");
		str.app_num(x);
		str.app(";\n");
	}
	else
		str.app("\nx = 0\n");
	str.app("Ответ: x = ");
	str.app_num(x);
	str.app(".\n\r");
}