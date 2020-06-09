#include <iostream>
#include <cmath>
#include <conio.h>
#include <string>
#include <stdio.h>
#include <cmath>
#include <windows.h>

#pragma comment(lib, "winmm.lib")

short key = 1, pointer;
bool mark = false, reverse = true, save_flag_inp = false;

const int l = 10;
float matrix[l][l * 2];
int minor[l][l + 1][l];
float inv_matrix[l][l];
int _rank1 = 0, _rank2 = 0, determinant = 0;
int k = 0, action = 1;
int size_x = 0, size_y = 0;
int menusize, base = 10;
int b_old = 0, c_old = 0, d_old = 0;

constexpr auto MENUWIDE = 40;
constexpr auto ELEMENT_LEN = 3;
constexpr auto UP = 72;
constexpr auto DOWN = 80;
constexpr auto LEFT = 75;
constexpr auto RIGHT = 77;
constexpr auto ONE = 49;
constexpr auto TWO = 50;
constexpr auto THREE = 51;
constexpr auto FOUR = 52;
constexpr auto ENTER = 13;
constexpr auto ESC = 27;
constexpr auto BACKSPACE = 8;
constexpr auto LIMIT = 308;

const double M_PI = 3.1415926535897932384626433832795;
const double M_2PI(2. * M_PI);

enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
} Color;

