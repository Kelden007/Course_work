#include "input_size.h"

int input_size()
{
	int fix = 0, value = 0, random = 0, focus = 1;
	bool flag = false;
	char input_array[3];
	for (int j = 0; j < 3; ++j)
		input_array[j] = -1;
	int i = 0, j = 0;
	std::cout << 0;
	do
	{
		fix = _getch();
		switch (fix)
		{
		case ESC:
			PlaySound(TEXT("beep_exit"), NULL, SND_ASYNC | SND_FILENAME);
			menu_matrix();
			break;
		case BACKSPACE:
			if (j > 0)
			{
				input_array[j - 1] = -1;
				--j;
				std::cout << '\b' << " " << '\b';
				if (j == 0)
				{
					std::cout << 0;
					focus = 1;
				}
			}
		}
		if (((fix >= (48 + focus)) && (fix <= 57)) && (focus == 1))
			std::cout << '\b' << " " << '\b';
		if (j < 2)
		{
			if (((fix >= (48 + focus)) && (fix <= 57)) || (fix == 13))
			{
				if (fix == 13)
					break;
				input_array[j] = fix;
				++j;
				focus = 0;
			}
			if ((fix >= (48 + focus)) && (fix <= 57))
			{
				fix = fix - '0';
				std::cout << fix;
			}
		}
		else
			if (fix == 13)
				flag = true;
		if (flag)
			break;
	} while (true);
	int t = -1;
	for (j = 0; j < 3; ++j)
		if (input_array[j] != -1)
			value = value * 10 + (input_array[j] - 48);
	return value;
}