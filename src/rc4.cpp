#include "rc4Main.h"
#include "rc4system.h"

void rc4Main::run() {
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);
	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1280, 720, TRUE);
	rc4System rc4;
	rc4Menu menu;
	while (true) {
		int mode = menu.RC4menu();
		if (mode == 2) {
			rc4.modeEncrypt(); // Run Encrypt Mode
		}
		if (mode == 3) {
			rc4.modeDecrypt(); // Run Decrypt Mode
		}
	}
}