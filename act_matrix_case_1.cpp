#include "act_matrix_case_1.h"

void act_matrix_case_1()
{
	system("cls");
	PlaySound(TEXT("beep_choose"), NULL, SND_ASYNC | SND_FILENAME);
	Sleep(100);
	matrix_input();
}