#include "input_num.h"

double input_num()
{
	short button = 0, pointer = 0;
	double factor = 0;
	bool focus = true, flag = false, point = false, minus = false;
	char input_array[LIMIT + 1];
	for (short j = 1; j < LIMIT + 1; ++j)
		input_array[j] = -1;
	input_array[0] = 0;
	int i = 0, j = 1;
	std::cout << 0;
	do
	{
		button = _getch();
		switch (button)
		{
		case ESC:
			PlaySound(TEXT("beep_exit"), NULL, SND_ASYNC | SND_FILENAME);
			menu_equations();
			break;
		case BACKSPACE:
			if (j > 1)
			{
				input_array[j - 1] = -1;
				--j;
				std::cout << '\b' << " " << '\b';
				if (j == 1 && point == false)
				{
					std::cout << 0;
					if (input_array[0] == 1)
					{
						input_array[0] = 0;
						minus = false;
					}
					focus = true;
				}
				if (j == pointer)
					point = false;
			}
			break;
		case 46:
			if (j > 0 && point == false)
			{
				std::cout << char(button);
				input_array[j] = char(button);
				pointer = j;
				++j;
				point = true;
			}
			break;
		case 45:
			if (minus == false && j == 1)
			{
				input_array[0] = 1;
				std::cout << '\b' << " " << '\b';
				std::cout << char(button);
				++j;
				focus = false;
			}
			minus = true;
			break;
		default:
			break;
		}
		if (focus && point == false && ((button >= (48 + focus)) && (button <= 57)))
			std::cout << '\b' << " " << '\b';
		if (j < LIMIT)
		{
			if (((button >= (48 + focus)) && (button <= 57)) || (button == 13))
			{
				if (button == 13)
					break;
				input_array[j] = button;
				++j;
				focus = false;
			}
			if ((button >= (48 + focus)) && (button <= 57))
			{
				button = button - '0';
				std::cout << button;
			}
		}
		else
			if (button == 13)
				flag = true;
		if (flag)
			break;
	} while (true);
	short t = -1, degree = 1;
	bool mark = true;
	for (j = 1; j < LIMIT - 1; ++j)
	{
		if (input_array[j] == '.')
		{
			mark = false;
			continue;
		}
		else if (input_array[j] != -1 && mark)
			factor = factor * 10 + (input_array[j] - '0');
		if (mark == false && input_array[j] != -1)
		{
			factor = factor + ((input_array[j] - '0') / pow(10.0, degree));
			++degree;
		}
	}
	if (minus == true)
		factor = -factor, minus = false;
	return factor;
}