#pragma once
#define Nchars 26  // Total number of encipherable characters
#define Mchars 26  // Buffer size for strings containing Nchars
#define Nrotors 11 // Maximum number of rotors (1-based: 1-10)
#define Nrefls 5   // Total number of reflectors (1-based: 1-4)
#define Nsteps 11  // Maximum total number of encryption steps
// = 2*4 (rotors) + 2 (plugboard) + 1 (reflector)
#define Nline 255

#include <stdio.h>
#include <string>

class Enigma
{
private:
	char* ROTOR[Nrotors]  // Wirings of the rotors
		= {
		// input alphabet ("rotor" 0, not used)
		"abcdefghijklmnopqrstuvwxyz",
		// rotor 1
		"ekmflgdqvzntowyhxuspaibrcj",
		// rotor 2
		"ajdksiruxblhwtmcqgznpyfvoe",
		// rotor 3
		"bdfhjlcprtxvznyeiwgakmusqo",
		// rotor 4
		"esovpzjayquirhxlnftgkdcmwb",
		// rotor 5
		"vzbrgityupsdnhlxawmjqofeck",
		// rotor 6
		"jpgvoumfyqbenhzrdkasxlictw",
		// rotor 7
		"nzjhgrcxmyswboufaivlpekqdt",
		// rotor 8
		"fkqhtlxocbjspdzramewniuygv",
		// beta rotor
		"leyjvcnixwpbqmdrtakzgfuhos",
		// gamma rotor
		"fsokanuerhmbtiycwlqpzxvgjd"
	};

	// Position in which each rotor causes its left neighbor to turn
// (The beta and gamma rotors could only be used in the Naval-Enigma
//  fourth position, and did not have knock-on effect.  So, their
//  notch positions are meaningless)

	char NOTCH[Nrotors]
		= { 'z', 'q', 'e', 'v', 'j', 'z', 'z', 'z', 'z', 'a', 'a' };

	char* REFLECTOR[Nrefls]  // Reflectors
		= {
		// input alphabet ("REFLECTOR" 0, not used)
		"abcdefghijklmnopqrstuvwxyz",
		// reflector B, thick
		"yruhqsldpxngokmiebfzcwvjat",
		// reflector C, thick
		"fvpjiaoyedrzxwgctkuqsbnmhl",
		// reflector B, dunn
		"enkqeuywjicopblmdxzvfthrgs",
		// reflector C, dunn
		"rdobjntkvehmlfcwzrxgyipsuq"
	};

	const char* PLUGBOARD  // Default wirings of the plugboard
		=
		"abcdefghijklmnopqrstuvwxyz";

	const char* alphabet  // Input alphabet
		=
		"abcdefghijklmnopqrstuvwxyz";

	int mRotors,                // Number of rotors placed in the machine
	// (1-based: 1-4)
		mSteps;                // Actual number of encryption steps
		// = 2*mRotors + 2 (plugboard) + 1 (reflector)
	int RotPos[Nrotors];     // Rotor placed in each position
	char window[Nrotors],     // Characters in window
		Iwindow[Nrotors];    // Initial values in 'window' (for resetting)
	char* RotWiring[Nrotors]; // Rotor wirings
	char RotNotch[Nrotors];   // Rotor switching positions
	int RotNumber[Nrotors];  // Which physical rotor (t,1-8,b,g)
	char* reflector,            // Wiring of the reflector
		plugboard[Mchars];   // Wirings of the plugboard
	int ReflType;              // Reflector used
	char step[Nsteps];        // Array to store encryption steps

	// Files and variables for setup and reporting
	FILE* inFp,             // input file pointer
		* outFp,            // output file pointer
		* logFp;            // log file pointer
	char inLine[Nline],   // input line
		outLine[Nline];  // output line

	int index(char c);
	void PlaceRotor(int position, int r);
	int ChrToInt(char c);
	int OpenFiles(char* inFname, char* encFname, char* logFname);
	void CloseFiles();
	void ShowRotors();
	void SetPlugboard();  // make connections on the plug board
	void ReportMachine();
	void SetRotorsAndReflector();
	void SetRotorPositions();
	int mod(int n, int modulus);  // simple modulo function
	void ShowWindow();
	void ShowSteps();
	void TurnRot(int n, int width);   // Turn rotor "n" "width" times
	void turn();   // determine which rotors must turn
	char RtoLpath(char c, int r);  // transform character "c" with rotor "r"
	char LtoRpath(char c, int r); // transform character "c" with rotor "r"
	char encrypt(char c);
	void ProcessPlainText();

public:
	void ProcessFile(char* inFname, char* encFname, char* logFname);
	void InitEnigma(); // Default initialization
	void TryUserSetup();
	void reset();
};
