#include "enigmaSystem.h"
#include <iostream>

int Enigma::index(char c)
{
	// c in alphabet

	int i = 0;

	while ((i < Nchars) && (c != alphabet[i]))
		++i;
	return i;
}


void Enigma::PlaceRotor(int position, int r)
// set wirings of a single rotor
{
	RotWiring[position] = ROTOR[r];
	RotNotch[position] = NOTCH[r];
	RotNumber[position] = r;
}


int Enigma::ChrToInt(char c)
{
	// '0' <= c <= '9'

	return (int)(c - '0');
}

void Enigma::reset()
{
	for (int i = 1; i <= mRotors; ++i)
		window[i] = Iwindow[i];
}

int Enigma::OpenFiles(char* inFname,
	char* encFname,
	char* logFname)
{
	inFp = fopen(inFname, "rt");
	outFp = fopen(encFname, "wt");
	logFp = fopen(logFname, "wt");
	return    (inFp != NULL) && (outFp != NULL) && (logFp != NULL);
}
void Enigma::CloseFiles()
{
	fclose(inFp); fclose(outFp); fclose(logFp);
}

void Enigma::ShowRotors()
{
	int i, j, k;
	char* Rwiring;

	for (i = mRotors; i >= 1; --i) {
		fprintf(logFp, "%d: ", i);
		Rwiring = RotWiring[i];
		k = RotPos[i];
		for (j = 0; j < k; ++j)
			fprintf(logFp, "%c", *Rwiring++);
		fprintf(logFp, "->");
		for (j = k; j < Nchars; ++j)
			fprintf(logFp, "%c", *Rwiring++);
		fprintf(logFp, "\n");
	}
}
// Initialization from file 'esetup' (step 1)

void Enigma::SetPlugboard()  // make connections on the plug board
{
	int i, n, x;
	char p1, p2, ch;

	// Read a line containing pairs of letters corresponding to pairs of
	// plugs connected by a wire.  The length of the line is assumed to be even.

	fgets(inLine, Nline, inFp);

	inLine[strlen(inLine) - 1] = '\0';
	n = strlen(inLine);

	for (i = 0; i < n; i += 2) {
		p1 = inLine[i];
		p2 = inLine[i + 1];
		x = index(p1);
		if ((ch = plugboard[x]) != p1) { // occupied? -> disconnect
			plugboard[index(ch)] = ch;
			plugboard[x] = p1;
		}
		plugboard[x] = p2;                 // plug in
		x = index(p2);
		if ((ch = plugboard[x]) != p2) { // occupied? -> disconnect
			plugboard[index(ch)] = ch;
			plugboard[x] = p1;
		}
		plugboard[x] = p1;                // plug in
	}
}

void Enigma::ReportMachine()
{
	fprintf(logFp, "Plugboard mappings:\n");
	fprintf(logFp, "%s\n", ROTOR[0]);
	fprintf(logFp, "%s\n", plugboard);

	fprintf(logFp, "\nRotor wirings:\n");
	fprintf(logFp, "position rotor ring setting notch sequence\n");
	for (int i = mRotors; i >= 1; --i) {
		fprintf(logFp, "%8d %5d %12c %5c %s\n", i, RotNumber[i], window[i], RotNotch[i], RotWiring[i]);
	}
	fprintf(logFp, "\nreflector %c %s\n", ReflType, reflector);
	fprintf(logFp, "\nrotors:\n");
	ShowRotors();
}
//lost
// Initialization from file 'esetup' (step 2)

void Enigma::SetRotorsAndReflector()
{
	int i, n, rotor, rotPos;
	char ch, ringPos;

	// Read the actual number of rotors "mRotors", compute the total
	// number of encryption steps "mSteps", and read "mRotors" lines,
	// each one containing three characters denoting
	//
	//   (a) rotor ID (1-8,b,g)
	//   (b) rotor position (1-mRotors), and
	//   (c) ring character (position)

	fgets(inLine, Nline, inFp);
	mRotors = ChrToInt(inLine[0]);
	if (mRotors > 4)
		mRotors = 4;
	mSteps = (mRotors << 1) + 3;
	for (i = 1; i <= mRotors; ++i) {
		fgets(inLine, Nline, inFp);
		ch = inLine[0];
		if (isdigit((int)ch))
			rotor = ChrToInt(ch);
		else {
			ch = tolower(ch);
			rotor = ch == 'b' ? 9
				: ch == 'g' ? 10 : 0;
		}
		rotPos = ChrToInt(inLine[1]);
		ringPos = inLine[2];
		Iwindow[rotPos] = window[rotPos] = ringPos;
		PlaceRotor(rotPos, rotor);
	}

	// Read a line containing the designation of the reflector (t,b,c,B,C)

	fgets(inLine, Nline, inFp);
	ch = inLine[0];
	switch (ch) {
	case 't': n = 0; break;      case 'b': n = 1; break;
	case 'c': n = 2; break;      case 'B': n = 3; break;
	case 'C': n = 4; break;       default: n = 0; break;
	}
	reflector = REFLECTOR[n];
	ReflType = i;
}


void Enigma::SetRotorPositions()
{
	int i, j, k;
	char* Rwiring, ch;

	for (i = 1; i <= mRotors; ++i) {

		j = RotNumber[i];
		ch = window[j];
		Rwiring = RotWiring[i];
		k = 0;
		while (Rwiring[k] != ch)
			++k;
		RotPos[j] = 1;
	}
}
int Enigma::mod(int n, int modulus)  // simple modulo function
{
	while (n >= modulus)
		n -= modulus;
	while (n < 0)
		n += modulus;
	return n;
}

