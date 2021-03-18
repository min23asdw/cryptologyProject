#include "UI.h"
#include "rc4Main.h"
#include "stegMain.h"
#include "enigmaMain.h"

using namespace std;

int main()
{
	UI mainUI;

	rc4Main rc4;
	stegMain steg;
	enigmaMain enigma;

	mainUI.addMenuItems("Enigma", 7);
	mainUI.addMenuItems("RC4", 7);
	mainUI.addMenuItems("RSA", 7);
	mainUI.addMenuItems("Steganography", 7);

	int menuRes = mainUI.menu("Main Menu");
	mainUI.clearScreen();

	if (menuRes == 0)
	{
		enigma.run();
	}

	if (menuRes == 1)
	{
		rc4.run();
	}

	if (menuRes == 2)
	{

	}

	if (menuRes == 3)
	{
		steg.run();
	}
	return 0;
}