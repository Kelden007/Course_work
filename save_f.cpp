#include "save_f.h"

void save_f(std::string result)
{
	system("cls");
	SetColor(LightGray, Black);
	std::cout << "������� ��� ����� ��� ���� ���� ���������� ���� (������ ���� \"C:\\Example\\save\").";
	std::cout << "\n� ���� ������� C - ��� �����, Example - ��� �����, save - ��� �����.";
	std::cout << "\n����� �������������� ������ ��� ������ �������� \'\\\' ��� \'/\'. ����� ����� �������� \':\'\n";
	std::cout << "����� ����� ������ ������ ��� �����. ��� ���������� � �� �����, ��� ��������� ������.\n\n";
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
			std::cout << "������. ������� ������������ ��� ����� ��� ����. ���������� ��� ���:\n\n";
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
		std::cout << "\n���������� ���� ������� �����������!\n��� ���������� ������� ENTER";
		int temp;
		while (true)
		{
			temp = _getch();
			if (temp == ENTER)
				break;
		}
	}
	else
		std::cout << "\n���������� ���� ������� �����������!\n������� ESC, ����� ��������� � ����\n";
}