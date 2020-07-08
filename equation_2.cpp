#include "equation_2.h"

void equation_2()
{
	double D, x = 0, x2 = 0, a = 0, b = 0, c = 0, x1_i = 0, x2_i = 0;
	SetColor(LightCyan, Black);
	input_factors_2(a, b, c);
	app_txt_inp_fac_2(a, b, c);
	if (a != 0)
	{
		calculation_dis(D, a, b, c);
		app_txt_cal_dis(D, a, b, c);
		if (D == 0)
		{
			calculation_x_2(x, a, b, c);
			app_txt_cal_x_2(x, a, b, c);
		}
		else if (D > 0)
		{
			calculation_x1_x2_2(x, x2, a, b, D);
			app_txt_cal_x1_x2_2(x, x2, a, b, D);
		}
		else
		{
			calculation_x1i_x2i_2(x, a, b, D, x1_i, x2_i);
			app_txt_cal_x1i_x2i_2(x, a, b, D, x1_i, x2_i);
		}
	}
	else
	{
		calculation_1(x, b, c);
		app_txt_cal_1(x, b, c);
	}
	pointer = 2;
}