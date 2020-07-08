#include "output_text_menu_equation.h"

std::string act_menu_equation[] =
{
"1. Линейное уравнение",
"2. Квадратное уравнение",
"3. Кубическое уравнение"
};

void output_text_menu_equation()
{
	int i = 1;
	for (std::string text_menu : act_menu_equation)
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