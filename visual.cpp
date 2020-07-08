#include "visual.h"

void visual(int i, int j)
{
	HANDLE consoleOutput;
	COORD cursorPos;
	consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	cursorPos.X = i;
	cursorPos.Y = j;
	SetConsoleCursorPosition(consoleOutput, cursorPos);
}