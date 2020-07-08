#include "output_text_menu_matrix.h"

std::string act_menu_matrix[] =
{
"1. ���� �������",
"2. ����",
"3. �����������",
"4. A^-1 (�������� �������)"
};

void output_text_menu_matrix()
{
	int i = 1;
	for (std::string text_menu : act_menu_matrix)
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