#include "load_f.h"

void load_f()
{
	SetColor(LightGray, Black);
	std::cout << "������� ��� ����� ��� ���� ������ ����� ����������� ���� (������ ���� \"C:\\Example\\save\").";
	std::cout << "\n� ���� ������� C - ��� �����, Example - ��� �����, save - ��� �����.";
	std::cout << "\n����� �������������� ������ ��� ������ �������� \'\\\' ��� \'/\'. ����� ����� �������� \':\'\n";
	std::cout << "����� ����� ������ ������ ��� �����. ��� �������� �� ��� �����, ��� ��������� ������.\n\n";
	bool flag = false, mark = false;
	char name[100] = "", space, element, cont;
	FILE* f;
	while (true)
	{
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		add_resolution(flag, name);
		std::cout << std::endl;
		fopen_s(&f, name, "r+t");
		if (f == NULL)
		{
			SetColor(Red, Black);
			PlaySound(TEXT("error"), NULL, SND_ASYNC | SND_FILENAME);
			Sleep(100);
			std::cout << "������. ������� ������������ ��� ����� ��� ����. ���������� ��� ���:\n\n";
		}
		else
			break;
	}
	space = 't';
	fseek(f, -4, SEEK_CUR), fread(&cont, 1, 1, f), fseek(f, -1, SEEK_CUR);
	while (true)
	{
		if (mark == 1)
		{
			fread(&cont, 1, 1, f);
			fseek(f, -1, SEEK_CUR);
		}
		switch (cont)
		{
		case 10:
		{
			fread(&cont, 1, 1, f);
			std::cout << cont;
			space = cont;
			break;
		}
		case '\r':
		{
			fclose(f);
			SetColor(Red, Black);
			std::cout << "\n�������� ���� ������� �����������!\n";
			return;
		}
		default:
		{
			fread(&element, sizeof(char), 1, f);
			std::cout << element;
			mark = 1;
			space = cont;
			break;
		}
		}
	}
}