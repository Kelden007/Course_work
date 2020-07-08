#include "act_matrix_case_3.h"

void act_matrix_case_3()
{
	system("cls");
	PlaySound(TEXT("beep_choose"), NULL, SND_ASYNC | SND_FILENAME);
	Sleep(100);
	visual(-1, menusize + 2);
	write_matrix();
	app_txt_matrix();
	std::cout << "\nДетерминант: " << determinant << std::endl;
	str.app("\nДетерминант: ");
	str.app_num(determinant);
	str.app("\n\r");
	request_matrix();
	str.clear_str();
}