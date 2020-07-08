#include "menu_main.h"

void menu_main()
{
	int num_but;
	if (key > 3)
		key = 3;;
	do
	{
		system("cls");
		output_text_menu_main();
		SetColor(Cyan, Black);
		num_but = _getch();
		if (num_but == 224)
			num_but = _getch();
		switch (num_but)
		{
		case DOWN:
			if (++key == 4)
				key = 1;
			PlaySound(TEXT("switch_menu"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		case UP:
			if (--key == 0)
				key = 3;
			PlaySound(TEXT("switch_menu"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		case ONE:
			key = 1;
			PlaySound(TEXT("switch_menu"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		case TWO:
			key = 2;
			PlaySound(TEXT("switch_menu"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		case THREE:
			key = 3;
			PlaySound(TEXT("switch_menu"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		case ESC:
			exit(0);
			break;
		case ENTER:
			switch (key)
			{
			case 1:
				system("cls");
				PlaySound(TEXT("beep_choose"), NULL, SND_ASYNC | SND_FILENAME);
				Sleep(100);
				menu_equations();
				break;
			case 2:
				system("cls");
				PlaySound(TEXT("beep_choose"), NULL, SND_ASYNC | SND_FILENAME);
				Sleep(100);
				key = 1;
				menu_matrix();
				break;
			case 3:
				system("cls");
				PlaySound(TEXT("beep_choose"), NULL, SND_ASYNC | SND_FILENAME);
				Sleep(100);
				load_f();
				request_load();
				break;
			}
		}
	} while (true);
}