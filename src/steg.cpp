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
	stegUI.addMenuItems("Exit to main menu", 7);

	int menu = -1;
	string input = "";
	while (true)
	{
		int menuRes = stegUI.menu("Steganography");
		bool textRes;

		if (menuRes == 0)
		{
			textRes = stegUI.textPage(textFileName, headings);
			if (textRes)
			{
				stegUI.clearScreen();
				continue;
			}
		}

		if (menuRes == 3)
		{
			stegUI.clearScreen();
			break;
		}

		while (menuRes == 1)
		{
			stegUI.clearScreen();
			string filename = "";
			string dataToHide = "";

			while (filename == "")
			{
				stegUI.clearScreen();
				cout << "Please create folder <ppm> and <steg>, if they don't exist." << '\n';
				cout << "Supported file types are bmp, ppm, pbm, NetPbM." << '\n';
				cout << "If you want to use other file types, please convert the file.\nUse this link: https://www.online-utility.org/image/convert/to/PPM" << '\n';
				cout << '\n';
				cout << "[ ENCODING ]" << '\n';
				cout << "Please input your image file name to be used as a cover image."
					<< "\n";
				cout << "ex. <img.ppm>, <testImg/img.ppm>, <img.bmp>"
					<< "\n\n";
				getline(cin, filename);
				encodeFile.convertToPPM(filename);
				cout << "------------------------------------------" << '\n';
				cout << "PPM (Portable Pixel Map) is used as an intermediary format. PPM-P6 stores color channels (red, green, blue) in binary format.\nThis will make it simple for us to read this file and change the least significant bit (last bit) to hide our message.\n\n";
				cout << "You can actually follow the file path and open the file to see the binary.\n";
				cout << "Use this tool: https://www.fileformat.info/tool/he, or Visual Studio Code with vscode-hexdump extension to show binary in hexadecimal.\n";
				cout << "------------------------------------------" << '\n';
				cin.clear();
				cout << "Press Enter to Continue";
				cin.ignore();
			}

			while (dataToHide == "")
			{
				stegUI.clearScreen();
				cout << "Please input your message, you wish to hide inside an image..."
					<< "\n";
				getline(cin, dataToHide);
				cout << "------------------------------------------" << '\n';
			}

			if (steg.encode(filename, dataToHide))
			{
				cout << '\n';
				encodeFile.saveToSameFormat();
				cout << "Encoding Succeed"
					<< "\n";
				cout << "------------------------------------------" << '\n';
			}
			cout << "------------------------------------------" << '\n';
			cin.clear();
			cout << "Press Enter to Continue";
			cin.ignore();
			break;
		}

		while (menuRes == 2)
		{
			stegUI.clearScreen();
			string filename = "";
			int length = 0;
			string hiddenMsg = "";

			while (filename == "")
			{
				stegUI.clearScreen();
				cout << "Please create folder <ppm> and <steg>, if they don't exist." << '\n';
				cout << "Supported file types are bmp, ppm, pbm, NetPbM." << '\n';
				cout << "If you want to use other file types, please convert the file.\nUse this link: https://www.online-utility.org/image/convert/to/PPM" << '\n';
				cout << '\n';
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
			cin.clear();
			cout << "Press Enter to Continue";
			cin.ignore();

			while (length == 0)
			{
				stegUI.clearScreen();
				cout << "We will search for a hidden message starting from the top. We need to know how long is the message, or the range we need to extract.\n";
				cout << "Please input your expected length of the hidden message."
					<< "\n";
				getline(cin, input);
				cout << "------------------------------------------" << '\n';
				if (isValidNum(input))
				{
					length = stoi(input);
				}
			}

			cin.clear();
			cout << "Press Enter to Continue";
			cin.ignore();
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
			cin.clear();
			cout << "Press Enter to Continue";
			cin.ignore();
			break;
		}

		stegUI.clearScreen();
	}
}

bool stegMain::isValidNum(const string& input)
{
	for (unsigned int i = 0; i < input.size(); i++)
	{
		if (input[i] > 57 || input[i] < 48)
			return false;
	}
	return true;
}

