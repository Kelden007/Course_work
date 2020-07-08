#include "inverse_matrix.h"

void inverse_matrix()
{
	visual(0, size_y + 4);
	std::cout << "\nОбратная матррица: \n";
	for (int i = 0; i < size_y; ++i)
	{
		std::cout << "|";
		for (int j = 0; j < size_x; ++j)
		{
			if (inv_matrix[i][j] < 0)
				printf("%.4f", inv_matrix[i][j]);
			else
				printf("%.5f", inv_matrix[i][j]);
			if (j != size_x - 1)
				std::cout << " ";
		}
		std::cout << "|" << std::endl;
	}
}