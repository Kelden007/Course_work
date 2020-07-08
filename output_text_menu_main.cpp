#include "output_text_menu_main.h"

std::string act_main_menu[] =
{
"1. Алгебраическое уравнение",
"2. Матрицы",
"3. Загрузка из файла"
};

void output_text_menu_main()
{
	int i = 1;
	for (std::string text_menu : act_main_menu)
	{
		SetColor(Blue, Black);
		std::string marker;
		if (key == i)
		{
			SetColor(LightBlue, Black);
			marker = " <--";
		}
		else
		{
			marker = "  ";
			SetColor(Blue, Black);
		}
		std::string menuline = text_menu + marker;
		std::cout << menuline << std::endl;
		++i;
	}
}