#include "save_f.h"

void save_f(std::string result)
{
	system("cls");
	SetColor(LightGray, Black);
	std::cout << "Введите имя файла или путь куда сохранится файл (пример пути \"C:\\Example\\save\").";
	std::cout << "\nВ этом примере C - имя диска, Example - имя папки, save - имя файла.";
	std::cout << "\nМежду наименованиями дисков или файлов ставится \'\\\' или \'/\'. После диска ставится \':\'\n";
	std::cout << "Также можно ввести просто имя файла. Оно сохранится в ту папку, где находится проект.\n\n";
	bool flag = false;
	int count;
	char name[100] = "";
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	FILE* f;
	while (true)
	{
		add_resolution(flag, name);
		fopen_s(&f, name, "w+t");
		if (f == NULL)
		{
			SetColor(Red, Black);
			PlaySound(TEXT("error"), NULL, SND_ASYNC | SND_FILENAME);
			Sleep(100);
			std::cout << "Ошибка. Введено некорректное имя файла или путь. Попробуйте ещё раз:\n\n";
		}
		else
			break;
	}
	count = fwrite(result.c_str(), sizeof(char), result.size(), f);
	fclose(f);
	SetColor(Red, Black);
	printf("\a");
	if (save_flag_inp)
	{
		std::cout << "\nСохранение было успешно произведено!\nДля продолженя нажмите ENTER";
		int temp;
		while (true)
		{
			temp = _getch();
			if (temp == ENTER)
				break;
		}
	}
	else
		std::cout << "\nСохранение было успешно произведено!\nНажмите ESC, чтобы вернуться в меню\n";
}