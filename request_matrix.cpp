#include "request_matrix.h"

void request_matrix()
{
	bool flag = true;
	SetColor(Red, Black);
	std::cout << "\n��� ������ ������� ESC\n" << "��� ���������� ������� ������� S\n";
	do
	{
		int num_but = _getch();
		if (num_but == 115)
			num_but = 83;
		switch (num_but)
		{
		case 27:
			mark = false, flag = false;
			PlaySound(TEXT("beep_exit"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		case 83:
			mark = false;
			str.save();
			break;
		default:
			break;
		}
	} while (flag);
}