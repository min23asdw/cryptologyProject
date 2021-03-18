#pragma once
#include<iostream>
#include<windows.h>
#include<conio.h>

class rc4Menu { //Menu
public:
	void NextAlgor();
	void gotoxy(int, int);
	void color(int);
	void backToMenu();
	void whatIsRC4();
	int RC4menu();
};
