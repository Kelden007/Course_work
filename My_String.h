#pragma once

#include <string>
#include "save_f.h"

class My_Str
{
private:
	std::string Str = "";
public:
	void app(std::string stack);
	void app_num(int number);
	void app_num(float number);	
	void app_num(double number);
	void endl();
	void save();
	void clear_str();
};

My_Str str;