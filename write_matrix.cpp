#include "write_matrix.h"

void write_matrix()
{
	std::cout << "ƒлина: " << size_x << std::endl << "Ўирина: " << size_y << std::endl << std::endl;
	for (int i = 0; i < size_y; ++i)
	{
		std::cout << "|";
		for (int j = 0; j < size_x; ++j)
			printf("%4d", minor[i][j][0]);
		std::cout << "|\n";
	}
}