#include "app_txt_cal_1.h"

void app_txt_cal_1(double x, double a, double b)
{
	if (a != 0)
	{
		if (b != 0)
		{
			str.endl();
			str.app_num(a);
			str.app("*x = ");
			str.app_num(-b);
			str.endl(), str.app("x = ");
			str.app_num(-b);
			str.app(" / ");
			str.app_num(a);
			str.app(" = ");
			str.app_num(x);
			str.endl();
		}
		else
		{
			str.endl();
			str.app_num(a);
			str.app("*x = ");
			str.app_num(b);
			str.endl();
			str.app("x = ");
			str.app_num(b);
			str.app(" / ");
			str.app_num(a);
			str.app(" = ");
			str.app_num(x);
			str.endl();
		}
		str.app("\n�����: x = ");
		str.app_num(x);
		str.app(".\n\r");
	}
	else if (a == 0 && b != 0)
		str.app("\n�����: ��������� �� ����� ������.\n\r");
	else
		str.app("\n�����: x ����� ��������� ����� ������������ ��������.\n\r");
}