void Enigma::ShowWindow()
{
	int i;

	for (i = mRotors; i >= 1; --i)
		fprintf(logFp, "%c ", window[i]);
	fprintf(logFp, "  ");
}

void Enigma::ShowSteps()
{
	int i;

	for (i = 0; i < mSteps; ++i)
		fprintf(logFp, " -> %c", step[i]);
}

void Enigma::TurnRot(int n, int width)   // Turn rotor "n" "width" times
{                                  // wrapping around if necessary
	char* r;

	if (width > 0) {
		RotPos[n] = mod(RotPos[n] + width, Nchars);
		r = RotWiring[n];
		window[n] = r[RotPos[n]];
	}
}
// Transform on right-to-left path through rotors

void Enigma::turn()   // determine which rotors must turn
{
	int doit[Nrotors], n;
	char* r1 = RotWiring[1];
	char* r2 = RotWiring[2];
	char* r3;

	if (mRotors > 3)
		r3 = RotWiring[3];

	// calculate stepwidth for each rotor
	doit[1] = 1;
	for (int i = 2; i <= mRotors; ++i)
		doit[i] = 0;
	if ((RotNotch[1] == r1[RotPos[1]])
		||
		(RotNotch[2] == r2[RotPos[2]]))  // double stepping
		doit[2] = 1;
	if (RotNotch[2] == r2[RotPos[2]])
		doit[3] = 1;
	if (mRotors > 3) {
		if (RotNotch[3] == r3[RotPos[3]])
			doit[4] = 1;
	}

	// turn rotors "simultaneously"
	for (n = 1; n <= mRotors; ++n)
		TurnRot(n, doit[n]);
}

char Enigma::RtoLpath(char c, int r)  // transform character "c" with rotor "r"
{
	int n, offset, idx, ret;
	char* CurRotor;

	CurRotor = RotWiring[r];
	n = index(c);
	offset = index(CurRotor[RotPos[r]]);
	idx = mod(n + offset, Nchars);
	ret = mod(index(CurRotor[idx]) - offset, Nchars);
	return alphabet[ret];
}

// Transform on left-to-right path through rotors

char Enigma::LtoRpath(char c, int r) // transform character "c" with rotor "r"
{
	int n, m, offset, idx, newchar;
	char* CurRotor;

	CurRotor = RotWiring[r];
	n = index(c);
	offset = index(CurRotor[RotPos[r]]);
	newchar = alphabet[mod(n + offset, Nchars)];

	m = 0;
	while (m < Nchars && CurRotor[m] != newchar)
		++m;
	idx = mod(m - offset, Nchars);
	return alphabet[idx];
}

char Enigma::encrypt(char c)
{
	int i, r;

	turn();                                          // move rotors
	i = 0;                                           // pass through:
	step[i++] = plugboard[index(c)];           //    plugboard
	for (r = 1; r <= mRotors; ++r)
		step[i++] = RtoLpath(step[i - 1], r);     //    right-to-left path
	step[i++] = reflector[index(step[i - 1])]; //    reflector
	for (r = mRotors; r >= 1; --r)                 //    left-to-right path
		step[i++] = LtoRpath(step[i - 1], r);
	step[i] = plugboard[index(step[i - 1])];   //    plugboard

	return step[i];
}

void Enigma::ProcessPlainText()
{
	int i, n;
	char c1, c2;
	//int h =0;
	fprintf(logFp, "\n\nEncryption\n");
	while (fgets(inLine, Nline, inFp) != NULL) {

		n = strlen(inLine) - 1;
		inLine[n] = '\0';

		for (i = 0; i < n; ++i) {
			c1 = inLine[i];
			if (isupper((int)c1))
				c1 = tolower(c1);

			c2 = encrypt(c1);
			// ShowRotors();
			ShowWindow();
			fprintf(logFp, " %c", c1);
			ShowSteps();
			fprintf(logFp, "\n");
			outLine[i] = c2;
		}
		fprintf(logFp, "\n");
		outLine[i] = '\0';
		fprintf(outFp, "%s\n", outLine);
		//cout << "H" << h;
		//h++;
	}
}

void Enigma::ProcessFile(char* inFname,
	char* encFname,
	char* logFname)
{
	if (OpenFiles(inFname, encFname, logFname)) {
		SetRotorPositions();
		ReportMachine();
		ProcessPlainText();
		CloseFiles();
	}
}
void Enigma::InitEnigma() // Default initialization
{

	mRotors = 3;
	mSteps = (mRotors << 1) + 3;
	strcpy(plugboard, PLUGBOARD);
	for (int i = 0; i <= mRotors; ++i) {
		RotWiring[i] = ROTOR[i];
		RotNotch[i] = NOTCH[i];
		RotNumber[i] = i;
		Iwindow[i] = window[i] = 'a';
	}
	reflector = REFLECTOR[1];
	ReflType = 1;
	return;
}


void Enigma::TryUserSetup()
// Attempt initialization from user file
{

	if ((inFp = fopen("esetup.txt", "rt"))
		!=
		NULL)
	{
		std::cout << "esetup loaded\n";
		SetPlugboard();
		SetRotorsAndReflector();
		fclose(inFp);
	}
}
