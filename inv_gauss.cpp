#include "inv_gauss.h"

void inv_gauss(bool flag, bool inv_flag, bool parameter)
{
	float s;
	for (int i = size_x - 1, j = size_x - 1; i >= 0, j >= 0; --i, --j)
		for (int m = i - 1; m >= 0; --m)
		{
			while (matrix[i][j] == 0) --i;
			if (m != i)
			{
				s = matrix[m][j] / matrix[i][j];
				matrix[m][j] = matrix[m][j] - matrix[i][j] * s;
				if (parameter == true)
					for (int k = 0; k < size_x - _rank1; ++k)
						matrix[m][l + 1 + k] = matrix[m][l + 1 + k] - matrix[i][l + 1 + k] * s;
				if (flag == true && inv_flag == false)
					matrix[m][size_x] = matrix[m][size_x] - matrix[i][size_x] * s;
				if (inv_flag == true)
					for (int k = 0; k < size_x; ++k)
						inv_matrix[m][k] = inv_matrix[m][k] - inv_matrix[i][k] * s;
			}
		}
}