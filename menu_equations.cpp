#include "menu_equations.h"

void menu_equations()
{
	int num_but;
	do
	{
		if (mark == false)
		{
			system("cls");
			output_text_menu_equation();
			SetColor(Cyan, Black);
			num_but = _getch();
			if (num_but == 224)
				num_but = _getch();
		}
		else
			num_but = 13;
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
			PlaySound(TEXT("beep_exit"), NULL, SND_ASYNC | SND_FILENAME);
			menu_main();
			break;
		case ENTER:
			switch (key)
			{
			case 1:
				system("cls");
				PlaySound(TEXT("beep_choose"), NULL, SND_ASYNC | SND_FILENAME);
				Sleep(100);
				equation_1();
				request_equation();
				str.clear_str();
				break;
			case 2:
				system("cls");
				PlaySound(TEXT("beep_choose"), NULL, SND_ASYNC | SND_FILENAME);
				Sleep(100);
				equation_2();
				request_equation();
				str.clear_str();
				break;
			case 3:
				system("cls");
				PlaySound(TEXT("beep_choose"), NULL, SND_ASYNC | SND_FILENAME);
				Sleep(100);
				equation_3();
				request_equation();
				str.clear_str();
				break;
			}
		}
	} while (true);
}