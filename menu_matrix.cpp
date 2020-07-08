#include "menu_matrix.h"

void menu_matrix()
{
	int num_but;
	do
	{
		system("cls");
		output_text_menu_matrix();
		SetColor(Cyan, Black);
		num_but = _getch();
		if (num_but == 224)
			num_but = _getch();
		switch (num_but)
		{
		case DOWN:
			if (++key == 5)
				key = 1;
			PlaySound(TEXT("switch_menu"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		case UP:
			if (--key == 0)
				key = 4;
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
		case FOUR:
			key = 4;
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
				act_matrix_case_1();
				break;
			case 2:
				act_matrix_case_2();
				break;
			case 3:
				act_matrix_case_3();
				break;
			case 4:
				if (act_matrix_case_4())
					continue;
				break;
			}
		}
	} while (true);
}