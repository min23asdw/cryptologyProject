#include "UI.h"

using namespace std;

int UI::menu(string header)
{
	int itemsSize = menuItems.size();
	int inactiveColor = 7; // Default colors
	int activeColor = 12; // 12 is red color
	int counter = 0;
	char select;

	setBeginPos(5, 2);
	int beginY = GetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE)).Y;

	cout << header << " (Use arrow key to select)" << endl << endl;
	menuItems[0].color = activeColor;

	while (true) {
		for (int i = 0; i < itemsSize; i++)
		{
			gotoxy(10, 2 + beginY + i);
			color(menuItems[i].color);
			cout << i + 1 << ". " << menuItems[i].name;
		}

		select = _getch();

		if (select == 72 && counter > 0) // 72 = up arrow key
		{
			menuItems[counter].color = inactiveColor;
			counter--;
			menuItems[counter].color = activeColor;
		}

		if (select == 80 && counter < itemsSize - 1) // 80 = down arrow key
		{
			menuItems[counter].color = inactiveColor;
			counter++;
			menuItems[counter].color = activeColor;
		}

		if (select == '\r') //carriage return = enter key
		{
			return counter;
		}
	}
}

void UI::addMenuItems(string name = "", int color = 7)
{
	MenuItem item;
	item.name = name;
	item.color = color;
	menuItems.push_back(item);
}


void UI::gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void UI::setBeginPos(int x, int y)
{
	COORD c = GetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE));
	c.X = x;
	c.Y += y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void UI::color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void UI::clearScreen()
{
	system("cls");
	color(7);
}


COORD UI::GetConsoleCursorPosition(HANDLE hConsoleOutput)
{
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi))
	{
		return cbsi.dwCursorPosition;
	}
	else
	{
		// The function failed. Call GetLastError() for details.
		COORD invalid = { 0, 0 };
		return invalid;
	}
}