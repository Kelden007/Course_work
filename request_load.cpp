#include "request_load.h"

void request_load()
{
	bool flag = true;
	SetColor(Red, Black);
	std::cout << "\nДля выхода нажмите ESC\n";
	do
	{
		int num_but = _getch();
		switch (num_but)
		{
		case 27:
			mark = false;
			flag = false;
			PlaySound(TEXT("beep_exit"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		default:
			break;
		}
	} while (flag);
}