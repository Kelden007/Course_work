#include "My_String.h"

void My_Str::app(std::string stack)
{
	Str.append(stack);
}
void My_Str::app_num(int number)
{
	Str += std::to_string(number);
}
void My_Str::app_num(float number)
{
	Str += std::to_string(number);
}
void My_Str::app_num(double number)
{
	Str += std::to_string(number);
}
void My_Str::endl()
{
	Str += '\n';
}
void My_Str::save()
{
	save_f(Str);
}
void My_Str::clear_str()
{
	Str.clear();
}