#include "app_txt_inverse_mat.h"

void app_txt_inverse_mat()
{
	str.app("\nОбратная матррица: \n");
	for (int i = 0; i < size_y; ++i)
	{
		str.app("|");
		for (int j = 0; j < size_x; ++j)
		{
			str.app_num(inv_matrix[i][j]);
			if (j != size_x - 1)
				str.app(" ");
		}
		str.app("|\n");
	}
	str.app("\r");
}