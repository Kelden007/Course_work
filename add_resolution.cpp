#include "add_resolution.h"

bool add_resolution(bool flag, char name[])
{
	int i = 0, counter = 0;
	while (flag == false)
	{
		SetColor(Brown, Black);
		std::cout << "Имя файла или путь: ";
		SetColor(Yellow, Black);
		std::cin.getline(name, 100);
		for (int j = 0; j < 96; j++)
		{
			if (name[j] == '\0')
			{
				counter = j;
				flag = true;
				break;
			}
		}
		name[counter] = '.', name[counter + 1] = 't', name[counter + 2] = 'x', name[counter + 3] = 't', name[counter + 4] = '\0';
	}
	return flag;
}