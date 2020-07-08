#include "minor_s.h"

void minor_s(int i, int j, int size)
{
	++k;
	int a1 = 0, b1 = 0, a2 = 0, b2 = 0;
	for (a1 = 0; a1 < size - 1; ++a1, ++a2)
	{
		if (a2 == i)
			++a2;
		for (b1 = 0, b2 = 0; b1 < size - 1; ++b1, ++b2)
		{
			if (b2 == j)
				++b2;
			minor[a1][b1][k] = minor[a2][b2][k - 1];
		}
	}
}