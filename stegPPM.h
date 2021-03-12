#include <iostream>
#include <string>
#include <fstream>
#include <bitset>
#include <vector>

using namespace std;

class stegPPM
{
private:
    ifstream inFile;
    vector<unsigned char> colorChannel;

    bool openAndRead(string filename);

    bool openFile(string filename);
    bool readHeader();
    void readImageData();
    bool writeModifyImageData(string dataTohide);
    string extractHiddenData(unsigned int length);

    void modifyLSB(unsigned char &byte, unsigned char changeTo);
    unsigned char extractBit(unsigned char data, int position);

public:
    int width = 0;
    int height = 0;
    int color = 0;
    unsigned int imgSize = 0;

    string version = "";

    bool encode(string filename, string message);
    string decodeMsg(string filename, const int length);
};

bool stegPPM::encode(string filename, string message)
{
    if (inFile.is_open())
    {
        inFile.close();
    }

    if (openAndRead(filename) == true)
    {
        if (writeModifyImageData(message) == true)
        {
            inFile.close();
            return true;
        }
    }

    return false;
}

string stegPPM::decodeMsg(string filename, int length)
{
    if (inFile.is_open())
    {
        inFile.close();
    }

    if (openAndRead(filename) == true)
    {
        return extractHiddenData(length);
    }
    else
    {
        return "";
    }
}

bool stegPPM::openAndRead(string filename)
{
    if (openFile(filename) == true)
    {
        if (readHeader() == true)
        {
            readImageData();
            return true;
        }
    }

    return false;
}

bool stegPPM::openFile(string filename)
{
    inFile.open(filename, ios::binary);
    if (inFile.fail())
    {
        cerr << "Could not open file\n";
        return false;
    }
    return true;
}

bool stegPPM::readHeader()
{
    version = "";
    width = 0;
    height = 0;
    color = 0;
    imgSize = 0;
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
                    cerr << "This magic PPM identifier is not supported, or corrupted file.\n";
                    return false;
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
                        cerr << "Corrupted File\n";
                        return false;
                    }
                }
            }

            if (!isascii(input[0]))
            {
                cerr << "Corrupted File. Header not found.\n";
                return false;
            }
        }

        imgSize = width * height;
        cout << version << " " << width << " " << height << " " << color << '\n';
        return true;
    }
    return false;
}

void stegPPM::readImageData()
{
    inFile.ignore(256, '\n');
    if (!colorChannel.empty())
    {
        colorChannel.clear();
    }
    colorChannel.resize(imgSize * 3);

    unsigned char pix;
    for (unsigned int i = 0; i < imgSize * 3; i++)
    {
        inFile.read(reinterpret_cast<char *>(&pix), 1);
        colorChannel[i] = pix;
    }
    cout << bitset<8>(colorChannel[0]) << "\n\n";
}

bool stegPPM::writeModifyImageData(string dataToHide)
{
    cout << version << " " << width << " " << height << " " << color << '\n';

    ofstream newFile("testImg/img.ppm", ios::out | ios::binary);
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
        cerr << "Could not write data.\n";
        return false;
    }

    newFile.close();
    return true;
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
            cout << '\n';
            k = 0;
            data += (char)ch;
            cout << bitset<8>(ch) << '\n';
            ch = extractBit(colorChannel[i], 0);
            cout << '\n';
        }
        else
        {
            ch = (ch << 1) | extractBit(colorChannel[i], 0);
            cout << bitset<8>(colorChannel[i]) << '\n';
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
