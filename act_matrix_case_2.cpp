#include "act_matrix_case_2.h"

void act_matrix_case_2()
{
	system("cls");
	PlaySound(TEXT("beep_choose"), NULL, SND_ASYNC | SND_FILENAME);
	Sleep(100);
	visual(-1, menusize + 2);
	write_matrix();
	app_txt_matrix();
	std::cout << "\n����: " << _rank1 << std::endl;
	str.app("\n����: ");
	str.app_num(_rank1);
	str.app("\n\r");
	request_matrix();
	str.clear_str();
}