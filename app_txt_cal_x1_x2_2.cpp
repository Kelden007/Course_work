#include "app_txt_cal_x1_x2_2.h"

void app_txt_cal_x1_x2_2(double x, double x2, double a, double b, double D)
{
	str.app("\nx1 = (-b - D^0.5) / (2*a);");
	str.app("\nx2 = (-b + D^0.5) / (2*a);\n");
	if (b > 0 && a > 0)
	{
		str.app("\nx1 = ("); str.app_num(-b); str.app(" - "); str.app_num(D); str.app("^0.5) / (2*"); str.app_num(a); str.app(")");
		str.app(" = "); str.app_num(-b - sqrt(D)); str.app(" / "), str.app_num(2 * a); str.app(" = "); str.app_num(x); str.app(";");
		str.app("\nx2 = ("); str.app_num(b); str.app(" + "); str.app_num(D); str.app("^0.5) / (2*"); str.app_num(a); str.app(")");
		str.app(" = "); str.app_num(-b + sqrt(D)); str.app(" / "); str.app_num(2 * a); str.app(" = "); str.app_num(x2); str.app(";\n");
	}
	else if (b < 0 && a > 0)
	{
		str.app("\nx1 = (-("); str.app_num(b); str.app(") - "); str.app_num(D); str.app("^0.5) / (2*"); str.app_num(a); str.app(")");
		str.app(" = "); str.app_num(-b - sqrt(D)); str.app(" / "), str.app_num(2 * a); str.app(" = "); str.app_num(x); str.app(";");
		str.app("\nx2 = (-("); str.app_num(b); str.app(") + "); str.app_num(D); str.app("^0.5) / (2*"); str.app_num(a); str.app(")");
		str.app(" = "); str.app_num(-b + sqrt(D)); str.app(" / "); str.app_num(2 * a); str.app(" = "); str.app_num(x2); str.app(";\n");
	}
	else if (b > 0 && a < 0)
	{
		str.app("\nx1 = ("); str.app_num(-b); str.app(" - "); str.app_num(D); str.app("^0.5) / (2*("); str.app_num(a); str.app("))");
		str.app(" = "); str.app_num(-b - sqrt(D)); str.app(" / ("), str.app_num(2 * a); str.app(") = "); str.app_num(x); str.app(";");
		str.app("\nx2 = ("); str.app_num(-b); str.app(" + "); str.app_num(D); str.app("^0.5) / (2*("); str.app_num(a); str.app("))");
		str.app(" = "); str.app_num(-b + sqrt(D)); str.app(" / ("); str.app_num(2 * a); str.app(") = "); str.app_num(x2); str.app(";\n");
	}
	else if (b < 0 && a < 0)
	{
		str.app("\nx1 = (-("); str.app_num(b); str.app(") - "); str.app_num(D); str.app("^0.5) / (2*("); str.app_num(a); str.app("))");
		str.app(" = "); str.app_num(-b - sqrt(D)); str.app(" / ("), str.app_num(2 * a); str.app(") = "); str.app_num(x); str.app(";");
		str.app("\nx2 = (-("); str.app_num(b); str.app(") + "); str.app_num(D); str.app("^0.5) / (2*("); str.app_num(a); str.app("))");
		str.app(" = "); str.app_num(-b + sqrt(D)); str.app(" / ("); str.app_num(2 * a); str.app(") = "); str.app_num(x2); str.app(";\n");
	}
	str.app("\nОтвет: x1 = ");
	str.app_num(x);
	str.app("; x2 = ");
	str.app_num(x2);
	str.app(".\n\r");
}