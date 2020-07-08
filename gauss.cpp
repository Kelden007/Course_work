#include "gauss.h"

void gauss(bool flag, bool inv_flag)
{
	float s;
	bool flag1;
	bool flag2 = false;
	int m = 0;
	int q = 0;
	for (m = 0; m < size_y; ++m)
	{
		if (q == size_x + flag || m == size_y - 1)
		{
			if (matrix[size_y - 1][size_x - 1 + flag] != 0)
			{
				s = matrix[size_y - 1][size_x - 1];
				if (s != 0)
				{
					for (int j = 0; j < size_x + flag; ++j)
						matrix[size_y - 1][j] = matrix[size_y - 1][j] / s;
					if (inv_flag == true)
						for (int j = 0; j < size_x; ++j)
							inv_matrix[size_y - 1][j] = inv_matrix[size_y - 1][j] / s;
				}
			}
			return;
		}
		flag1 = false;
		for (int i = m; i < size_y - 1; ++i)
			if (matrix[i][q] != 0 && flag1 == false)
			{
				flag1 = true;
				for (int j = m; j < size_x + flag; ++j)
				{
					s = matrix[m][j];
					matrix[m][j] = matrix[i][j];
					matrix[i][j] = s;
					if (inv_flag == true)
					{
						s = inv_matrix[m][j];
						inv_matrix[m][j] = inv_matrix[i][j];
						inv_matrix[i][j] = s;
					}
				}
			}
		if (flag1 == false)
		{
			flag2 = true;
			++q;
			--m;
			continue;
		}
		if (matrix[m][q] != 0)
		{
			s = matrix[m][q];
			for (int j = m; j < size_x + flag; ++j)
				matrix[m][j] = matrix[m][j] / s;
			if (inv_flag == true)
				for (int j = 0; j < size_x; ++j)
					inv_matrix[m][j] = inv_matrix[m][j] / s;
		}
		if (flag1 == true)
		{
			if (matrix[m][q] != 0)
				for (int i = m + 1; i < size_y; ++i)
				{
					s = matrix[i][q] / matrix[m][q];
					for (int j = 0; j < size_x + flag; ++j)
						matrix[i][j] = matrix[i][j] - matrix[m][j] * s;
					if (inv_flag == true)
						for (int j = 0; j < size_x; ++j)
							inv_matrix[i][j] = inv_matrix[i][j] - inv_matrix[m][j] * s;
				}

		}
		else
			return;
		++q;
	}
}