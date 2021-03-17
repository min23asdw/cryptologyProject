#include "rc4menu.h"

using namespace std;

// Delay for Next Algorithm
void rc4Menu::NextAlgor() {
	Sleep(250);
	cout << endl << endl;
	Sleep(250);
	cout << "___________________________________________________________________________________" << endl << endl;
	Sleep(500);
	cout << ".";
	Sleep(250);
	cout << " . ";
	Sleep(250);
	cout << ". ";
	Sleep(250);
	cout << " > ";
	Sleep(500);
}

void rc4Menu::color(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void rc4Menu::gotoxy(int x, int y) {
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void rc4Menu::whatIsRC4() {
	int page = 1;
	char select;
	system("cls");
	color(7);
	gotoxy(5, 2);
	cout << "What is RC4?";
	for (int i = 0;;) {

		if (page == 1) {
			system("cls");
			gotoxy(5, 2);
			cout << "What is RC4?";
			gotoxy(10, 4);
			cout << "RC4 was designed in 1987 by Ron Rivest and is one of the most widely software stream cipher and used";
			gotoxy(10, 5);
			cout << "in popular protocols, such as SSL (protect Internet traffic), WEP (secure wireless networks) and PDF.";
			gotoxy(10, 6);
			cout << "It's considered to be fast and simple in terms of software.";
			gotoxy(10, 8);
			cout << "RC4 generates a pseudo-random stream of bits (a key-stream). As with any stream cipher,";
			gotoxy(10, 9);
			cout << "these can be used for encryption by combining it with the plaintext using bit-wise exclusive-or.";
			gotoxy(10, 10);
			cout << "Decryption is performed the same way (since exclusive-or is a symmetric operation).";
			gotoxy(5, 24);
			color(12); // red color
			cout << "Page 1 of 3 | (Press left arrow to back , right arrow to next , Q to main menu)";
			color(7); // white color
		}
		if (page == 2) {
			system("cls");
			gotoxy(5, 2);
			cout << "Working of RC4";
			gotoxy(7, 4);
			cout << "Encryption Procedure";
			gotoxy(10, 6);
			cout << "1. The user inputs a plain text file and a secret key.";
			gotoxy(10, 7);
			cout << "2. The encryption engine then generates the keystream by using KSA and PRGA Algorithm.";
			gotoxy(10, 8);
			cout << "3. This keystream is now XOR with the plain text";
			gotoxy(10, 9);
			cout << "   this XORing is done byte by byte to produce the encrypted text.";
			gotoxy(10, 10);
			cout << "4. The encrypted text is then sent to the intended receiver";
			gotoxy(10, 11);
			cout << "   the intended receiver will then decrypted the text and after decryption, the";
			gotoxy(10, 12);
			cout << "   receiver will get the original plain text.";
			gotoxy(7, 14);
			cout << "Decryption Procedure";
			gotoxy(10, 16);
			cout << "Decryption is achieved by doing the same byte-wise X-OR operation on the Ciphertext. ";
			gotoxy(10, 18);
			cout << "Example: Let A be the plain text and B be the keystream (A xor B) xor B = A ";
			gotoxy(5, 24);
			color(12);
			cout << "Page 2 of 3 | (Press left arrow to back , right arrow to next , Q to main menu)";
			color(7);

		}
		if (page == 3) {
			system("cls");
			gotoxy(5, 2);
			cout << "RC4 Block Diagram";
			gotoxy(10, 4);
			cout << "...............................................................................";
			gotoxy(10, 5);
			cout << ".                                                                             .";
			gotoxy(10, 6);
			cout << ".                          [      SECRET KEY      ]                           .";
			gotoxy(10, 7);
			cout << ".                                     |                                       .";
			gotoxy(10, 8);
			cout << ".                                     |                                       .";
			gotoxy(10, 9);
			cout << ".                                     V                                       .";
			gotoxy(10, 10);
			cout << ".                          [         RC4          ]                           .";
			gotoxy(10, 11);
			cout << ".                                     |                                       .";
			gotoxy(10, 12);
			cout << ".                                     |                                       .";
			gotoxy(10, 13);
			cout << ".                                     V                                       .";
			gotoxy(10, 14);
			cout << ".                          [      Keystream       ]                           .";
			gotoxy(10, 15);
			cout << ".                                     |                                       .";
			gotoxy(10, 16);
			cout << ".                                     |                                       .";
			gotoxy(10, 17);
			cout << ".    [-----------------]              V               [------------------]    .";
			gotoxy(10, 18);
			cout << ".    [    Plain Text   ]---------->[  +  ]----------->[  Encrypted Text  ]    .";
			gotoxy(10, 19);
			cout << ".    [-----------------]                              [------------------]    .";
			gotoxy(10, 20);
			cout << ".                                                                             .";
			gotoxy(10, 21);
			cout << "...............................................................................";
			gotoxy(5, 24);
			color(12);
			cout << "Page 3 of 3 | (Press left arrow to back , right arrow to next , Q to main menu)";
			color(7);
		}

		select = _getch();

		if (select == 75 && (page >= 2 && page <= 3)) {   // 75 = left arrow key
			page--;
		}
		if (select == 77 && (page >= 1 && page <= 2)) {   // 77 = right arrow key
			page++;
		}
		if (select == 'Q' || select == 'q') {
			backToMenu();
			break;
		}


	}

}


int rc4Menu::RC4menu() {

	int Set[] = { 7,7,7 }; // Default colors
	system("cls");
	int counter = 1;
	char select;
	gotoxy(5, 2);
	Set[0] = 12;
	cout << "The RC4 Algorithm (Use arrow key to select the menu)" << endl << endl;
	for (int i = 0;;) {


		gotoxy(10, 5);
		color(Set[0]);
		cout << "1. What is RC4?";

		gotoxy(10, 6);
		color(Set[1]);
		cout << "2. Encryption";

		gotoxy(10, 7);
		color(Set[2]);
		cout << "3. Decryption";

		select = _getch();

		if (select == 72 && (counter >= 2 && counter <= 3)) {   // 72 = up arrow key
			counter--;
		}
		if (select == 80 && (counter >= 1 && counter <= 2)) {   // 80 = down arrow key
			counter++;
		}
		if (select == '\r') //carriage return = enter key
		{
			if (counter == 1) {
				whatIsRC4();
				break;
			}
			if (counter == 2) {
				return 2;
			}
			if (counter == 3) {
				return 3;
			}
		}
		Set[0] = 7;
		Set[1] = 7;
		Set[2] = 7;
		if (counter == 1) {
			Set[0] = 12; // 12 is color red
		}
		if (counter == 2) {
			Set[1] = 12; // 12 is color red
		}
		if (counter == 3) {
			Set[2] = 12; // 12 is color red
		}


	}
}

void rc4Menu::backToMenu() {
	RC4menu();
}