void SetColor(ConsoleColor text, ConsoleColor background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

std::string str = "";

std::string act_main_menu[] =
{
"1. Алгебраическое уравнение",
"2. Матрицы",
"3. Загрузка из файла"
};

std::string act_menu_equation[] =
{
"1. Линейное уравнение",
"2. Квадратное уравнение",
"3. Кубическое уравнение"
};

std::string act_menu_matrix[] =
{
"1. Ввод матрицы",
"2. Ранг",
"3. Детерминант",
"4. A^-1 (обратная матрица)"
};

enum keys
{
	key1 = 49, key2, key3, key4, key5, key6
};

void visual(int i, int j);
void gauss1();
void gauss(bool flag, bool inv_flag);
void inv_gauss(bool flag, bool inv_flag, bool parameter);
void matrix_rank(bool flag);
void minor_s(int i, int j, int size);
int determinant_count(int size);
int element_write(int i, int j);
void element_switch();
void app_txt_matrix();
void write_matrix();
void app_txt_matrix();
void write_matrix();
void up_triangle();
void matrix_analysis();
void matrix_input();
void app_txt_inverse_mat();
void inverse_matrix();
double input_num();
int input_size();
bool add_resolution(bool flag, char name[]);
void save_f(std::string result);
void load_f();
void app_txt_inp_fac_1(double a, double b, bool& flag);
void input_factors_1(double& a, double& b, bool flag);
void app_txt_cal_1(double x, double a, double b, bool flag);
void calculation_1(double& x, double a, double b, bool flag);
void equation_1();
void app_txt_inp_fac_2(double a, double b, double c, bool& flag);
void input_factors_2(double& a, double& b, double& c, bool flag);
void app_txt_cal_dis(double D, double a, double b, double c, bool flag);
void calculation_dis(double& D, double a, double b, double c, bool flag);
void app_txt_cal_x_2(double x, double a, double b, double c, bool flag);
void calculation_x_2(double& x, double a, double b, double c, bool flag);
void app_txt_cal_x1_x2_2(double x, double x2, double a, double b, double D, bool flag);
void calculation_x1_x2_2(double& x, double& x2, double a, double b, double D, bool flag);
void app_txt_cal_x1i_x2i_2(double& x_real, double a, double b, double D, bool flag, double x1_i, double x2_i);
void calculation_x1i_x2i_2(double& x_real, double a, double b, double D, bool flag, double& x1_i, double& x2_i);
void equation_2();
void app_txt_inp_fac_3(double a, double b, double c, double d, bool& flag);
void input_factors_3(double& a, double& b, double& c, double& d, bool flag);
void app_txt_cal_3(double a, double b, double c, double& d, bool& flag);
void calculation_3(double& a, double& b, double& c, double& d, bool flag);
void equation_3();
void request_equation();
void request_matrix();
void output_text_menu_equation();
void output_text_menu_matrix();
void output_text_menu_main();
void act_matrix_case_1();
void act_matrix_case_2();
void act_matrix_case_3();
bool act_matrix_case_4();
void menu_equations();
void menu_matrix();
void menu_main();

int main()
{
	setlocale(LC_ALL, "ru");
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	menu_main();
	return 0;
}

void visual(int i, int j)
{
	HANDLE consoleOutput;
	COORD cursorPos;

	consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	cursorPos.X = i;
	cursorPos.Y = j;
	SetConsoleCursorPosition(consoleOutput, cursorPos);
}

void gauss1()
{
	float s;
	int iter = 0;
	int q = 0;
}

void gauss(bool flag, bool inv_flag)
{
	float s;
	bool flag1;
	bool flag2 = false;
	int m = 0;
	int q = 0;
	for (m = 0; m < size_y; ++m)
	{
		if (q == size_x + flag || m == size_y - 1)
		{
			if (matrix[size_y - 1][size_x - 1 + flag] != 0)
			{
				s = matrix[size_y - 1][size_x - 1];
				if (s != 0)
				{
					for (int j = 0; j < size_x + flag; ++j)
						matrix[size_y - 1][j] = matrix[size_y - 1][j] / s;
					if (inv_flag == true)
						for (int j = 0; j < size_x; ++j)
							inv_matrix[size_y - 1][j] = inv_matrix[size_y - 1][j] / s;
				}
			}
			return;
		}
		flag1 = false;
		for (int i = m; i < size_y - 1; ++i)
			if (matrix[i][q] != 0 && flag1 == false)
			{
				flag1 = true;
				for (int j = m; j < size_x + flag; ++j)
				{
					s = matrix[m][j];
					matrix[m][j] = matrix[i][j];
					matrix[i][j] = s;
					if (inv_flag == true)
					{
						s = inv_matrix[m][j];
						inv_matrix[m][j] = inv_matrix[i][j];
						inv_matrix[i][j] = s;
					}
				}
			}
		if (flag1 == false)
		{
			flag2 = true;
			++q;
			--m;
			continue;
		}
		if (matrix[m][q] != 0)
		{
			s = matrix[m][q];
			for (int j = m; j < size_x + flag; ++j)
				matrix[m][j] = matrix[m][j] / s;
			if (inv_flag == true)
				for (int j = 0; j < size_x; ++j)
					inv_matrix[m][j] = inv_matrix[m][j] / s;
		}
		if (flag1 == true)
		{
			if (matrix[m][q] != 0)
				for (int i = m + 1; i < size_y; ++i)
				{
					s = matrix[i][q] / matrix[m][q];
					for (int j = 0; j < size_x + flag; ++j)
						matrix[i][j] = matrix[i][j] - matrix[m][j] * s;
					if (inv_flag == true)
						for (int j = 0; j < size_x; ++j)
							inv_matrix[i][j] = inv_matrix[i][j] - inv_matrix[m][j] * s;
				}

		}
		else
			return;
		++q;
	}
}

void inv_gauss(bool flag, bool inv_flag, bool parameter)
{
	float s;
	for (int i = size_x - 1, j = size_x - 1; i >= 0, j >= 0; --i, --j)
		for (int m = i - 1; m >= 0; --m)
		{
			while (matrix[i][j] == 0) --i;
			if (m != i)
			{
				s = matrix[m][j] / matrix[i][j];
				matrix[m][j] = matrix[m][j] - matrix[i][j] * s;
				if (parameter == true)
					for (int k = 0; k < size_x - _rank1; ++k)
						matrix[m][l + 1 + k] = matrix[m][l + 1 + k] - matrix[i][l + 1 + k] * s;
				if (flag == true && inv_flag == false)
					matrix[m][size_x] = matrix[m][size_x] - matrix[i][size_x] * s;
				if (inv_flag == true)
					for (int k = 0; k < size_x; ++k)
						inv_matrix[m][k] = inv_matrix[m][k] - inv_matrix[i][k] * s;
			}
		}
}

void matrix_rank(bool flag)
{
	for (int i = 0; i < size_y; ++i)
		for (int j = 0; j < size_x + flag; ++j)
			matrix[i][j] = minor[i][j][0];
	bool flag1 = false;
	gauss(flag, 0);
	for (int i = 0; i < size_y; ++i)
		for (int j = 0; j < size_x + flag; ++j)
			if (matrix[i][j] != 0)
			{
				if (flag == 0)
					++_rank1;
				else
					++_rank2;
				break;
			}
	for (int i = 0; i < size_y; ++i)
		for (int j = 0; j < size_x + flag; ++j)
			matrix[i][j] = minor[i][j][0];
	return;
}

void minor_s(int i, int j, int size)
{
	++k;
	int a1 = 0, b1 = 0, a2 = 0, b2 = 0;
	for (a1 = 0; a1 < size - 1; ++a1, ++a2)
	{
		if (a2 == i)
			++a2;
		for (b1 = 0, b2 = 0; b1 < size - 1; ++b1, ++b2)
		{
			if (b2 == j)
				++b2;
			minor[a1][b1][k] = minor[a2][b2][k - 1];
		}
	}
}

int determinant_count(int size)
{
	int minor_ = 0;
	switch (size)
	{
	case 1:
	{
		minor_ = minor[0][0][k];
		if (size_x == 1)
			determinant = minor[0][0][k];
		break;
	}
	default:
	{
		int sum = 0;
		for (int i = 0; i < size; ++i)
		{
			minor_s(i, 0, size);
			minor_ = determinant_count(size - 1);
			k--;
			sum = sum + pow(-1, i) * minor[i][0][k] * minor_;
		}
		if (k == 0)
			determinant = determinant + sum;
		return
			sum;
		break;
	}
	}
	return minor_;
}

int element_write(int i, int j)
{
	int element_value = 0;
	char value[ELEMENT_LEN + 1];
	bool flag = false, znak = true;
	if (j < size_x)
	{
		visual(0, size_y + menusize + 4);
		std::cout << "Элемент[" << i << "]" << "[" << j << "] =       ";
		visual(16, size_y + menusize + 4);
	}
	std::cout << std::endl;
	SetColor(Red, Black);
	std::cout << "\nДля выхода нажмите ESC\n" << "Для сохранения решения нажмите S\n" << "Для того чтобы ввести заново коэффициенты, нажмите R\n";
	SetColor(Cyan, Black);
	visual(16, size_y + menusize + 4);
	int numb, m;
	for (m = 0; m < ELEMENT_LEN; ++m)
	{
		if (flag == true)
			break;
		numb = _getch();
		if (numb == ESC)
		{
			matrix_analysis();
			PlaySound(TEXT("beep_exit"), NULL, SND_ASYNC | SND_FILENAME);
			menu_matrix();
		}
		if (numb == 114)
			numb = 82;
		if (numb == 115)
			numb = 83;
		if (numb == 45 && m == 0)
		{
			std::cout << char(numb);
			znak = false;
		}
		if (numb == 82)
		{
			reverse = true;
			system("cls");
			matrix_input();
		}
		if (numb == 83)
		{
			save_flag_inp = true;
			app_txt_matrix();
			str.append("\r");
			save_f(str);
			save_flag_inp = false;
			system("cls");
			SetColor(Cyan, Black);
			matrix_input();
		}
		if (numb == 8)
		{
			if (m > 0)
			{
				value[m - 1] = '\0';
				--m;
				std::cout << '\b' << " " << '\b';
			}
		}
		if (numb != 224 && (numb < 48 || numb > 57))
		{
			--m;
			continue;
		}
		if (numb >= 48 && numb <= 57)
		{
			value[m] = numb;
			std::cout << value[m];
		}
		if (numb == 224)
		{
			flag = true;
			value[m] = '\0';
			if (m == 0)
				break;
			for (m = 0; m < strlen(value); ++m)
			{
				int number = value[m] - '0';
				element_value = element_value + number * pow(10, strlen(value) - m - 1);
			}
			if (znak == false)
				element_value = 0 - element_value;
			if (j < size_x)
				visual(15, size_y + menusize + 4);
			else
				visual(19, size_y + menusize + 4);
			std::cout << "     ";
			break;
		}
		if (m == 2)
		{
			flag = true;
			value[m + 1] = '\0';
			for (m = 0; m < strlen(value); ++m)
			{
				int number = value[m] - '0';
				element_value = element_value + number * pow(10, strlen(value) - m - 1);
			}
			if (znak == false)
				element_value = 0 - element_value;
		}
	}
	if (m != 0)
		matrix[i][j] = minor[i][j][0] = element_value;
	if (j < size_x)
	{
		visual(1 + 4 * j, i + menusize + 3);
		printf("%4d", minor[i][j][0]);
	}
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	if (numb == ESC)
	{
		visual(0, size_y + menusize + 4);
		std::cout << "                  ";
		visual(0, size_y + menusize + 4);
		for (int i = 0; i < size_y; i++)
			for (int i = 0; i < size_y; i++)
				matrix[i][j] = minor[i][j][0];
		return 0;
	}
}

void element_switch()
{
	int i = 0;
	int j = 0;
	int result;
	result = element_write(i, j);
	if (result == 0)
		return;
	while (true)
	{
		int choice = _getch();
		switch (choice)
		{
		case UP:
		{
			if (i == 0)
				i = size_y - 1;
			else
				--i;
			result = element_write(i, j);
			if (result == 0)
				return;
			break;
		}
		case DOWN:
		{
			if (i == size_y - 1)
				i = 0;
			else
				++i;
			result = element_write(i, j);
			if (result == 0)
				return;
			break;
		}
		case LEFT:
		{
			if (j == 0)
				j = size_x - 1;
			else
				--j;
			result = element_write(i, j);
			if (result == 0)
				return;
			break;
		}
		case RIGHT:
		{
			if (j == size_x - 1)
				j = 0;
			else
				++j;
			result = element_write(i, j);
			if (result == 0)
				return;
			break;
		}
		}
	}
}

void app_txt_matrix()
{
	str.append("Длина: "), str += std::to_string(int(size_x)), str += "\n", str.append("Ширина: "), str += std::to_string(int(size_y)), str += "\n\n";
	for (int i = 0; i < size_y; ++i)
	{
		str.append("|");
		for (int j = 0; j < size_x; ++j)
			str.append("    "), str += std::to_string(int(minor[i][j][0]));
		str.append("|\n");
	}
}

void write_matrix()
{
	std::cout << "Длина: " << size_x << std::endl << "Ширина: " << size_y << std::endl << std::endl;
	for (int i = 0; i < size_y; ++i)
	{
		std::cout << "|";
		for (int j = 0; j < size_x; ++j)
			printf("%4d", minor[i][j][0]);
		std::cout << "|\n";
	}
}

void up_triangle()
{
	double str[l];
	for (int i = 0; i < size_y - 1; ++i)
	{
		bool null_flag = true;
		for (int j = 0; j <= size_x; ++j)
		{
			str[j] = matrix[i][j];
			if (matrix[i][j] != 0)
			{
				null_flag = false;
				break;
			}
		}
		if (null_flag == false)
			continue;
		for (int j = 0; j <= size_x; ++j)
		{
			matrix[i][j] = matrix[i + 1][j];
			matrix[i + 1][j] = str[j];
		}
	}
}

void matrix_analysis()
{
	matrix_rank(0);
	matrix_rank(1);
	if (size_x == size_y && size_x == _rank1)
	{
		gauss(0, 1);
		inv_gauss(0, 1, 0);
		determinant_count(size_x);
	}
	for (int i = 0; i < size_y; ++i)
		for (int j = 0; j < size_x; ++j)
			matrix[i][j] = minor[i][j][0];
	if (_rank1 == _rank2)
	{
		if (_rank1 >= size_x)
		{
			gauss(1, 0);
			inv_gauss(1, 0, 0);
			up_triangle();
		}
		if (size_x > _rank1)
		{
			gauss(1, 0);
			up_triangle();
			int s = 0;
			int i(0), j(0);
			while (s != size_x - _rank1)
			{
				if (matrix[i][j] == 0)
				{
					s++;
					matrix[_rank1 + s - 1][j] = 1;
					matrix[_rank1 + s - 1][l + s] = 1;
				}
				++i;
				++j;
			}
			inv_gauss(1, 0, 1);
		}
	}
}

void matrix_input()
{
	if ((size_x == 0 || size_y == 0) || reverse)
	{
		do
		{
			std::cout << "Ввод длины: ";
			size_x = input_size();
			if (size_x < 1 || size_x >= l)
				std::cout << "\tОшибка! Максимальные размеры матрицы 9, минимальные - 1" << std::endl;
		} while (size_x < 1 || size_x >= l);
		std::cout << std::endl;
		do
		{
			std::cout << "Ввод широты: ";
			size_y = input_size();
			if (size_y < 1 || size_y >= l)
				std::cout << "\tОшибка! Максимальные размеры матрицы 9, минимальные - 1" << std::endl;
		} while (size_y < 1 || size_y >= l);
		std::cout << std::endl;
		reverse = false;
		system("cls");
	}
	_rank1 = 0;
	determinant = 0;
	for (int i = 0; i < size_y; ++i)
		for (int j = 0; j < size_x; ++j)
		{
			matrix[i][j] = minor[i][j][0];
			if (i == j)
				inv_matrix[i][j] = 1;
		}
	write_matrix();
	element_switch();
}

void app_txt_inverse_mat()
{
	str.append("\nОбратная матррица: \n");
	for (int i = 0; i < size_y; ++i)
	{
		str.append("|");
		for (int j = 0; j < size_x; ++j)
		{
			str += std::to_string(float(inv_matrix[i][j]));
			if (j != size_x - 1)
				str.append(" ");
		}
		str.append("|\n");
	}
	str.append("\r");
}

void inverse_matrix()
{
	visual(0, size_y + 4);
	std::cout << "\nОбратная матррица: \n";
	for (int i = 0; i < size_y; ++i)
	{
		std::cout << "|";
		for (int j = 0; j < size_x; ++j)
		{
			if (inv_matrix[i][j] < 0)
				printf("%.4f", inv_matrix[i][j]);
			else
				printf("%.5f", inv_matrix[i][j]);
			if (j != size_x - 1)
				std::cout << " ";
		}
		std::cout << "|" << std::endl;
	}
}

double input_num()
{
	short button = 0, pointer = 0;
	double factor = 0;
	bool focus = true, flag = false, point = false, minus = false;
	char input_array[LIMIT + 1];
	for (short j = 1; j < LIMIT + 1; ++j)
		input_array[j] = -1;
	input_array[0] = 0;
	int i = 0, j = 1;
	std::cout << 0;
	do
	{
		button = _getch();
		switch (button)
		{
		case ESC:
			PlaySound(TEXT("beep_exit"), NULL, SND_ASYNC | SND_FILENAME);
			menu_equations();
			break;
		case BACKSPACE:
			if (j > 1)
			{
				input_array[j - 1] = -1;
				--j;
				std::cout << '\b' << " " << '\b';
				if (j == 1 && point == false)
				{
					std::cout << 0;
					if (input_array[0] == 1)
					{
						input_array[0] = 0;
						minus = false;
					}
					focus = true;
				}
				if (j == pointer)
					point = false;
			}
			break;
		case 46:
			if (j > 0 && point == false)
			{
				std::cout << char(button);
				input_array[j] = char(button);
				pointer = j;
				++j;
				point = true;
			}
			break;
		case 45:
			if (minus == false && j == 1)
			{
				input_array[0] = 1;
				std::cout << '\b' << " " << '\b';
				std::cout << char(button);
				++j;
				focus = false;
			}
			minus = true;
			break;
		default:
			break;
		}
		if (focus && point == false && ((button >= (48 + focus)) && (button <= 57)))
			std::cout << '\b' << " " << '\b';
		if (j < LIMIT)
		{
			if (((button >= (48 + focus)) && (button <= 57)) || (button == 13))
			{
				if (button == 13)
					break;
				input_array[j] = button;
				++j;
				focus = false;
			}
			if ((button >= (48 + focus)) && (button <= 57))
			{
				button = button - '0';
				std::cout << button;
			}
		}
		else
			if (button == 13)
				flag = true;
		if (flag)
			break;
	} while (true);
	short t = -1, degree = 1;
	bool mark = true;
	for (j = 1; j < LIMIT - 1; ++j)
	{
		if (input_array[j] == '.')
		{
			mark = false;
			continue;
		}
		else if (input_array[j] != -1 && mark)
			factor = factor * 10 + (input_array[j] - '0');
		if (mark == false && input_array[j] != -1)
		{
			factor = factor + ((input_array[j] - '0') / pow(10.0, degree));
			++degree;
		}
	}
	if (minus == true)
		factor = -factor, minus = false;
	return factor;
}

int input_size()
{
	int fix = 0, value = 0, random = 0, focus = 1;
	bool flag = false;
	char input_array[3];
	for (int j = 0; j < 3; ++j)
		input_array[j] = -1;
	int i = 0, j = 0;
	std::cout << 0;
	do
	{
		fix = _getch();
		switch (fix)
		{
		case ESC:
			PlaySound(TEXT("beep_exit"), NULL, SND_ASYNC | SND_FILENAME);
			menu_matrix();
			break;
		case BACKSPACE:
			if (j > 0)
			{
				input_array[j - 1] = -1;
				--j;
				std::cout << '\b' << " " << '\b';
				if (j == 0)
				{
					std::cout << 0;
					focus = 1;
				}
			}
		}
		if (((fix >= (48 + focus)) && (fix <= 57)) && (focus == 1))
			std::cout << '\b' << " " << '\b';
		if (j < 2)
		{
			if (((fix >= (48 + focus)) && (fix <= 57)) || (fix == 13))
			{
				if (fix == 13)
					break;
				input_array[j] = fix;
				++j;
				focus = 0;
			}
			if ((fix >= (48 + focus)) && (fix <= 57))
			{
				fix = fix - '0';
				std::cout << fix;
			}
		}
		else
			if (fix == 13)
				flag = true;
		if (flag)
			break;
	} while (true);
	int t = -1;
	for (j = 0; j < 3; ++j)
		if (input_array[j] != -1)
			value = value * 10 + (input_array[j] - 48);
	return value;
}

bool add_resolution(bool flag, char name[])
{
	int i = 0, counter = 0;
	while (flag == false)
	{
		SetColor(Brown, Black);
		std::cout << "Имя файла или путь: ";
		SetColor(Yellow, Black);
		std::cin.getline(name, 100);
		for (int j = 0; j < 96; j++)
		{
			if (name[j] == '\0')
			{
				counter = j;
				flag = true;
				break;
			}
		}
		name[counter] = '.', name[counter + 1] = 't', name[counter + 2] = 'x', name[counter + 3] = 't', name[counter + 4] = '\0';
	}
	return flag;
}

void save_f(std::string result)
{
	system("cls");
	SetColor(LightGray, Black);
	std::cout << "Введите имя файла или путь куда сохранится файл (пример пути \"C:\\Example\\save\").";
	std::cout << "\nВ этом примере C - имя диска, Example - имя папки, save - имя файла.";
	std::cout << "\nМежду наименованиями дисков или файлов ставится \'\\\' или \'/\'. После диска ставится \':\'\n";
	std::cout << "Также можно ввести просто имя файла. Оно сохранится в ту папку, где находится проект.\n\n";
	bool flag = false;
	int count;
	char name[100] = "";
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	FILE* f;
	while (true)
	{
		add_resolution(flag, name);
		fopen_s(&f, name, "w+t");
		if (f == NULL)
		{
			SetColor(Red, Black);
			PlaySound(TEXT("error"), NULL, SND_ASYNC | SND_FILENAME);
			Sleep(100);
			std::cout << "Ошибка. Введено некорректное имя файла или путь. Попробуйте ещё раз:\n\n";
		}
		else
			break;
	}
	count = fwrite(result.c_str(), sizeof(char), result.size(), f);
	fclose(f);
	SetColor(Red, Black);
	printf("\a");
	if (save_flag_inp)
	{
		std::cout << "\nСохранение было успешно произведено!\nДля продолженя нажмите ENTER";
		int temp;
		while (true)
		{
			temp = _getch();
			if (temp == ENTER)
				break;
		}
	}
	else
		std::cout << "\nСохранение было успешно произведено!\nНажмите ESC, чтобы вернуться в меню\n";
}

void load_f()
{
	SetColor(LightGray, Black);
	std::cout << "Введите имя файла или путь откуда будет загружаться файл (пример пути \"C:\\Example\\save\").";
	std::cout << "\nВ этом примере C - имя диска, Example - имя папки, save - имя файла.";
	std::cout << "\nМежду наименованиями дисков или файлов ставится \'\\\' или \'/\'. После диска ставится \':\'\n";
	std::cout << "Также можно ввести просто имя файла. Оно загрузит из той папки, где находится проект.\n\n";
	bool flag = false, mark = false;
	char name[100] = "", space, element, cont;
	FILE* f;
	while (true)
	{
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		add_resolution(flag, name);
		std::cout << std::endl;
		fopen_s(&f, name, "r+t");
		if (f == NULL)
		{
			SetColor(Red, Black);
			PlaySound(TEXT("error"), NULL, SND_ASYNC | SND_FILENAME);
			Sleep(100);
			std::cout << "Ошибка. Введено некорректное имя файла или путь. Попробуйте ещё раз:\n\n";
		}
		else
			break;
	}
	space = 't';
	fseek(f, -4, SEEK_CUR), fread(&cont, 1, 1, f), fseek(f, -1, SEEK_CUR);
	while (true)
	{
		if (mark == 1)
		{
			fread(&cont, 1, 1, f);
			fseek(f, -1, SEEK_CUR);
		}
		switch (cont)
		{
		case 10:
		{
			fread(&cont, 1, 1, f);
			std::cout << cont;
			space = cont;
			break;
		}
		case '\r':
		{
			fclose(f);
			SetColor(Red, Black);
			std::cout << "\nЗагрузка была успешна произведена!\n";
			return;
		}
		default:
		{
			fread(&element, sizeof(char), 1, f);
			std::cout << element;
			mark = 1;
			space = cont;
			break;
		}
		}
	}
}

void app_txt_inp_fac_1(double a, double b, bool& flag)
{
	double temp = 0;
	if (a != 0)
		temp = b / a;
	if (temp == round(temp) && a == round(a) && b == round(b))
		flag = true;
	str.append("Уравнение вида: a*x + b = 0\n");
	if (flag)
	{
		str.append("Введите коэффициент \'a\': "), str += std::to_string(int(a)), str += "\n";
		str.append("Введите коэффициент \'b\': "), str += std::to_string(int(b)), str += "\n";
		str += "\n", str += std::to_string(int(a)), str.append("*x ");
		if (b >= 0)
			str.append("+ "), str += std::to_string(int(b)), str.append(" = 0\n");
		else
			str.append("- "), str += std::to_string(int(-b)), str.append(" = 0\n");
	}
	else
	{
		str.append("Введите коэффициент \'a\': "), str += std::to_string(a), str += "\n";
		str.append("Введите коэффициент \'b\': "), str += std::to_string(b), str += "\n";
		str += "\n", str += std::to_string(a), str.append("*x ");
		if (b >= 0)
			str.append("+ "), str += std::to_string(b), str.append(" = 0\n");
		else
			str.append("- "), str += std::to_string(-b), str.append(" = 0\n");
	}
}

void input_factors_1(double& a, double& b, bool flag)
{
	std::cout << "Уравнение вида: a*x + b = 0\n";
	std::cout << "Введите коэффициент \'a\': ";
	a = input_num();
	std::cout << "\nВведите коэффициент \'b\': ";
	b = input_num();
	SetColor(Cyan, Black);
	std::cout << "\n\n" << a << "*x ";
	if (b >= 0)
		std::cout << "+ " << b << " = 0\n";
	else
		std::cout << "- " << -b << " = 0\n";
}

void app_txt_cal_1(double x, double a, double b, bool flag)
{
	if (flag)
	{
		if (a != 0)
		{
			if (b != 0)
			{
				str += "\n", str += std::to_string(int(a)), str.append("*x = "), str += std::to_string(int(-b));
				str += "\n", str.append("x = "), str += std::to_string(int(-b)), str.append(" / "), str += std::to_string(int(a)), str.append(" = "), str += std::to_string(int(x)), str += "\n";
			}
			else
			{
				str += "\n", str += std::to_string(int(a)), str.append("*x = "), str += std::to_string(int(b));
				str += "\n", str.append("x = "), str += std::to_string(int(b)), str.append(" / "), str += std::to_string(int(a)), str.append(" = "), str += std::to_string(int(x)), str += "\n";
			}
			str.append("\nОтвет: x = "), str += std::to_string(int(x)), str.append(".\n\r");
		}
		else if (a == 0 && b != 0)
			str.append("\nОтвет: уравнение не имеет корней.\n\r");
		else
			str.append("\nОтвет: x может принимать любое вещественное значение.\n\r");
	}
	else
	{
		if (a != 0)
		{
			if (b != 0)
			{
				str += "\n", str += std::to_string(a), str.append("*x = "), str += std::to_string(-b);
				str += "\n", str.append("x = "), str += std::to_string(-b), str.append(" / "), str += std::to_string(a), str.append(" = "), str += std::to_string(x), str += "\n";
			}
			else
			{
				str += "\n", str += std::to_string(a), str.append("*x = "), str += std::to_string(b);
				str += "\n", str.append("x = "), str += std::to_string(b), str.append(" / "), str += std::to_string(a), str.append(" = "), str += std::to_string(x), str += "\n";
			}
			str.append("\nОтвет: x = "), str += std::to_string(x), str.append(".\n");
		}
		else if (a == 0 && b != 0)
			str.append("\nОтвет: уравнение не имеет корней.\n");
		else
			str.append("\nОтвет: x может принимать любое вещественное значение.\n");
	}
}

void calculation_1(double& x, double a, double b, bool flag)
{
	if (a != 0)
	{
		if (b != 0)
		{
			x = -b / a;
			std::cout << "\n" << a << "*x = " << -b;
			std::cout << "\nx = " << -b << " / " << a << " = " << x << std::endl;
		}
		else
		{
			x = b / a;
			std::cout << "\n" << a << "*x = " << b;
			std::cout << "\nx = " << b << " / " << a << " = " << x << std::endl;
		}
		std::cout << "\nОтвет: x = " << x << ".\n";
	}
	else if (a == 0 && b != 0)
		std::cout << "\nОтвет: уравнение не имеет корней.\n";
	else
		std::cout << "\nОтвет: x может принимать любое вещественное значение.\n";
}

void equation_1()
{
	bool flag = false;
	double a, b, x;
	SetColor(LightCyan, Black);
	input_factors_1(a, b, flag);
	app_txt_inp_fac_1(a, b, flag);
	calculation_1(x, a, b, flag);
	app_txt_cal_1(x, a, b, flag);
	pointer = 1;
}

void app_txt_inp_fac_2(double a, double b, double c, bool& flag)
{
	double temp = 0, temp_2 = 0;
	if (a != 0)
		temp = b / (2 * a), temp_2 = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
	if (temp == round(temp) && temp_2 == round(temp_2) && a == round(a) && b == round(b) && c == round(c))
		flag = true;
	if (flag)
	{
		str.append("Введите коэффициент \'a\': "), str += std::to_string(int(a)), str += "\n";
		str.append("Введите коэффициент \'b\': "), str += std::to_string(int(b)), str += "\n";
		str.append("Введите коэффициент \'c\': "), str += std::to_string(int(c)), str += "\n";
		str += "\n", str += std::to_string(int(a)), str.append("*x^2 ");
		if (b >= 0)
			str.append("+ "), str += std::to_string(int(b)), str.append("*x ");
		else
			str.append("- "), str += std::to_string(int(-b)), str.append("*x ");
		if (c >= 0)
			str.append("+ "), str += std::to_string(int(c)), str.append(" = 0\n");
		else
			str.append("- "), str += std::to_string(int(-c)), str.append(" = 0\n");
	}
	else
	{
		str.append("Введите коэффициент \'a\': "), str += std::to_string(a), str += "\n";
		str.append("Введите коэффициент \'b\': "), str += std::to_string(b), str += "\n";
		str.append("Введите коэффициент \'c\': "), str += std::to_string(c), str += "\n";
		str += "\n", str += std::to_string(a), str.append("*x^2 ");
		if (b >= 0)
			str.append("+ "), str += std::to_string(b), str.append("*x ");
		else
			str.append("- "), str += std::to_string(-b), str.append("*x ");
		if (c >= 0)
			str.append("+ "), str += std::to_string(c), str.append(" = 0\n");
		else
			str.append("- "), str += std::to_string(-c), str.append(" = 0\n");
	}
}

void input_factors_2(double& a, double& b, double& c, bool flag)
{
	std::cout << "Уравнение вида: a*x^2 + b*x + c = 0\n", str.append("Уравнение вида: a*x^2 + b*x + c = 0\n");
	std::cout << "Введите коэффициент \'a\': ";
	a = input_num();
	std::cout << "\nВведите коэффициент \'b\': ";
	b = input_num();
	std::cout << "\nВведите коэффициент \'c\': ";
	c = input_num();
	SetColor(Cyan, Black);
	std::cout << "\n\n" << a << "*x^2 ";
	if (b >= 0)
		std::cout << "+ " << b << "*x ";
	else
		std::cout << "- " << -b << "*x ";
	if (c >= 0)
		std::cout << "+ " << c << " = 0\n";
	else
		std::cout << "- " << -c << " = 0\n";
}

void app_txt_cal_dis(double D, double a, double b, double c, bool flag)
{
	str.append("\nD = b^2 - 4*a*c;\n");
	if (flag)
	{
		if (b > 0 && a > 0 && c > 0)
		{
			str.append("D = "), str += std::to_string(int(b)), str.append("^2 - 4*"), str += std::to_string(int(a)), str.append("*"), str += std::to_string(int(c));
			str.append(" = "), str += std::to_string(int(pow(b, 2))), str.append(" - "), str += std::to_string(4 * int(a) * int(c)), str.append(" = "), str += std::to_string(int(D)), str.append(";\n");
		}
		else if (b > 0 && a < 0 && c > 0)
		{
			str.append("D = "), str += std::to_string(int(b)), str.append("^2 - 4*("), str += std::to_string(int(a)), str.append(")*"), str += std::to_string(int(c));
			str.append(" = "), str += std::to_string(int(pow(b, 2))), str.append(" - ("), str += std::to_string(4 * int(a) * int(c)), str.append(") = "), str += std::to_string(int(D)), str.append(";\n");
		}
		else if (b > 0 && a > 0 && c < 0)
		{
			str.append("D = "), str += std::to_string(int(b)), str.append("^2 - 4*"), str += std::to_string(int(a)), str.append("*("), str += std::to_string(int(c));
			str.append(") = "), str += std::to_string(int(pow(b, 2))), str.append(" - ("), str += std::to_string(4 * int(a) * int(c)), str.append(") = "), str += std::to_string(int(D)), str.append(";\n");
		}
		else if (b > 0 && a < 0 && c < 0)
		{
			str.append("D = "), str += std::to_string(int(b)), str.append("^2 - 4*("), str += std::to_string(int(a)), str.append(")*("), str += std::to_string(int(c));
			str.append(") = "), str += std::to_string(int(pow(b, 2))), str.append(" - "), str += std::to_string(4 * int(a) * int(c)), str.append(" = "), str += std::to_string(int(D)), str.append(";\n");
		}


		else if (b < 0 && a > 0 && c > 0)
		{
			str.append("D = ("), str += std::to_string(int(b)), str.append(")^2 - 4*"), str += std::to_string(int(a)), str.append("*"), str += std::to_string(int(c));
			str.append(" = "), str += std::to_string(int(pow(b, 2))), str.append(" - "), str += std::to_string(4 * int(a) * int(c)), str.append(" = "), str += std::to_string(int(D)), str.append(";\n");
		}
		else if (b < 0 && a < 0 && c > 0)
		{
			str.append("D = ("), str += std::to_string(int(b)), str.append(")^2 - 4*("), str += std::to_string(int(a)), str.append(")*"), str += std::to_string(int(c));
			str.append(" = "), str += std::to_string(int(pow(b, 2))), str.append(" - ("), str += std::to_string(4 * int(a) * int(c)), str.append(") = "), str += std::to_string(int(D)), str.append(";\n");
		}
		else if (b < 0 && a > 0 && c < 0)
		{
			str.append("D = ("), str += std::to_string(int(b)), str.append(")^2 - 4*"), str += std::to_string(int(a)), str.append("*("), str += std::to_string(int(c));
			str.append(") = "), str += std::to_string(int(pow(b, 2))), str.append(" - ("), str += std::to_string(4 * int(a) * int(c)), str.append(") = "), str += std::to_string(int(D)), str.append(";\n");
		}
		else if (b < 0 && a < 0 && c < 0)
		{
			str.append("D = ("), str += std::to_string(int(b)), str.append(")^2 - 4*("), str += std::to_string(int(a)), str.append(")*("), str += std::to_string(int(c));
			str.append(") = "), str += std::to_string(int(pow(b, 2))), str.append(" - "), str += std::to_string(4 * int(a) * int(c)), str.append(" = "), str += std::to_string(int(D)), str.append(";\n");
		}
	}
	else
	{
		if (b > 0 && a > 0 && c > 0)
		{
			str.append("D = "), str += std::to_string(b), str.append("^2 - 4*"), str += std::to_string(a), str.append("*"), str += std::to_string(c);
			str.append(" = "), str += std::to_string(pow(b, 2)), str.append(" - "), str += std::to_string(4 * a * c), str.append(" = "), str += std::to_string(D), str.append(";\n");
		}
		else if (b > 0 && a < 0 && c > 0)
		{
			str.append("D = "), str += std::to_string(b), str.append("^2 - 4*("), str += std::to_string(a), str.append(")*"), str += std::to_string(c);
			str.append(" = "), str += std::to_string(pow(b, 2)), str.append(" - ("), str += std::to_string(4 * a * c), str.append(") = "), str += std::to_string(D), str.append(";\n");
		}
		else if (b > 0 && a > 0 && c < 0)
		{
			str.append("D = "), str += std::to_string(b), str.append("^2 - 4*"), str += std::to_string(a), str.append("*("), str += std::to_string(c);
			str.append(") = "), str += std::to_string(pow(b, 2)), str.append(" - ("), str += std::to_string(4 * a * c), str.append(") = "), str += std::to_string(D), str.append(";\n");
		}
		else if (b > 0 && a < 0 && c < 0)
		{
			str.append("D = "), str += std::to_string(b), str.append("^2 - 4*("), str += std::to_string(a), str.append(")*("), str += std::to_string(c);
			str.append(") = "), str += std::to_string(pow(b, 2)), str.append(" - "), str += std::to_string(4 * a * c), str.append(" = "), str += std::to_string(D), str.append(";\n");
		}


		else if (b < 0 && a > 0 && c > 0)
		{
			str.append("D = ("), str += std::to_string(b), str.append(")^2 - 4*"), str += std::to_string(a), str.append("*"), str += std::to_string(c);
			str.append(" = "), str += std::to_string(pow(b, 2)), str.append(" - "), str += std::to_string(4 * a * c), str.append(" = "), str += std::to_string(D), str.append(";\n");
		}
		else if (b < 0 && a < 0 && c > 0)
		{
			str.append("D = ("), str += std::to_string(b), str.append(")^2 - 4*("), str += std::to_string(a), str.append(")*"), str += std::to_string(c);
			str.append(" = "), str += std::to_string(pow(b, 2)), str.append(" - ("), str += std::to_string(4 * a * c), str.append(") = "), str += std::to_string(D), str.append(";\n");
		}
		else if (b < 0 && a > 0 && c < 0)
		{
			str.append("D = ("), str += std::to_string(b), str.append(")^2 - 4*"), str += std::to_string(a), str.append("*("), str += std::to_string(c);
			str.append(") = "), str += std::to_string(pow(b, 2)), str.append(" - ("), str += std::to_string(4 * a * c), str.append(") = "), str += std::to_string(D), str.append(";\n");
		}
		else if (b < 0 && a < 0 && c < 0)
		{
			str.append("D = ("), str += std::to_string(b), str.append(")^2 - 4*("), str += std::to_string(a), str.append(")*("), str += std::to_string(c);
			str.append(") = "), str += std::to_string(pow(b, 2)), str.append(" - "), str += std::to_string(4 * a * c), str.append(" = "), str += std::to_string(D), str.append(";\n");
		}
	}
}

void calculation_dis(double& D, double a, double b, double c, bool flag)
{
	D = pow(b, 2) - 4 * a * c;
	std::cout << "\nD = b^2 - 4*a*c;\n";
	if (b > 0 && a > 0 && c > 0)
		std::cout << "D = " << b << "^2 - 4*" << a << "*" << c << " = " << pow(b, 2) << " - " << 4 * a * c << " = " << D << ";\n";
	else if (b > 0 && a < 0 && c > 0)
		std::cout << "D = " << b << "^2 - 4*(" << a << ")*" << c << " = " << pow(b, 2) << " - (" << 4 * a * c << ") = " << D << ";\n";
	else if (b > 0 && a > 0 && c < 0)
		std::cout << "D = " << b << "^2 - 4*" << a << "*(" << c << ") = " << pow(b, 2) << " - (" << 4 * a * c << ") = " << D << ";\n";
	else if (b > 0 && a < 0 && c < 0)
		std::cout << "D = " << b << "^2 - 4*(" << a << ")*(" << c << ") = " << pow(b, 2) << " - " << 4 * a * c << " = " << D << ";\n";

	else if (b < 0 && a > 0 && c > 0)
		std::cout << "D = (" << b << ")^2 - 4*" << a << "*" << c << " = " << pow(b, 2) << " - " << 4 * a * c << " = " << D << ";\n";
	else if (b < 0 && a < 0 && c > 0)
		std::cout << "D = (" << b << ")^2 - 4*(" << a << ")*" << c << " = " << pow(b, 2) << " - (" << 4 * a * c << ") = " << D << ";\n";
	else if (b < 0 && a > 0 && c < 0)
		std::cout << "D = (" << b << ")^2 - 4*" << a << "*(" << c << ") = " << pow(b, 2) << " - (" << 4 * a * c << ") = " << D << ";\n";
	else if (b < 0 && a < 0 && c < 0)
		std::cout << "D = (" << b << ")^2 - 4*(" << a << ")*(" << c << ") = " << pow(b, 2) << " - " << 4 * a * c << " = " << D << ";\n";
}

void app_txt_cal_x_2(double x, double a, double b, double c, bool flag)
{
	if (flag)
	{
		if (a != 0)
			str.append("\nx = -b / (2*a);");
		if (b > 0 && a > 0)
		{
			str.append("\nx = -"), str += std::to_string(int(b)), str.append(" / (2*"), str += std::to_string(int(a)), str.append(")");
			str.append(" = -"), str += std::to_string(int(b)), str.append(" / "), str += std::to_string(2 * int(a)), str.append(" = "), str += std::to_string(int(x)), str.append(";\n");
		}
		else if (b < 0 && a > 0)
		{
			str.append("\nx = -("), str += std::to_string(int(b)), str.append(") / (2*"), str += std::to_string(int(a)), str.append(")");
			str.append(" = -"), str += std::to_string(int(-b)), str.append(" / "), str += std::to_string(2 * int(a)), str.append(" = "), str += std::to_string(int(x)), str.append(";\n");
		}
		else if (b > 0 && a < 0)
		{
			str.append("\nx = -"), str += std::to_string(int(b)), str.append(" / (2*("), str += std::to_string(int(a)), str.append("))");
			str.append(" = -"), str += std::to_string(int(b)), str.append(" / ("), str += std::to_string(2 * int(a)), str.append(") = "), str += std::to_string(int(x)), str.append(";\n");
		}
		else if (b < 0 && a < 0)
		{
			str.append("\nx = -("), str += std::to_string(int(b)), str.append(") / (2*("), str += std::to_string(int(a)), str.append("))");
			str.append(" = -"), str += std::to_string(int(b)), str.append(" / ("), str += std::to_string(2 * int(a)), str.append(") = "), str += std::to_string(int(x)), str.append(";\n");
		}
		else
			str.append("\nx = 0\n");
		str.append("Ответ: x = "), str += std::to_string(int(x)), str.append(".\n\r");
	}
	else
	{
		if (a != 0)
			str.append("\nx = -b / (2*a);");
		if (b > 0 && a > 0)
		{
			str.append("\nx = -"), str += std::to_string(b), str.append(" / (2*"), str += std::to_string(a), str.append(")");
			str.append(" = -"), str += std::to_string(b), str.append(" / "), str += std::to_string(2 * a), str.append(" = "), str += std::to_string(x), str.append(";\n");
		}
		else if (b < 0 && a > 0)
		{
			str.append("\nx = -("), str += std::to_string(b), str.append(") / (2*"), str += std::to_string(a), str.append(")");
			str.append(" = -"), str += std::to_string(-b), str.append(" / "), str += std::to_string(2 * a), str.append(" = "), str += std::to_string(x), str.append(";\n");
		}
		else if (b > 0 && a < 0)
		{
			str.append("\nx = -"), str += std::to_string(b), str.append(" / (2*("), str += std::to_string(a), str.append("))");
			str.append(" = -"), str += std::to_string(b), str.append(" / ("), str += std::to_string(2 * a), str.append(") = "), str += std::to_string(x), str.append(";\n");
		}
		else if (b < 0 && a < 0)
		{
			str.append("\nx = -("), str += std::to_string(b), str.append(") / (2*("), str += std::to_string(a), str.append("))");
			str.append(" = -"), str += std::to_string(b), str.append(" / ("), str += std::to_string(2 * a), str.append(") = "), str += std::to_string(x), str.append(";\n");
		}
		else
			str.append("\nx = 0\n");
		str.append("Ответ: x = "), str += std::to_string(x), str.append(".\n\r");
	}
}

void calculation_x_2(double& x, double a, double b, double c, bool flag)
{
	if (a != 0)
	{
		x = -b / (2 * a);
		std::cout << "\nx = -b / (2*a);";
	}
	if (b > 0 && a > 0)
	{
		std::cout << "\nx = -" << b << " / (2*" << a << ")";
		std::cout << " = -" << b << " / " << 2 * a << " = " << x << ";\n";
	}
	else if (b < 0 && a > 0)
	{
		std::cout << "\nx = -(" << b << ") / (2*" << a << ")";
		std::cout << " = " << -b << " / " << 2 * a << " = " << x << ";\n";
	}
	else if (b > 0 && a < 0)
	{
		std::cout << "\nx = -" << b << " / (2*(" << a << "))";
		std::cout << " = -" << b << " / (" << 2 * a << ") = " << x << ";\n";
	}
	else if (b < 0 && a < 0)
	{
		std::cout << "\nx = -(" << b << ") / (2*(" << a << "))";
		std::cout << " = " << -b << " / (" << 2 * a << ") = " << x << ";\n";
	}
	else
		std::cout << "\nx = 0\n";
	std::cout << "Ответ: x = " << x << ".\n";
}

void app_txt_cal_x1_x2_2(double x, double x2, double a, double b, double D, bool flag)
{
	if (flag)
	{
		str.append("\nx1 = (-b - D^0.5) / (2*a);"), str.append("\nx2 = (-b + D^0.5) / (2*a);\n");
		if (b > 0 && a > 0)
		{
			str.append("\nx1 = ("), str += std::to_string(int(-b)), str.append(" - "), str += std::to_string(int(D)), str.append("^0.5) / (2*"), str += std::to_string(int(a)), str.append(")");
			str.append(" = "), str += std::to_string(int(-b - sqrt(D))), str.append(" / "), str += std::to_string(int(2 * a)), str.append(" = "), str += std::to_string(int(x)), str.append(";");
			str.append("\nx2 = ("), str += std::to_string(int(-b)), str.append(" + "), str += std::to_string(int(D)), str.append("^0.5) / (2*"), str += std::to_string(int(a)), str.append(")");
			str.append(" = "), str += std::to_string(int(-b + sqrt(D))), str.append(" / "), str += std::to_string(int(2 * a)), str.append(" = "), str += std::to_string(int(x2)), str.append(";\n");
		}
		else if (b < 0 && a > 0)
		{
			str.append("\nx1 = (-("), str += std::to_string(int(b)), str.append(") - "), str += std::to_string(int(D)), str.append("^0.5) / (2*"), str += std::to_string(int(a)), str.append(")");
			str.append(" = "), str += std::to_string(int(-b - sqrt(D))), str.append(" / "), str += std::to_string(int(2 * a)), str.append(" = "), str += std::to_string(int(x)), str.append(";");
			str.append("\nx2 = (-("), str += std::to_string(int(b)), str.append(") + "), str += std::to_string(int(D)), str.append("^0.5) / (2*"), str += std::to_string(int(a)), str.append(")");
			str.append(" = "), str += std::to_string(int(-b + sqrt(D))), str.append(" / "), str += std::to_string(int(2 * a)), str.append(" = "), str += std::to_string(int(x2)), str.append(";\n");
		}
		else if (b > 0 && a < 0)
		{
			str.append("\nx1 = ("), str += std::to_string(int(-b)), str.append(" - "), str += std::to_string(int(D)), str.append("^0.5) / (2*("), str += std::to_string(int(a)), str.append("))");
			str.append(" = "), str += std::to_string(int(-b - sqrt(D))), str.append(" / ("), str += std::to_string(int(2 * a)), str.append(") = "), str += std::to_string(int(x)), str.append(";");
			str.append("\nx2 = ("), str += std::to_string(int(-b)), str.append(" + "), str += std::to_string(int(D)), str.append("^0.5) / (2*("), str += std::to_string(int(a)), str.append("))");
			str.append(" = "), str += std::to_string(int(-b + sqrt(D))), str.append(" / ("), str += std::to_string(int(2 * a)), str.append(") = "), str += std::to_string(int(x2)), str.append(";\n");
		}
		else if (b < 0 && a < 0)
		{
			str.append("\nx1 = (-("), str += std::to_string(int(b)), str.append(") - "), str += std::to_string(int(D)), str.append("^0.5) / (2*("), str += std::to_string(int(a)), str.append("))");
			str.append(" = "), str += std::to_string(int(-b - sqrt(D))), str.append(" / ("), str += std::to_string(int(2 * a)), str.append(") = "), str += std::to_string(int(x)), str.append(";");
			str.append("\nx2 = (-("), str += std::to_string(int(b)), str.append(") + "), str += std::to_string(int(D)), str.append("^0.5) / (2*("), str += std::to_string(int(a)), str.append("))");
			str.append(" = "), str += std::to_string(int(-b + sqrt(D))), str.append(" / ("), str += std::to_string(int(2 * a)), str.append(") = "), str += std::to_string(int(x2)), str.append(";\n");
		}
		str.append("\nОтвет: x1 = "), str += std::to_string(int(x)), str.append("; x2 = "), str += std::to_string(int(x2)), str.append(".\n\r");
	}
	else
	{
		str.append("\nx1 = (-b - D^0.5) / (2*a);"), str.append("\nx2 = (-b + D^0.5) / (2*a);\n");
		if (b > 0 && a > 0)
		{
			str.append("\nx1 = ("), str += std::to_string(-b), str.append(" - "), str += std::to_string(D), str.append("^0.5) / (2*"), str += std::to_string(a), str.append(")");
			str.append(" = "), str += std::to_string(-b - sqrt(D)), str.append(" / "), str += std::to_string(2 * a), str.append(" = "), str += std::to_string(x), str.append(";");
			str.append("\nx2 = ("), str += std::to_string(b), str.append(" + "), str += std::to_string(D), str.append("^0.5) / (2*"), str += std::to_string(a), str.append(")");
			str.append(" = "), str += std::to_string(-b + sqrt(D)), str.append(" / "), str += std::to_string(2 * a), str.append(" = "), str += std::to_string(x2), str.append(";\n");
		}
		else if (b < 0 && a > 0)
		{
			str.append("\nx1 = (-("), str += std::to_string(b), str.append(") - "), str += std::to_string(D), str.append("^0.5) / (2*"), str += std::to_string(a), str.append(")");
			str.append(" = "), str += std::to_string(-b - sqrt(D)), str.append(" / "), str += std::to_string(2 * a), str.append(" = "), str += std::to_string(x), str.append(";");
			str.append("\nx2 = (-("), str += std::to_string(b), str.append(") + "), str += std::to_string(D), str.append("^0.5) / (2*"), str += std::to_string(a), str.append(")");
			str.append(" = "), str += std::to_string(-b + sqrt(D)), str.append(" / "), str += std::to_string(2 * a), str.append(" = "), str += std::to_string(x2), str.append(";\n");
		}
		else if (b > 0 && a < 0)
		{
			str.append("\nx1 = ("), str += std::to_string(-b), str.append(" - "), str += std::to_string(D), str.append("^0.5) / (2*("), str += std::to_string(a), str.append("))");
			str.append(" = "), str += std::to_string(-b - sqrt(D)), str.append(" / ("), str += std::to_string(2 * a), str.append(") = "), str += std::to_string(x), str.append(";");
			str.append("\nx2 = ("), str += std::to_string(-b), str.append(" + "), str += std::to_string(D), str.append("^0.5) / (2*("), str += std::to_string(a), str.append("))");
			str.append(" = "), str += std::to_string(-b + sqrt(D)), str.append(" / ("), str += std::to_string(2 * a), str.append(") = "), str += std::to_string(x2), str.append(";\n");
		}
		else if (b < 0 && a < 0)
		{
			str.append("\nx1 = (-("), str += std::to_string(b), str.append(") - "), str += std::to_string(D), str.append("^0.5) / (2*("), str += std::to_string(a), str.append("))");
			str.append(" = "), str += std::to_string(-b - sqrt(D)), str.append(" / ("), str += std::to_string(2 * a), str.append(") = "), str += std::to_string(x), str.append(";");
			str.append("\nx2 = (-("), str += std::to_string(b), str.append(") + "), str += std::to_string(D), str.append("^0.5) / (2*("), str += std::to_string(a), str.append("))");
			str.append(" = "), str += std::to_string(-b + sqrt(D)), str.append(" / ("), str += std::to_string(2 * a), str.append(") = "), str += std::to_string(x2), str.append(";\n");
		}
		str.append("\nОтвет: x1 = "), str += std::to_string(x), str.append("; x2 = "), str += std::to_string(x2), str.append(".\n\r");
	}
}

void calculation_x1_x2_2(double& x, double& x2, double a, double b, double D, bool flag)
{
	x = (-b - sqrt(D)) / (2 * a);
	x2 = (-b + sqrt(D)) / (2 * a);
	std::cout << "\nx1 = (-b - D^0.5) / (2*a);" << "\nx2 = (-b + D^0.5) / (2*a);\n";
	if (b > 0 && a > 0)
	{
		std::cout << "\nx1 = (" << -b << " - " << D << "^0.5) / (2*" << a << ")";
		std::cout << " = " << -b - sqrt(D) << " / " << 2 * a << " = " << x << ";";
		std::cout << "\nx2 = (" << -b << " + " << D << "^0.5) / (2*" << a << ")";
		std::cout << " = " << -b + sqrt(D) << " / " << 2 * a << " = " << x2 << ";\n";
	}
	else if (b < 0 && a > 0)
	{
		std::cout << "\nx1 = (-(" << b << ") - " << D << "^0.5) / (2*" << a << ")";
		std::cout << " = " << -b - sqrt(D) << " / " << 2 * a << " = " << x << ";";
		std::cout << "\nx2 = (-(" << b << ") + " << D << "^0.5) / (2*" << a << ")";
		std::cout << " = " << -b + sqrt(D) << " / " << 2 * a << " = " << x2 << ";\n";
	}
	else if (b > 0 && a < 0)
	{
		std::cout << "\nx1 = (" << -b << " - " << D << "^0.5) / (2*(" << a << "))";
		std::cout << " = " << -b - sqrt(D) << " / (" << 2 * a << ") = " << x << ";";
		std::cout << "\nx2 = (" << -b << " + " << D << "^0.5) / (2*(" << a << "))";
		std::cout << " = " << -b + sqrt(D) << " / (" << 2 * a << ") = " << x2 << ";\n";
	}
	else if (b < 0 && a < 0)
	{
		std::cout << "\nx1 = (-(" << b << ") - " << D << "^0.5) / (2*(" << a << "))";
		std::cout << " = " << -b - sqrt(D) << " / (" << 2 * a << ") = " << x << ";";
		std::cout << "\nx2 = (-(" << b << ") + " << D << "^0.5) / (2*(" << a << "))";
		std::cout << " = " << -b + sqrt(D) << " / (" << 2 * a << ") = " << x2 << ";\n";
	}
	std::cout << "\nОтвет: x1 = " << x << "; x2 = " << x2 << ".\n";
}

void app_txt_cal_x1i_x2i_2(double& x_real, double a, double b, double D, bool flag, double x1_i, double x2_i)
{
	if (flag)
	{
		str.append("D = "), str += std::to_string(int(abs(D))), str.append("*i^2 (где i - это мнимая единица, квадрат которой равняется -1)");
		str.append("\nx1_i = (-b - D^0.5) / (2*a);");
		str.append("\nx2_i = (-b + D^0.5) / (2*a);\n");
		if (b > 0 && a > 0)
		{
			str.append("\nx1_i = ("), str += std::to_string(int(-b)), str.append(" + ("), str += std::to_string(int(abs(D))), str.append("*i^2)^0.5) / (2*"), str += std::to_string(int(a)), str.append(")");
			str.append(" = "), str += std::to_string(int(x_real)), str.append(" + "), str += std::to_string(int(x1_i)), str.append("*i;");
			str.append("\nx2_i = ("), str += std::to_string(int(-b)), str.append(" - ("), str += std::to_string(int(abs(D))), str.append("*i^2)^0.5) / (2*"), str += std::to_string(int(a)), str.append(")");
			str.append(" = "), str += std::to_string(int(x_real)), str.append(" - "), str += std::to_string(int(abs(x2_i))), str.append("*i.");
			str += std::to_string(int(x_real)), str.append(" - "), str += std::to_string(int(abs(x2_i))), str.append("*i.\n");
		}
		else if (b < 0 && a > 0)
		{
			str.append("\nx1_i = (-("), str += std::to_string(int(b)), str.append(") + ("), str += std::to_string(int(abs(D))), str.append("*i^2)^0.5) / (2*"), str += std::to_string(int(a)), str.append(")");
			str.append(" = "), str += std::to_string(int(x_real)), str.append(" + "), str += std::to_string(int(x1_i)), str.append("*i;");
			str.append("\nx2_i = (-("), str += std::to_string(int(b)), str.append(") - ("), str += std::to_string(int(abs(D))), str.append("*i^2)^0.5) / (2*"), str += std::to_string(int(a)), str.append(")");
			str.append(" = "), str += std::to_string(int(x_real)), str.append(" - "), str += std::to_string(int(abs(x2_i))), str.append("*i.");
		}
		else if (b > 0 && a < 0)
		{
			str.append("\nx1_i = ("), str += std::to_string(int(-b)), str.append(" + ("), str += std::to_string(int(abs(D))), str.append("*i^2)^0.5) / (2*("), str += std::to_string(int(a)), str.append("))");
			str.append(" = "), str += std::to_string(int(x_real)), str.append(" + "), str += std::to_string(int(x1_i)), str.append("*i;");
			str.append("\nx2 = ("), str += std::to_string(int(-b)), str.append(" - ("), str += std::to_string(int(abs(D))), str.append("*i^2)^0.5) / (2*("), str += std::to_string(int(a)), str.append("))");
			str.append(" = "), str += std::to_string(int(x_real)), str.append(" - "), str += std::to_string(int(abs(x2_i))), str.append("*i.");
		}
		else if (b < 0 && a < 0)
		{
			str.append("\nx1_i = (-("), str += std::to_string(int(b)), str.append(") + ("), str += std::to_string(int(abs(D))), str.append("*i^2)^0.5) / (2*("), str += std::to_string(int(a)), str.append("))");
			str.append(" = "), str += std::to_string(int(x_real)), str.append(" + "), str += std::to_string(int(x1_i)), str.append("*i;");
			str.append("\nx2_i = (-("), str += std::to_string(int(b)), str.append(") - ("), str += std::to_string(int(abs((D)))), str.append("*i^2)^0.5) / (2*("), str += std::to_string(int(a)), str.append("))");
			str.append(" = "), str += std::to_string(int(x_real)), str.append(" - "), str += std::to_string(int(abs(x2_i))), str.append("*i.");
		}
		str.append("\nОтвет: x1_i = "), str += std::to_string(int(x_real)), str.append(" + "), str += std::to_string(int(x1_i)), str.append("*i; x2_i = "), str += std::to_string(x2_i), str.append("*i.\n\r");
	}
	else
	{
		str.append("D = "), str += std::to_string(abs(D)), str.append("*i^2 (где i - это мнимая единица, квадрат которой равняется -1)");
		str.append("\nx1_i = (-b - D^0.5) / (2*a);");
		str.append("\nx2_i = (-b + D^0.5) / (2*a);\n");
		if (b > 0 && a > 0)
		{
			str.append("\nx1_i = ("), str += std::to_string(-b), str.append(" + ("), str += std::to_string(abs(D)), str.append("*i^2)^0.5) / (2*"), str += std::to_string(a), str.append(")");
			str.append(" = "), str += std::to_string(x_real), str.append(" + "), str += std::to_string(x1_i), str.append("*i;");
			str.append("\nx2_i = ("), str += std::to_string(-b), str.append(" - ("), str += std::to_string(abs(D)), str.append("*i^2)^0.5) / (2*"), str += std::to_string(a), str.append(")");
			str.append(" = "), str += std::to_string(x_real), str.append(" - "), str += std::to_string(x2_i), str.append("*i.");
			str += std::to_string(x_real), str.append(" - "), str += std::to_string(abs(x2_i)), str.append("*i.\n");
		}
		else if (b < 0 && a > 0)
		{
			str.append("\nx1_i = (-("), str += std::to_string(b), str.append(") + ("), str += std::to_string(abs(D)), str.append("*i^2)^0.5) / (2*"), str += std::to_string(a), str.append(")");
			str.append(" = "), str += std::to_string(x_real), str.append(" + "), str += std::to_string(x1_i), str.append("*i;");
			str.append("\nx2_i = (-("), str += std::to_string(b), str.append(") - ("), str += std::to_string(abs(D)), str.append("*i^2)^0.5) / (2*"), str += std::to_string(a), str.append(")");
			str.append(" = "), str += std::to_string(x_real), str.append(" - "), str += std::to_string(abs(x2_i)), str.append("*i.");
		}
		else if (b > 0 && a < 0)
		{
			str.append("\nx1_i = ("), str += std::to_string(-b), str.append(" + ("), str += std::to_string(abs(D)), str.append("*i^2)^0.5) / (2*("), str += std::to_string(a), str.append("))");
			str.append(" = "), str += std::to_string(x_real), str.append(" + "), str += std::to_string(x1_i), str.append("*i;");
			str.append("\nx2 = ("), str += std::to_string(-b), str.append(" - ("), str += std::to_string(abs(D)), str.append("*i^2)^0.5) / (2*("), str += std::to_string(a), str.append("))");
			str.append(" = "), str += std::to_string(x_real), str.append(" - "), str += std::to_string(abs(x2_i)), str.append("*i.");
		}
		else if (b < 0 && a < 0)
		{
			str.append("\nx1_i = (-("), str += std::to_string(b), str.append(") + ("), str += std::to_string(abs(D)), str.append("*i^2)^0.5) / (2*("), str += std::to_string(a), str.append("))");
			str.append(" = "), str += std::to_string(x_real), str.append(" + "), str += std::to_string(x1_i), str.append("*i;");
			str.append("\nx2_i = (-("), str += std::to_string(b), str.append(") - ("), str += std::to_string(abs((D))), str.append("*i^2)^0.5) / (2*("), str += std::to_string(a), str.append("))");
			str.append(" = "), str += std::to_string(x_real), str.append(" - "), str += std::to_string(abs(x2_i)), str.append("*i.");
		}
		str.append("\nОтвет: x1_i = "), str += std::to_string(x_real), str.append(" + "), str += std::to_string(x1_i), str.append("*i; x2_i = "), str += std::to_string(x2_i), str.append("*i.\n\r");
	}
}

void calculation_x1i_x2i_2(double& x_real, double a, double b, double D, bool flag, double& x1_i, double& x2_i)
{
	std::cout << "D = " << abs(D) << "*i^2 (где i - это мнимая единица, квадрат которой равняется -1)";
	x_real = -b / (2 * a);
	x1_i = sqrt(abs(D)) / (2 * a);
	x2_i = -sqrt(abs(D)) / (2 * a);
	std::cout << "\nx1_i = (-b - D^0.5) / (2*a);";
	std::cout << "\nx2_i = (-b + D^0.5) / (2*a);\n";
	if (b > 0 && a > 0)
	{
		std::cout << "\nx1_i = (" << -b << " + (" << abs(D) << "*i^2)^0.5) / (2*" << a << ")";
		std::cout << " = " << x_real << " + " << x1_i << "*i;";
		std::cout << "\nx2_i = (" << -b << " - (" << abs(D) << "*i^2)^0.5) / (2*" << a << ")";
		std::cout << " = " << x_real << " - " << abs(x2_i) << "*i.";
	}
	else if (b < 0 && a > 0)
	{
		std::cout << "\nx1_i = (-(" << b << ") + (" << abs(D) << "*i^2)^0.5) / (2*" << a << ")";
		std::cout << " = " << x_real << " + " << x1_i << "*i;";
		std::cout << "\nx2_i = (-(" << b << ") - (" << abs(D) << "*i^2)^0.5) / (2*" << a << ")";
		std::cout << " = " << x_real << " - " << abs(x2_i) << "*i.";
	}
	else if (b > 0 && a < 0)
	{
		std::cout << "\nx1_i = (" << -b << " + (" << abs(D) << "*i^2)^0.5) / (2*(" << a << "))";
		std::cout << " = " << x_real << " + " << x1_i << "*i;";
		std::cout << "\nx2_i = (" << -b << " - (" << abs(D) << "*i^2)^0.5) / (2*(" << a << "))";
		std::cout << " = " << x_real << " - " << abs(x2_i) << "*i.";
	}
	else if (b < 0 && a < 0)
	{
		std::cout << "\nx1_i = (-(" << b << ") + (" << abs(D) << "*i^2)^0.5) / (2*(" << a << "))";
		std::cout << " = " << x_real << " + " << x1_i << "*i;";
		std::cout << "\nx2_i = (-(" << b << ") - (" << abs(D) << "*i^2)^0.5) / (2*(" << a << "))";
		std::cout << " = " << x_real << " - " << abs(x2_i) << "*i.";
	}
	std::cout << "\nОтвет: x1_i = " << x_real << " + " << x1_i << "*i; x2_i = " << x_real << " - " << abs(x2_i) << "*i.\n";
}

void equation_2()
{
	bool flag = false;
	double D, x = 0, x2 = 0, a = 0, b = 0, c = 0, x1_i = 0, x2_i = 0;
	SetColor(LightCyan, Black);
	input_factors_2(a, b, c, flag);
	app_txt_inp_fac_2(a, b, c, flag);
	if (a != 0)
	{
		calculation_dis(D, a, b, c, flag);
		app_txt_cal_dis(D, a, b, c, flag);
		if (D == 0)
		{
			calculation_x_2(x, a, b, c, flag);
			app_txt_cal_x_2(x, a, b, c, flag);
		}
		else if (D > 0)
		{
			calculation_x1_x2_2(x, x2, a, b, D, flag);
			app_txt_cal_x1_x2_2(x, x2, a, b, D, flag);
		}
		else
		{
			calculation_x1i_x2i_2(x, a, b, D, flag, x1_i, x2_i);
			app_txt_cal_x1i_x2i_2(x, a, b, D, flag, x1_i, x2_i);
		}
	}
	else
	{
		calculation_1(x, b, c, flag);
		app_txt_cal_1(x, b, c, flag);
	}
	pointer = 2;
}

void app_txt_inp_fac_3(double a, double b, double c, double d, bool& flag)
{
	if (a == round(a) && b == round(b) && c == round(c) && d == round(d))
		flag = true;
	str.append("Уравнение вида: a*x^3 + b*x^2 + c*x + d = 0\n");
	if (flag)
	{
		str.append("Введите коэффициент \'a\': "), str += std::to_string(int(a)), str += "\n";
		str.append("Введите коэффициент \'b\': "), str += std::to_string(int(b)), str += "\n";
		str.append("Введите коэффициент \'c\': "), str += std::to_string(int(c)), str += "\n";
		str.append("Введите коэффициент \'d\': "), str += std::to_string(int(d)), str += "\n";
		str += "\n", str += std::to_string(int(a)), str.append("*x^3 ");
		if (b >= 0)
			str.append("+ "), str += std::to_string(int(b)), str.append("*x^2 ");
		else
			str.append("- "), str += std::to_string(int(-b)), str.append("*x^2 ");
		if (c >= 0)
			str.append("+ "), str += std::to_string(int(c)), str.append("*x ");
		else
			str.append("- "), str += std::to_string(int(-c)), str.append("*x ");
		if (d >= 0)
			str.append("+ "), str += std::to_string(int(d)), str.append(" = 0\n");
		else
			str.append("- "), str += std::to_string(int(-d)), str.append(" = 0\n");
	}
	else
	{
		str.append("Введите коэффициент \'a\': "), str += std::to_string(a), str += "\n";
		str.append("Введите коэффициент \'b\': "), str += std::to_string(b), str += "\n";
		str.append("Введите коэффициент \'c\': "), str += std::to_string(c), str += "\n";
		str.append("Введите коэффициент \'d\': "), str += std::to_string(d), str += "\n";
		str += "\n", str += std::to_string(a), str.append("*x^3 ");
		if (b >= 0)
			str.append("+ "), str += std::to_string(b), str.append("*x^2 ");
		else
			str.append("- "), str += std::to_string(-b), str.append("*x^2 ");
		if (c >= 0)
			str.append("+ "), str += std::to_string(c), str.append("*x ");
		else
			str.append("- "), str += std::to_string(-c), str.append("*x ");
		if (d >= 0)
			str.append("+ "), str += std::to_string(d), str.append(" = 0\n");
		else
			str.append("- "), str += std::to_string(-d), str.append(" = 0\n");
	}
}

void input_factors_3(double& a, double& b, double& c, double& d, bool flag)
{
	std::cout << "Уравнение вида: a*x^3 + b*x^2 + c*x + d = 0\n";
	std::cout << "Введите коэффициент \'a\': ";
	a = input_num();
	std::cout << "\nВведите коэффициент \'b\': ";
	b = input_num();
	std::cout << "\nВведите коэффициент \'c\': ";
	c = input_num();
	std::cout << "\nВведите коэффициент \'d\': ";
	d = input_num();
	SetColor(Cyan, Black);
	std::cout << "\n\n" << a << "*x^3 ";
	if (b >= 0)
		std::cout << "+ " << b << "*x^2 ";
	else
		std::cout << "- " << -b << "*x^2 ";
	if (c >= 0)
		std::cout << "+ " << c << "*x ";
	else
		std::cout << "- " << -c << "*x ";
	if (d >= 0)
		std::cout << "+ " << d << " = 0\n";
	else
		std::cout << "- " << -d << " = 0\n";
}

void app_txt_cal_3(double a, double b, double c, double& d, bool& flag)
{
	double temp = (3 * c - (b * b)) / 9, temp_2 = -(27 * d) + b * (9 * c - 2 * (b * b));
	temp_2 /= 54.0;
	double temp_3 = temp_2 + sqrt(pow(temp, 3) + pow(temp_2, 2));
	if (temp == round(temp) && temp_2 == round(temp_2) && temp_3 == round(temp_3) && a == round(a) && b == round(b) && c == round(c) && d == round(d))
		flag = true;
	else
		flag = false;
	double disc, q, r, dum1, s, t, term1, r13, x1_real, x2_real, x3_real, x2_imag, x3_imag;
	q = (3.0 * c - (b * b)) / 9.0;
	r = -(27.0 * d) + b * (9.0 * c - 2.0 * (b * b)), r /= 54.0;
	disc = q * q * q + r * r;
	term1 = (b / 3.0);
	if (flag)
	{
		if (a != 1)
		{
			str.append("\nТак как коэф. \"a\" не равняется 1, то:\n");
			str.append("b = b / a = "), str += std::to_string(int(b_old)), str.append(" / "), str += std::to_string(int(a)), str.append(" = ");
			str += std::to_string(int(b)), str += "\n";
			str.append("c = c / a = "), str += std::to_string(int(c_old)), str.append(" / "), str += std::to_string(int(a)), str.append(" = ");
			str += std::to_string(int(c)), str += "\n";
			str.append("d = d / a = "), str += std::to_string(int(d_old)), str.append(" / "), str += std::to_string(int(a)), str.append(" = ");
			str += std::to_string(int(d)), str += "\n";
		}
		str.append("\nЧтобы расчитать корнии, нужно вычислить следуюшие значения: Q = (b^2-3*c)/9, R = (2*b^3-9*b*c+27*d)/54.\n");
		str.append("Q = "), str += std::to_string(int(q));
		str.append("\nR = "), str += std::to_string(int(r));
		str.append("\n\nДалее заводим следующий параметр D (дискриминант кубического уравнения), который вычисляется по формуле:\nD = Q^3 + R^2\n");
		str.append("При D > 0 имеется один действительный корень и два комплексных. При D <= 0 все корни действительные.\nD = "), str += std::to_string(int(disc));
		str.append("\n\nДобавим ещё один параметр Ter (промежуточное значение): Ter = b / 3\nTer = "), str += std::to_string(int(term1));
		if (disc > 0)
		{
			s = r + sqrt(disc);
			s = s < 0 ? -cbrt(-s) : cbrt(s);
			str.append("\n\nТак как D > 0, то для вычисление x понадобится ещё два параметра S и T\n");
			str.append("S = (R + D^(1/2))^(1/3) = "), str += std::to_string(int(s));
			t = r - sqrt(disc);
			t = t < 0 ? -cbrt(-t) : cbrt(t);
			str.append("\nT = (R - D^(1/2))^(1/3) = "), str += std::to_string(int(t)), str.append("\n\nВычисление действительного корня:");
			x1_real = -term1 + s + t;
			str.append("\nx1 = -Ter + S + T = "), str += std::to_string(int(x1_real));
			term1 += (s + t) / 2.0;
			str.append("\n\nВычисление комплексных корней:\nTer = Ter + (S + T) / 2 = "), str += std::to_string(int(term1)), str.append(";");
			if (term1 == 0)
				x3_real = x2_real = term1;
			else
				x3_real = x2_real = -term1;
			str.append("\nx2_r = x3_r = -Ter = "), str += std::to_string(int(x2_real));
			term1 = sqrt(3.0) * (-t + s) / 2;
			str.append("\nTer  = 3^(1/2)*(-T + S) / 2 = "), str += std::to_string(int(term1)), str.append(";");
			x2_imag = term1, x3_imag = -term1;
			str.append("\nx2_i = "), str += std::to_string(int(x2_imag)), str.append("\nx3_i = "), str += std::to_string(int(x3_imag)), str += "\n";
		}
		else if (disc == 0)
		{
			str.append("\n\nТак как D = 0, то комплексная часть равна 0.\n");
			x3_imag = x2_imag = 0;
			str.append("\nx2_i = 0; x3_i = 0;\n");
			r13 = r < 0 ? -cbrt(-r) : cbrt(r);
			str.append("\nВведём временную переменную t.\nt = R^(1/3) = "), str += std::to_string(int(r13)), str.append(";\n");
			x1_real = -term1 + 2.0 * r13;
			str.append("\nx1 = -Ter + 2*t = "), str += std::to_string(int(x1_real)), str.append(";\n");
			x3_real = x2_real = -(r13 + term1);
			str.append("x2 = -(t + Ter) = "), str += std::to_string(int(x2_real)), str.append(";\nx3 = -(t + Ter) = "), str += std::to_string(int(x3_real)), str.append(";\n");
		}
		else
		{
			str.append("\n\nТак как D < 0, то комплексная часть равна 0 и все корни различны.\n");
			x3_imag = x2_imag = 0;
			str.append("\nx2_i = 0; x3_i = 0;\n");
			q = -q;
			str.append("Q = -Q;\n");
			dum1 = q * q * q;
			dum1 = acos(r / sqrt(dum1));
			r13 = 2.0 * sqrt(q);
			str.append("\nДобавим две переменные Dum и t:\nt = 2*R^(1/2) = "), str += std::to_string(int(r13)), str.append(";\nDum = arccos(t / Q^3) = "), str += std::to_string(int(dum1)), str.append(";\n");
			x1_real = -term1 + r13 * cos(dum1 / 3.0);
			str.append("\nx1 = -Ter + t * cos(Dum / 3) = "), str += std::to_string(int(x1_real)), str.append(";\n");
			x2_real = -term1 + r13 * cos((dum1 + 2.0 * M_PI) / 3.0);
			str.append("x2 = -Ter + t * cos(Dum  + 2*PI) / 3 = "), str += std::to_string(int(x2_real)), str.append(";\n");
			x3_real = -term1 + r13 * cos((dum1 + 4.0 * M_PI) / 3.0);
			str.append("x3 = -Ter + t * cos(Dum + 4*PI) / 3 = "), str += std::to_string(int(x3_real)), str.append(";\n");
		}
		if (x2_imag != 0 && x3_imag != 0)
		{
			str.append("\nОтвет: x1 = "), str += std::to_string(int(x1_real)), str.append("; x2 = "), str += std::to_string(int(x2_real)), str.append(" + "), str += std::to_string(int(x2_imag));
			str.append("*i; x3 = "), str += std::to_string(int(x3_real)), str.append(" + "), str += std::to_string(int(x3_imag)), str.append("*i.\n\r");
		}
		else
		{
			str.append("\nОтвет: x1 = "), str += std::to_string(int(x1_real)), str.append("; x2 = "), str += std::to_string(int(x2_real));
			str.append("; x3 = "), str += std::to_string(int(x3_real)), str.append(".\n\r");
		}
	}
	else
	{
		if (a != 1)
		{
			str.append("\nТак как коэф. \"a\" не равняется 1, то:\n");
			str.append("b = b / a = "), str += std::to_string(b), str.append(" / "), str += std::to_string(a), str.append(" = ");
			str += std::to_string(b), str += "\n";
			str.append("c = c / a = "), str += std::to_string(c), str.append(" / "), str += std::to_string(a), str.append(" = ");
			str += std::to_string(c), str += "\n";
			str.append("d = d / a = "), str += std::to_string(d), str.append(" / "), str += std::to_string(a), str.append(" = ");
			str += std::to_string(d), str += "\n";
		}
		str.append("\nЧтобы расчитать корнии, нужно вычислить следуюшие значения: Q = (b^2-3*c)/9, R = (2*b^3-9*b*c+27*d)/54.\n");
		str.append("Q = "), str += std::to_string(q);
		str.append("\nR = "), str += std::to_string(r);
		str.append("\n\nДалее заводим следующий параметр D (дискриминант кубического уравнения), который вычисляется по формуле:\nD = Q^3 + R^2\n");
		str.append("При D > 0 имеется один действительный корень и два комплексных. При D <= 0 все корни действительные.\nD = "), str += std::to_string(disc);
		str.append("\n\nДобавим ещё один параметр Ter (промежуточное значение): Ter = b / 3\nTer = "), str += std::to_string(term1);
		if (disc > 0)
		{
			s = r + sqrt(disc);
			s = s < 0 ? -cbrt(-s) : cbrt(s);
			str.append("\n\nТак как D > 0, то для вычисление x понадобится ещё два параметра S и T\n");
			str.append("S = (R + D^(1/2))^(1/3) = "), str += std::to_string(s);
			t = r - sqrt(disc);
			t = t < 0 ? -cbrt(-t) : cbrt(t);
			str.append("\nT = (R - D^(1/2))^(1/3) = "), str += std::to_string(t), str.append("\n\nВычисление действительного корня:");
			x1_real = -term1 + s + t;
			str.append("\nx1 = -Ter + S + T = "), str += std::to_string(x1_real);
			term1 += (s + t) / 2.0;
			str.append("\n\nВычисление комплексных корней:\nTer = Ter + (S + T) / 2 = "), str += std::to_string(term1), str.append(";");
			if (term1 == 0)
				x3_real = x2_real = term1;
			else
				x3_real = x2_real = -term1;
			str.append("\nx2_r = x3_r = -Ter = "), str += std::to_string(x2_real);
			term1 = sqrt(3.0) * (-t + s) / 2;
			str.append("\nTer  = 3^(1/2)*(-T + S) / 2 = "), str += std::to_string(term1), str.append(";");
			x2_imag = term1, x3_imag = -term1;
			str.append("\nx2_i = "), str += std::to_string(x2_imag), str.append("\nx3_i = "), str += std::to_string(x3_imag), str += "\n";
		}
		else if (disc == 0)
		{
			str.append("\n\nТак как D = 0, то комплексная часть равна 0.\n");
			x3_imag = x2_imag = 0;
			str.append("\nx2_i = 0; x3_i = 0;\n");
			r13 = r < 0 ? -cbrt(-r) : cbrt(r);
			str.append("\nВведём временную переменную t.\nt = R^(1/3) = "), str += std::to_string(r13), str.append(";\n");
			x1_real = -term1 + 2.0 * r13;
			str.append("\nx1 = -Ter + 2*t = "), str += std::to_string(x1_real), str.append(";\n");
			x3_real = x2_real = -(r13 + term1);
			str.append("x2 = -(t + Ter) = "), str += std::to_string(x2_real), str.append(";\nx3 = -(t + Ter) = "), str += std::to_string(x3_real), str.append(";\n");
		}
		else
		{
			str.append("\n\nТак как D < 0, то комплексная часть равна 0 и все корни различны.\n");
			x3_imag = x2_imag = 0;
			str.append("\nx2_i = 0; x3_i = 0;\n");
			q = -q;
			str.append("Q = -Q;\n");
			dum1 = q * q * q;
			dum1 = acos(r / sqrt(dum1));
			r13 = 2.0 * sqrt(q);
			str.append("\nДобавим две переменные Dum и t:\nt = 2*R^(1/2) = "), str += std::to_string(r13), str.append(";\nDum = arccos(t / Q^3) = "), str += std::to_string(dum1), str.append(";\n");
			x1_real = -term1 + r13 * cos(dum1 / 3.0);
			str.append("\nx1 = -Ter + t * cos(Dum / 3) = "), str += std::to_string(x1_real), str.append(";\n");
			x2_real = -term1 + r13 * cos((dum1 + 2.0 * M_PI) / 3.0);
			str.append("x2 = -Ter + t * cos(Dum  + 2*PI) / 3 = "), str += std::to_string(x2_real), str.append(";\n");
			x3_real = -term1 + r13 * cos((dum1 + 4.0 * M_PI) / 3.0);
			str.append("x3 = -Ter + t * cos(Dum + 4*PI) / 3 = "), str += std::to_string(x3_real), str.append(";\n");
		}
		if (x2_imag != 0 && x3_imag != 0)
		{
			str.append("\nОтвет: x1 = "), str += std::to_string(x1_real), str.append("; x2 = "), str += std::to_string(x2_real), str.append(" + "), str += std::to_string(x2_imag);
			str.append("*i; x3 = "), str += std::to_string(x3_real), str.append(" + "), str += std::to_string(x3_imag), str.append("*i.\n\r");
		}
		else
		{
			str.append("\nОтвет: x1 = "), str += std::to_string(x1_real), str.append("; x2 = "), str += std::to_string(x2_real);
			str.append("; x3 = "), str += std::to_string(x3_real), str.append(".\n\r");
		}
	}
}

void calculation_3(double& a, double& b, double& c, double& d, bool flag)
{
	b_old = b, c_old = c, d_old = d;
	if (a != 1)
	{
		std::cout << "\nТак как коэф. \"a\" не равняется 1, то:\n";
		std::cout << "b = b / a = " << b << " / " << a << " = ";
		b /= a, std::cout << b << std::endl;
		std::cout << "c = c / a = " << c << " / " << a << " = ";
		c /= a, std::cout << c << std::endl;
		std::cout << "d = d / a = " << d << " / " << a << " = ";
		d /= a, std::cout << d << std::endl;
	}
	double disc, q, r, dum1, s, t, term1, r13;
	std::cout << "\nЧтобы расчитать корнии, нужно вычислить следуюшие значения: Q = (b^2-3*c)/9, R = (2*b^3-9*b*c+27*d)/54.\n";
	q = (3.0 * c - (b * b)) / 9.0;
	std::cout << "Q = " << q;
	r = -(27.0 * d) + b * (9.0 * c - 2.0 * (b * b));
	r /= 54.0;
	std::cout << "\nR = " << r;
	disc = q * q * q + r * r;
	std::cout << "\n\nДалее заводим следующий параметр D (дискриминант кубического уравнения), который вычисляется по формуле:\nD = Q^3 + R^2\n";
	std::cout << "При D > 0 имеется один действительный корень и два комплексных. При D <= 0 все корни действительные.\nD = " << disc;
	term1 = (b / 3.0);
	std::cout << "\n\nДобавим ещё один параметр Ter (промежуточное значение): Ter = b / 3\nTer = " << term1;

	double x1_real, x2_real, x3_real, x2_imag, x3_imag;
	if (disc > 0)   // Один корень действительный, два комплексных
	{
		std::cout << "\n\nТак как D > 0, то для вычисление x понадобится ещё два параметра S и T\n";
		s = r + sqrt(disc);
		s = s < 0 ? -cbrt(-s) : cbrt(s);
		std::cout << "S = (R + D^(1/2))^(1/3) = " << s;
		t = r - sqrt(disc);
		t = t < 0 ? -cbrt(-t) : cbrt(t);
		std::cout << "\nT = (R - D^(1/2))^(1/3) = " << t << "\n\nВычисление действительного корня:";
		x1_real = -term1 + s + t;
		std::cout << "\nx1 = -Ter + S + T = " << x1_real;
		term1 += (s + t) / 2.0;
		std::cout << "\n\nВычисление комплексных корней:\nTer = Ter + (S + T) / 2 = " << term1 << ";";
		if (term1 == 0)
			x3_real = x2_real = term1;
		else
			x3_real = x2_real = -term1;
		std::cout << "\nx2_r = x3_r = -Ter = " << x2_real;
		term1 = sqrt(3.0) * (-t + s) / 2;
		std::cout << "\nTer  = 3^(1/2)*(-T + S) / 2 = " << term1 << ";";
		x2_imag = term1;
		x3_imag = -term1;
		std::cout << "\nx2_i = " << x2_imag << "\nx3_i = " << x3_imag << std::endl;
	}
	// Остальные корни действительные
	else if (disc == 0)  // Все корни действительны и два равны
	{
		std::cout << "\n\nТак как D = 0, то комплексная часть равна 0.\n";
		x3_imag = x2_imag = 0;
		std::cout << "\nx2_i = 0; x3_i = 0;\n";
		r13 = r < 0 ? -cbrt(-r) : cbrt(r);
		std::cout << "\nВведём временную переменную t.\nt = R^(1/3) = " << r13 << ";\n";
		x1_real = -term1 + 2.0 * r13;
		std::cout << "\nx1 = -Ter + 2*t = " << x1_real << ";\n";
		x3_real = x2_real = -(r13 + term1);
		std::cout << "x2 = -(t + Ter) = " << x2_real << ";\nx3 = -(t + Ter) = " << x3_real << ";\n";
	}
	// Единственный оставшийся вариант - все корни действительны и неравны (чтобы попасть сюда, q < 0)
	else
	{
		std::cout << "\n\nТак как D < 0, то комплексная часть равна 0 и все корни различны.\n";
		x3_imag = x2_imag = 0;
		std::cout << "\nx2_i = 0; x3_i = 0;\n";
		q = -q;
		std::cout << "Q = -Q;\n";
		dum1 = q * q * q;
		dum1 = acos(r / sqrt(dum1));
		r13 = 2.0 * sqrt(q);
		std::cout << "\nДобавим две переменные Dum и t:\nt = 2*R^(1/2) = " << r13 << ";\nDum = arccos(t / Q^3) = " << dum1 << ";\n";
		x1_real = -term1 + r13 * cos(dum1 / 3.0);
		std::cout << "\nx1 = -Ter + t * cos(Dum / 3) = " << x1_real << ";\n";
		x2_real = -term1 + r13 * cos((dum1 + 2.0 * M_PI) / 3.0);
		std::cout << "x2 = -Ter + t * cos(Dum  + 2*PI) / 3 = " << x2_real << ";\n";
		x3_real = -term1 + r13 * cos((dum1 + 4.0 * M_PI) / 3.0);
		std::cout << "x3 = -Ter + t * cos(Dum + 4*PI) / 3 = " << x3_real << ";\n";
	}
	if (x2_imag != 0 && x3_imag != 0)
		std::cout << "\nОтвет: x1 = " << x1_real << "; x2 = " << x2_real << " + " << x2_imag << "*i; x3 = " << x3_real << " + " << x3_imag << "*i.\n";
	else
		std::cout << "\nОтвет: x1 = " << x1_real << "; x2 = " << x2_real << "; x3 = " << x3_real << ".\n";
}

void equation_3()
{
	bool flag = false;
	double a, b, c, d, p, q, s, f, x1, x2, x3, x2i, x3i;
	SetColor(LightCyan, Black);
	input_factors_3(a, b, c, d, flag);
	app_txt_inp_fac_3(a, b, c, d, flag);
	calculation_3(a, b, c, d, flag);
	app_txt_cal_3(a, b, c, d, flag);
	pointer = 3;
}

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
			save_f(str);
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

void request_matrix()
{
	bool flag = true;
	SetColor(Red, Black);
	std::cout << "\nДля выхода нажмите ESC\n" << "Для сохранения решения нажмите S\n";
	do
	{
		int num_but = _getch();
		if (num_but == 115)
			num_but = 83;
		switch (num_but)
		{
		case 27:
			mark = false, flag = false;
			PlaySound(TEXT("beep_exit"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		case 83:
			mark = false;
			save_f(str);
			break;
		default:
			break;
		}
	} while (flag);
}

void request_load()
{
	bool flag = true;
	SetColor(Red, Black);
	std::cout << "\nДля выхода нажмите ESC\n";
	do
	{
		int num_but = _getch();
		switch (num_but)
		{
		case 27:
			mark = false, flag = false;
			PlaySound(TEXT("beep_exit"), NULL, SND_ASYNC | SND_FILENAME);
			break;
		default:
			break;
		}
	} while (flag);
}

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

void act_matrix_case_1()
{
	system("cls");
	PlaySound(TEXT("beep_choose"), NULL, SND_ASYNC | SND_FILENAME);
	Sleep(100);
	matrix_input();
}

void act_matrix_case_2()
{
	system("cls");
	PlaySound(TEXT("beep_choose"), NULL, SND_ASYNC | SND_FILENAME);
	Sleep(100);
	visual(-1, menusize + 2);
	write_matrix();
	app_txt_matrix();
	std::cout << "\nРанг: " << _rank1 << std::endl;
	str.append("\nРанг: "), str += std::to_string(int(_rank1)), str += "\n\r";
	request_matrix();
	str.clear();
}

void act_matrix_case_3()
{
	system("cls");
	PlaySound(TEXT("beep_choose"), NULL, SND_ASYNC | SND_FILENAME);
	Sleep(100);
	visual(-1, menusize + 2);
	write_matrix();
	app_txt_matrix();
	std::cout << "\nДетерминант: " << determinant << std::endl;
	str.append("\nДетерминант: "), str += std::to_string(int(determinant)), str += "\n\r";
	request_matrix();
	str.clear();
}

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
		std::cout << "\nОбратная матрица не найдена\n", str.append("\nОбратная матрица не найдена\n\r");
		request_matrix();
		return true;
	}
	inverse_matrix();
	app_txt_inverse_mat();
	request_matrix();
	str.clear();
	return false;
}

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
				str.clear();
				break;
			case 2:
				system("cls");
				PlaySound(TEXT("beep_choose"), NULL, SND_ASYNC | SND_FILENAME);
				Sleep(100);
				equation_2();
				request_equation();
				str.clear();
				break;
			case 3:
				system("cls");
				PlaySound(TEXT("beep_choose"), NULL, SND_ASYNC | SND_FILENAME);
				Sleep(100);
				equation_3();
				request_equation();
				str.clear();
				break;
			}
		}
	} while (true);
}

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

void menu_main()
{
	int num_but;
	if (key > 3)
		key = 3;;
	do
	{
		system("cls");
		output_text_menu_main();
		SetColor(Cyan, Black);
		num_but = _getch();
		if (num_but == 224)
			num_but = _getch();
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
			exit(0);
			break;
		case ENTER:
			switch (key)
			{
			case 1:
				system("cls");
				PlaySound(TEXT("beep_choose"), NULL, SND_ASYNC | SND_FILENAME);
				Sleep(100);
				menu_equations();
				break;
			case 2:
				system("cls");
				PlaySound(TEXT("beep_choose"), NULL, SND_ASYNC | SND_FILENAME);
				Sleep(100);
				key = 1;
				menu_matrix();
				break;
			case 3:
				system("cls");
				PlaySound(TEXT("beep_choose"), NULL, SND_ASYNC | SND_FILENAME);
				Sleep(100);
				load_f();
				request_load();
				break;
			}
		}
	} while (true);
}
