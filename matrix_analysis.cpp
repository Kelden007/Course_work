#include "matrix_analysis.h"

void matrix_analysis()
{
	matrix_rank(0);
	matrix_rank(1);
	if (size_x == size_y && size_x == _rank1)
	{
		gauss(0, 1);
		inv_gauss(0, 1, 0);
		determinant_count(size_x);
	}
	for (int i = 0; i < size_y; ++i)
		for (int j = 0; j < size_x; ++j)
			matrix[i][j] = minor[i][j][0];
	if (_rank1 == _rank2)
	{
		if (_rank1 >= size_x)
		{
			gauss(1, 0);
			inv_gauss(1, 0, 0);
			up_triangle();
		}
		if (size_x > _rank1)
		{
			gauss(1, 0);
			up_triangle();
			int s = 0;
			int i(0), j(0);
			while (s != size_x - _rank1)
			{
				if (matrix[i][j] == 0)
				{
					s++;
					matrix[_rank1 + s - 1][j] = 1;
					matrix[_rank1 + s - 1][l + s] = 1;
				}
				++i;
				++j;
			}
			inv_gauss(1, 0, 1);
		}
	}
}