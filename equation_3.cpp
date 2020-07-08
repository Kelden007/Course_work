#include "equation_3.h"

void equation_3()
{
	double a, b, c, d;
	SetColor(LightCyan, Black);
	input_factors_3(a, b, c, d);
	app_txt_inp_fac_3(a, b, c, d);
	calculation_3(a, b, c, d);
	app_txt_cal_3(a, b, c, d);
	pointer = 3;
}