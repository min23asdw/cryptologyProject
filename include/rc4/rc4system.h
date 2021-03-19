#pragma once
#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<string>
#include<windows.h>
#include<bitset>
#include "rc4menu.h"

using std::string;
using std::vector;

class rc4System {
    vector<unsigned char> S;
    vector<unsigned char> keyStream;
    string hexCipher = "";
    string cipher = "";
    string key = "";
    string plaintext = "";
    char cipherText[256] = { ' ' };
    char decrypted[256] = { ' ' };
    unsigned int temp = 0;
    bool checkEncrypt = false;
    rc4Menu menu;
public:
    void arrayInit(vector<unsigned char>&);
    void keySchedulAlgor(string&, vector<unsigned char>&, string);
    void pseudoRanGen(string, vector<unsigned char>);
    void rc4Encrypt(string, vector<unsigned char>);
    void rc4Decrypt(string, vector<unsigned char>);
    void modeEncrypt();
    void modeDecrypt();
    string hexToASCII(string);
};
/*
// Global Variables
vector<unsigned char> S;
vector<unsigned char> keyStream;
string key = "";
string plaintext = "";
char cipherText[256] = { ' ' };
char decrypted[256] = { ' ' };
unsigned int temp = 0;
bool checkEncrypt = false;
rc4Menu menu;*/
