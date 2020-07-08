#include "determinant_count.h"

int determinant_count(int size)
{
	int minor_ = 0;
	switch (size)
	{
	case 1:
	{
		minor_ = minor[0][0][k];
		if (size_x == 1)
			determinant = minor[0][0][k];
		break;
	}
	default:
	{
		int sum = 0;
		for (int i = 0; i < size; ++i)
		{
			minor_s(i, 0, size);
			minor_ = determinant_count(size - 1);
			k--;
			sum = sum + pow(-1, i) * minor[i][0][k] * minor_;
		}
		if (k == 0)
			determinant = determinant + sum;
		return
			sum;
		break;
	}
	}
	return minor_;
}