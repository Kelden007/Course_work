#include "element_switch.h"

void element_switch()
{
	int i = 0;
	int j = 0;
	int result;
	result = element_write(i, j);
	if (result == 0)
		return;
	while (true)
	{
		int choice = _getch();
		switch (choice)
		{
		case UP:
		{
			if (i == 0)
				i = size_y - 1;
			else
				--i;
			result = element_write(i, j);
			if (result == 0)
				return;
			break;
		}
		case DOWN:
		{
			if (i == size_y - 1)
				i = 0;
			else
				++i;
			result = element_write(i, j);
			if (result == 0)
				return;
			break;
		}
		case LEFT:
		{
			if (j == 0)
				j = size_x - 1;
			else
				--j;
			result = element_write(i, j);
			if (result == 0)
				return;
			break;
		}
		case RIGHT:
		{
			if (j == size_x - 1)
				j = 0;
			else
				++j;
			result = element_write(i, j);
			if (result == 0)
				return;
			break;
		}
		}
	}
}