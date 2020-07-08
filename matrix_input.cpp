#include "matrix_input.h"

void matrix_input()
{
	if ((size_x == 0 || size_y == 0) || reverse)
	{
		do
		{
			std::cout << "Ввод длины: ";
			size_x = input_size();
			if (size_x < 1 || size_x >= l)
				std::cout << "\tОшибка! Максимальные размеры матрицы 9, минимальные - 1" << std::endl;
		} while (size_x < 1 || size_x >= l);
		std::cout << std::endl;
		do
		{
			std::cout << "Ввод широты: ";
			size_y = input_size();
			if (size_y < 1 || size_y >= l)
				std::cout << "\tОшибка! Максимальные размеры матрицы 9, минимальные - 1" << std::endl;
		} while (size_y < 1 || size_y >= l);
		std::cout << std::endl;
		reverse = false;
		system("cls");
	}
	_rank1 = 0;
	determinant = 0;
	for (int i = 0; i < size_y; ++i)
		for (int j = 0; j < size_x; ++j)
		{
			matrix[i][j] = minor[i][j][0];
			if (i == j)
				inv_matrix[i][j] = 1;
		}
	write_matrix();
	element_switch();
}