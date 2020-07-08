#include "act_matrix_case_4.h"

bool act_matrix_case_4()
{
	system("cls");
	PlaySound(TEXT("beep_choose"), NULL, SND_ASYNC | SND_FILENAME);
	Sleep(100);
	visual(-1, menusize + 2);
	write_matrix();
	app_txt_matrix();
	if (determinant == 0)
	{
		std::cout << "\nОбратная матрица не найдена\n";
		str.app("\nОбратная матрица не найдена\n\r");
		request_matrix();
		return true;
	}
	inverse_matrix();
	app_txt_inverse_mat();
	request_matrix();
	str.clear_str();
	return false;
}