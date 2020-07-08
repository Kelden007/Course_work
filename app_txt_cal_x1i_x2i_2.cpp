#include "app_txt_cal_x1i_x2i_2.h"

void app_txt_cal_x1i_x2i_2(double& x_real, double a, double b, double D, double x1_i, double x2_i)
{
	str.app("D = ");
	str.app_num(abs(D));
	str.app("*i^2 (где i - это мнимая единица, квадрат которой равняется -1)");
	str.app("\nx1_i = (-b - D^0.5) / (2*a);");
	str.app("\nx2_i = (-b + D^0.5) / (2*a);\n");
	if (b > 0 && a > 0)
	{
		str.app("\nx1_i = ("); str.app_num(-b); str.app(" + ("); str.app_num(abs(D)); str.app("*i^2)^0.5) / (2*"); str.app_num(a); str.app(")");
		str.app(" = "); str.app_num(x_real); str.app(" + "); str.app_num(x1_i); str.app("*i;");
		str.app("\nx2_i = ("); str.app_num(-b); str.app(" - ("); str.app_num(abs(D)); str.app("*i^2)^0.5) / (2*"); str.app_num(a); str.app(")");
		str.app(" = "); str.app_num(x_real); str.app(" - "); str.app_num(x2_i); str.app("*i.\n");
	}
	else if (b < 0 && a > 0)
	{
		str.app("\nx1_i = (-("); str.app_num(b); str.app(") + ("); str.app_num(abs(D)); str.app("*i^2)^0.5) / (2*"); str.app_num(a); str.app(")");
		str.app(" = "); str.app_num(x_real); str.app(" + "); str.app_num(x1_i); str.app("*i;");
		str.app("\nx2_i = (-("); str.app_num(b); str.app(") - ("); str.app_num(abs(D)); str.app("*i^2)^0.5) / (2*"); str.app_num(a); str.app(")");
		str.app(" = "); str.app_num(x_real); str.app(" - "); str.app_num(x2_i); str.app("*i.\n");
	}
	else if (b > 0 && a < 0)
	{
		str.app("\nx1_i = ("); str.app_num(-b); str.app(" + ("); str.app_num(abs(D)); str.app("*i^2)^0.5) / (2*("); str.app_num(a); str.app("))");
		str.app(" = "); str.app_num(x_real); str.app(" + "); str.app_num(x1_i); str.app("*i;");
		str.app("\nx2_i = ("); str.app_num(-b); str.app(" - ("); str.app_num(abs(D)); str.app("*i^2)^0.5) / (2*("); str.app_num(a); str.app("))");
		str.app(" = "); str.app_num(x_real); str.app(" - "); str.app_num(x2_i); str.app("*i.\n");
	}
	else if (b < 0 && a < 0)
	{
		str.app("\nx1_i = (-("); str.app_num(b); str.app(") + ("); str.app_num(abs(D)); str.app("*i^2)^0.5) / (2*("); str.app_num(a); str.app("))");
		str.app(" = "); str.app_num(x_real); str.app(" + "); str.app_num(x1_i); str.app("*i;");
		str.app("\nx2_i = (-("); str.app_num(b); str.app(") - ("); str.app_num(abs(D)); str.app("*i^2)^0.5) / (2*("); str.app_num(a); str.app("))");
		str.app(" = "); str.app_num(x_real); str.app(" - "); str.app_num(x2_i); str.app("*i.\n");
	}
	str.app("\nОтвет: x1_i = ");
	str.app_num(x_real);
	str.app(" + ");
	str.app_num(x1_i);
	str.app("*i; x2_i = ");
	str.app_num(x2_i);
	str.app("*i.\n\r");
}