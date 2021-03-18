#pragma once
#include "stegMain.h"
#include "convertPPM.h"
#include "stegPPM.h"
#include "UI.h"

using std::cout;
using std::cin;
using std::string;

void stegMain::run()
{
	stegPPM steg;
	convertPPM encodeFile;
	convertPPM decodeFile;
	UI stegUI;
	const vector<string> textFileName
	{
		"resources/steg1.txt",
		"resources/steg2.txt",
		"resources/steg3.txt"
	};

	const vector<string> headings
	{
		"Intro",
		"History",
		"How it works?"
	};

	stegUI.addMenuItems("What is steganography?", 7);
	stegUI.addMenuItems("Encode", 7);
	stegUI.addMenuItems("Decode", 7);

	int menuRes = stegUI.menu("Steganography");

	if (menuRes == 0)
	{
		stegUI.textPage(textFileName, headings);
	}

	/*int menu = -1;
	string input = "";
	while (true)
	{
		cout << "Enter 0 to hide a message (Encode)" << '\n';
		cout << "Enter 1 to reveal a message (Decode)" << '\n';
		cout << "------------------------------------------" << '\n';
		getline(cin, input);
		menu = stoi(input);

		while (menu == 0)
		{
			string filename = "";
			string dataToHide = "";

			while (filename == "")
			{
				cout << '\n';
				cout << "ENCODING------------------------------------------" << '\n';
				cout << "Please input your image file name to be used as a cover image."
					<< "\n";
				cout << "ex. <img.ppm>, <testImg/img.ppm>, <img.jpg>"
					<< "\n\n";
				getline(cin, filename);
				encodeFile.convertToPPM(filename);
				cout << "------------------------------------------" << '\n';
			}
			while (dataToHide == "")
			{
				cout << "Please input your message, you wish to hide inside an image..."
					<< "\n";
				getline(cin, dataToHide);
				cout << "------------------------------------------" << '\n';
			}

			if (steg.encode(filename, dataToHide))
			{
				encodeFile.saveToSameFormat();
				cout << "Encoding Succeed"
					<< "\n";
				cout << "------------------------------------------" << '\n';
				break;
			}
			cout << "------------------------------------------" << '\n';
			break;
		}
		while (menu == 1)
		{
			string filename = "";
			int length = 0;
			string hiddenMsg = "";

			while (filename == "")
			{
				cout << '\n';
				cout << "DECODING------------------------------------------" << '\n';
				cout << "Please input your image file name to decode a hidden message."
					<< "\n";
				cout << "ex. <img.ppm>, <testImg/img.ppm>"
					<< "\n\n";
				getline(cin, filename);
				decodeFile.convertToPPM(filename);
				cout << "------------------------------------------" << '\n';
			}

			while (length == 0)
			{
				cout << "Please input your expected length of the hidden message."
					<< "\n";
				getline(cin, input);
				cout << "------------------------------------------" << '\n';
				length = stoi(input);
			}

			hiddenMsg = steg.decodeMsg(filename, length);
			if (hiddenMsg == "")
			{
				cout << "Cannot find hidden message."
					<< "\n";
				cout << "------------------------------------------" << '\n';
				continue;
			}

			cout << "Decoding Succeed"
				<< "\n";
			cout << "Your hidden message is \n";
			cout << hiddenMsg << "\n";
			cout << "------------------------------------------" << '\n';
			break;
		}
	}*/
}