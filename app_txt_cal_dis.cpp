#include "app_txt_cal_dis.h"

void app_txt_cal_dis(double D, double a, double b, double c)
{
	str.app("\nD = b^2 - 4*a*c;\n");
	if (b > 0 && a > 0 && c > 0)
	{
		str.app("D = ");
		str.app_num(b);
		str.app("^2 - 4*");
		str.app_num(a);
		str.app("*");
		str.app_num(c);
		str.app(" = ");
		str.app_num(pow(b, 2));
		str.app(" - ");
		str.app_num(4 * a * c);
		str.app(" = ");
		str.app_num(D);
		str.app(";\n");
	}
	else if (b > 0 && a < 0 && c > 0)
	{
		str.app("D = ");
		str.app_num(b);
		str.app("^2 - 4*(");
		str.app_num(a);
		str.app(")*");
		str.app_num(c);
		str.app(" = ");
		str.app_num(pow(b, 2));
		str.app(" - (");
		str.app_num(4 * a * c);
		str.app(") = ");
		str.app_num(D);
		str.app(";\n");
	}
	else if (b > 0 && a > 0 && c < 0)
	{
		str.app("D = ");
		str.app_num(b);
		str.app("^2 - 4*");
		str.app_num(a);
		str.app("*(");
		str.app_num(c);
		str.app(") = ");
		str.app_num(pow(b, 2));
		str.app(" - (");
		str.app_num(4 * a * c);
		str.app(") = ");
		str.app_num(D);
		str.app(";\n");
	}
	else if (b > 0 && a < 0 && c < 0)
	{
		str.app("D = ");
		str.app_num(b);
		str.app("^2 - 4*(");
		str.app_num(a);
		str.app(")*(");
		str.app_num(c);
		str.app(") = ");
		str.app_num(pow(b, 2));
		str.app(" - ");
		str.app_num(4 * a * c);
		str.app(" = ");
		str.app_num(D);
		str.app(";\n");
	}
	else if (b < 0 && a > 0 && c > 0)
	{
		str.app("D = (");
		str.app_num(b);
		str.app(")^2 - 4*");
		str.app_num(a);
		str.app("*");
		str.app_num(c);
		str.app(" = ");
		str.app_num(pow(b, 2));
		str.app(" - ");
		str.app_num(4 * a * c);
		str.app(" = ");
		str.app_num(D);
		str.app(";\n");
	}
	else if (b < 0 && a < 0 && c > 0)
	{
		str.app("D = (");
		str.app_num(b);
		str.app(")^2 - 4*(");
		str.app_num(a);
		str.app(")*");
		str.app_num(c);
		str.app(" = ");
		str.app_num(pow(b, 2));
		str.app(" - (");
		str.app_num(4 * a * c);
		str.app(") = ");
		str.app_num(D);
		str.app(";\n");
	}
	else if (b < 0 && a > 0 && c < 0)
	{
		str.app("D = (");
		str.app_num(b);
		str.app(")^2 - 4*");
		str.app_num(a);
		str.app("*(");
		str.app_num(c);
		str.app(") = ");
		str.app_num(pow(b, 2));
		str.app(" - (");
		str.app_num(4 * a * c);
		str.app(") = ");
		str.app_num(D);
		str.app(";\n");
	}
	else if (b < 0 && a < 0 && c < 0)
	{
		str.app("D = (");
		str.app_num(b);
		str.app(")^2 - 4*(");
		str.app_num(a);
		str.app(")*(");
		str.app_num(c);
		str.app(") = ");
		str.app_num(pow(b, 2));
		str.app(" - ");
		str.app_num(4 * a * c);
		str.app(" = ");
		str.app_num(D);
		str.app(";\n");
	}
}