#include "request_equation.h"

void request_equation()
{
	bool flag = true;
	SetColor(Red, Black);
	std::cout << "\nДля выхода нажмите ESC\n" << "Для сохранения решения нажмите S\n" << "Для того чтобы ввести заново коэффициенты, нажмите R\n";
	do
	{
		int num_but = _getch();
		if (num_but == 115)
			num_but = 83;
		else if (num_but == 114)
			num_but = 82;
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
		case 82:
			mark = true;
			key = pointer;
			menu_equations();
			break;
		default:
			break;
		}
	} while (flag);
}