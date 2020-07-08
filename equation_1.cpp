#include "equation_1.h"

void equation_1()
{
	double a, b, x;
	SetColor(LightCyan, Black);
	input_factors_1(a, b);
	app_txt_inp_fac_1(a, b);
	calculation_1(x, a, b);
	app_txt_cal_1(x, a, b);
	pointer = 1;
}