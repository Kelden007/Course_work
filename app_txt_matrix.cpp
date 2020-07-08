#include "app_txt_matrix.h"

void app_txt_matrix()
{
	str.app("ƒлина: ");
	str.app_num(size_x);
	str.endl();
	str.app("Ўирина: ");
	str.app_num(size_y);
	str.endl();
	str.endl();
	for (int i = 0; i < size_y; ++i)
	{
		str.app("|");
		for (int j = 0; j < size_x; ++j)
		{
			str.app("    ");
			str.app_num(minor[i][j][0]);
		}
		str.app("|\n");
	}
}