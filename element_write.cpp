#include "element_write.h"

int element_write(int i, int j)
{
	int element_value = 0;
	char value[ELEMENT_LEN + 1];
	bool flag = false, znak = true;
	if (j < size_x)
	{
		visual(0, size_y + menusize + 4);
		std::cout << "Элемент[" << i << "]" << "[" << j << "] =       ";
		visual(16, size_y + menusize + 4);
	}
	std::cout << std::endl;
	SetColor(Red, Black);
	std::cout << "\nДля выхода нажмите ESC\n" << "Для сохранения решения нажмите S\n" << "Для того чтобы ввести заново коэффициенты, нажмите R\n";
	SetColor(Cyan, Black);
	visual(16, size_y + menusize + 4);
	int numb, m;
	for (m = 0; m < ELEMENT_LEN; ++m)
	{
		if (flag == true)
			break;
		numb = _getch();
		if (numb == ESC)
		{
			matrix_analysis();
			PlaySound(TEXT("beep_exit"), NULL, SND_ASYNC | SND_FILENAME);
			menu_matrix();
		}
		if (numb == 114)
			numb = 82;
		if (numb == 115)
			numb = 83;
		if (numb == 45 && m == 0)
		{
			std::cout << char(numb);
			znak = false;
		}
		if (numb == 82)
		{
			reverse = true;
			system("cls");
			matrix_input();
		}
		if (numb == 83)
		{
			save_flag_inp = true;
			app_txt_matrix();
			str.app("\r");
			str.save();
			save_flag_inp = false;
			system("cls");
			SetColor(Cyan, Black);
			matrix_input();
		}
		if (numb == 8)
		{
			if (m > 0)
			{
				value[m - 1] = '\0';
				--m;
				std::cout << '\b' << " " << '\b';
			}
		}
		if (numb != 224 && (numb < 48 || numb > 57))
		{
			--m;
			continue;
		}
		if (numb >= 48 && numb <= 57)
		{
			value[m] = numb;
			std::cout << value[m];
		}
		if (numb == 224)
		{
			flag = true;
			value[m] = '\0';
			if (m == 0)
				break;
			for (m = 0; m < strlen(value); ++m)
			{
				int number = value[m] - '0';
				element_value = element_value + number * pow(10, strlen(value) - m - 1);
			}
			if (znak == false)
				element_value = 0 - element_value;
			if (j < size_x)
				visual(15, size_y + menusize + 4);
			else
				visual(19, size_y + menusize + 4);
			std::cout << "     ";
			break;
		}
		if (m == 2)
		{
			flag = true;
			value[m + 1] = '\0';
			for (m = 0; m < strlen(value); ++m)
			{
				int number = value[m] - '0';
				element_value = element_value + number * pow(10, strlen(value) - m - 1);
			}
			if (znak == false)
				element_value = 0 - element_value;
		}
	}
	if (m != 0)
		matrix[i][j] = minor[i][j][0] = element_value;
	if (j < size_x)
	{
		visual(1 + 4 * j, i + menusize + 3);
		printf("%4d", minor[i][j][0]);
	}
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	if (numb == ESC)
	{
		visual(0, size_y + menusize + 4);
		std::cout << "                  ";
		visual(0, size_y + menusize + 4);
		for (int i = 0; i < size_y; i++)
			for (int i = 0; i < size_y; i++)
				matrix[i][j] = minor[i][j][0];
		return 0;
	}
}