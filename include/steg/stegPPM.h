#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <bitset>
#include <vector>

using std::string;

class stegPPM
{
private:
    std::ifstream inFile;
    std::vector<unsigned char> colorChannel;

    bool openAndRead(string filename);

    bool openFile(string filename);
    bool readHeader();
    void readImageData();
    bool writeModifyImageData(string filename, string dataTohide);
    string extractHiddenData(unsigned int length);

    void modifyLSB(unsigned char &byte, unsigned char changeTo);
    unsigned char extractBit(unsigned char data, int position);

    const string encodeFolder = "steg";
public:
    int width = 0;
    int height = 0;
    int color = 0;
    unsigned int imgSize = 0;

    string version = "";

    bool encode(string filename, string message);
    string decodeMsg(string filename, const int length);
};
