#include "stegPPM.h"

using namespace std;

bool stegPPM::encode(string filename, string message)
{
    if (inFile.is_open())
    {
        inFile.close();
    }

    if (openAndRead(filename) == true)
    {
        if (writeModifyImageData(filename, message) == true)
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
        cout << "PPM Header" << '\n';
        cout << version << " " << width << " " << height << " " << color << "\n\n";
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
        inFile.read(reinterpret_cast<char*>(&pix), 1);
        colorChannel[i] = pix;
    }
}

bool stegPPM::writeModifyImageData(string filename, string dataToHide)
{
    //cout << version << " " << width << " " << height << " " << color << '\n';

    int slash = filename.find_last_of('/');
    string name = filename.substr(slash + 1, filename.size());

    ofstream newFile(encodeFolder + "/steg_" + name, ios::out | ios::binary);
    newFile << version << '\n';
    newFile << width << ' ' << height << '\n';
    newFile << color << '\n';

    unsigned int j = 0;
    int k = 7;
    cout << "We will change the last bit (least significant bit) of each color channel to each digit of binary from message, we wish to hide." << '\n';
    cout << "This operation will go through every pixels of the image. If it reaches the end of the message, it will continue the operation by going back to the beginning of the message.\n\n";
    cout << "This technique is used for watermarking to prevent copyright infringement.\n";
    cout << "If the image is cropped, then the data will still remain.\n";

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

    newFile.write(reinterpret_cast<char*>(&colorChannel[0]), imgSize * 3);

    if (newFile.fail())
    {
        cerr << "Could not write data.\n";
        return false;
    }

    cout << "\nEncoded Image was saved at: " << encodeFolder + "/steg_" + name << '\n';

    newFile.close();
    return true;
}

string stegPPM::extractHiddenData(unsigned int length)
{
    string data;
    unsigned char ch = extractBit(colorChannel[0], 0);
    //cout << "Bits from each color channel (RGB) representing color value: " << bitset<8>(colorChannel[0]) << '\n';
    int range = (length * 8) >= imgSize ? imgSize - 1 : length * 8;

    int k = 0;
    for (int i = 1; i <= range; i++)
    {
        cout << "Bits from each color channel (RGB) representing color value: " << bitset<8>(colorChannel[i-1]) << '\n';

        if (k >= 7)
        {
            cout << '\n';
            k = 0;
            data += (char)ch;
            cout << "8-bit number from the last bit of each color value, representing each character of the hidden message: \n" << bitset<8>(ch) << " --> " << (char)ch << '\n';
            ch = extractBit(colorChannel[i], 0);
            cout << '\n';
        }
        else
        {
            ch = (ch << 1) | extractBit(colorChannel[i], 0);
            k++;
        }
    }

    return data;
}

void stegPPM::modifyLSB(unsigned char& byte, unsigned char changeTo)
{
    int mask = 1;
    byte = ((byte & ~mask) | changeTo);
}

unsigned char stegPPM::extractBit(unsigned char data, int position)
{
    int mask = 1 << position;
    return ((data & mask) >> position);
}
