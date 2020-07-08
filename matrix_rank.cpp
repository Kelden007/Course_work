#include "matrix_rank.h"

void matrix_rank(bool flag)
{
	for (int i = 0; i < size_y; ++i)
		for (int j = 0; j < size_x + flag; ++j)
			matrix[i][j] = minor[i][j][0];
	bool flag1 = false;
	gauss(flag, 0);
	for (int i = 0; i < size_y; ++i)
		for (int j = 0; j < size_x + flag; ++j)
			if (matrix[i][j] != 0)
			{
				if (flag == 0)
					++_rank1;
				else
					++_rank2;
				break;
			}
	for (int i = 0; i < size_y; ++i)
		for (int j = 0; j < size_x + flag; ++j)
			matrix[i][j] = minor[i][j][0];
	return;
}