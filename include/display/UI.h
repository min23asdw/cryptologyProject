#include<iostream>
#include<windows.h>
#include<conio.h>
#include<vector>

using std::string;
using std::vector;

class UI
{
private:
	struct MenuItem
	{
		MenuItem() : name(""), color(7) {}
		string name;
		int color;
	};

	MenuItem menuItem;
	vector<MenuItem> menuItems;

public:
	UI() {}

	int menu(string header);
	void addMenuItems(string name, int color);
	void gotoxy(int x, int y);
	void color(int color);
	void clearScreen();
	COORD GetConsoleCursorPosition(HANDLE hConsoleOutput);
	void setBeginPos(int x, int y);
};
