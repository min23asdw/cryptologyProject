#include <iostream>
#include <string>
#include <fstream>
#include <bitset>
#include <vector>
#include "cryptoExceptions.h"

using namespace std;

class stegPPM
{
private:
    ifstream inFile;

public:
    int width = 0;
    int height = 0;
    int color = 0;
    int row = 0;
    int col = 0;
    unsigned int imgSize = 0;

    vector<unsigned char> colorChannel;

    string version = "";

    void openFile(string filename);
    void readHeader();
    void readImageData();
    void writeModifyImageData(string dataTohide);
    string extractHiddenData(unsigned int length);
    void modifyLSB(unsigned char &byte, unsigned char changeTo);
    unsigned char extractBit(unsigned char data, int position);
};

void stegPPM::openFile(string filename)
{
    inFile.open(filename, ios::binary);
    if (inFile.fail())
    {
        throw CryptoExceptions("Could not open file");
    }
}

void stegPPM::readHeader()
{
    if (inFile.is_open())
    {
        string input = "";
        while (color == 0)
        {
            inFile >> input;
            if (input[0] == '#')
            {
                inFile.ignore(70, '\n');
                continue;
            }

            if (version == "")
            {
                if (input != "P6")
                {
                    cout << "" << '\n';
                    throw CryptoExceptions("This magic PPM identifier is not supported, or corrupted file.");
                    break;
                }
                else
                    version = input;
            }
            else
            {
                if (width == 0)
                    width = stoi(input);
                else if (height == 0)
                    height = stoi(input);
                else
                {
                    color = stoi(input);
                    if (width == 0 || height == 0)
                    {
                        throw CryptoExceptions("Corrupted File");
                        break;
                    }
                }
            }

            if (!isascii(input[0]))
            {
                throw CryptoExceptions("Corrupted File. Header not found.");
                break;
            }
        }

        imgSize = width * height;
        cout << version << " " << width << " " << height << " " << color << '\n';
    }
}

void stegPPM::readImageData()
{
    inFile.ignore(256, '\n');
    colorChannel.resize(imgSize * 3);
    unsigned char pix;
    for (unsigned int i = 0; i < imgSize * 3; i++)
    {
        inFile.read(reinterpret_cast<char *>(&pix), 1);
        colorChannel[i] = pix;
    }
}

void stegPPM::writeModifyImageData(string dataToHide)
{
    ofstream newFile("testImg/newImg.ppm", ios::out | ios::binary);
    newFile << version << '\n';
    newFile << width << ' ' << height << '\n';
    newFile << color << '\n';

    unsigned int j = 0;
    int k = 7;
    for (unsigned int i = 0; i < imgSize * 3; i++)
    {
        if (k < 0)
        {
            k = 7;
            j++;
        }

        if (j >= dataToHide.size())
        {
            j = 0;
        }

        modifyLSB(colorChannel[i], extractBit(dataToHide[j], k));
        k--;
    }

    newFile.write(reinterpret_cast<char *>(&colorChannel[0]), imgSize * 3);

    if (newFile.fail())
    {
        throw CryptoExceptions("Could not write data.");
    }

    newFile.close();
}

string stegPPM::extractHiddenData(unsigned int length)
{
    string data;
    unsigned char ch = extractBit(colorChannel[0], 0);
    int range = (length * 8) >= imgSize ? imgSize - 1 : length * 8;

    int k = 0;
    for (int i = 1; i <= range; i++)
    {
        if (k >= 7)
        {
            k = 0;
            data += (char)ch;
            cout << bitset<8>(ch) << '\n';
            ch = extractBit(colorChannel[i], 0);
        }
        else
        {
            ch = (ch << 1) | extractBit(colorChannel[i], 0);
            k++;
        }
    }

    return data;
}

void stegPPM::modifyLSB(unsigned char &byte, unsigned char changeTo)
{
    int mask = 1;
    byte = ((byte & ~mask) | changeTo);
}

unsigned char stegPPM::extractBit(unsigned char data, int position)
{
    int mask = 1 << position;
    return ((data & mask) >> position);
}