#include "up_triangle.h"

void up_triangle()
{
	double str[l];
	for (int i = 0; i < size_y - 1; ++i)
	{
		bool null_flag = true;
		for (int j = 0; j <= size_x; ++j)
		{
			str[j] = matrix[i][j];
			if (matrix[i][j] != 0)
			{
				null_flag = false;
				break;
			}
		}
		if (null_flag == false)
			continue;
		for (int j = 0; j <= size_x; ++j)
		{
			matrix[i][j] = matrix[i + 1][j];
			matrix[i + 1][j] = str[j];
		}
	}
}