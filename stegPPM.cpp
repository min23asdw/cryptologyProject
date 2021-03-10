#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <bitset>
#include <vector>

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
    struct Rgb
    {
        unsigned char r, g, b;
    };

    Rgb *pixels = nullptr;

    string version = "";

    void openFile(string filename);
    void readHeader();
    void readImageData();
    void writeImageData();
    void modifyLSB(unsigned char &byte, int changeTo);
};

void stegPPM::openFile(string filename)
{
    inFile.open(filename, ios::binary);
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
                    cout << "This magic PPM identifier is not supported, or corrupted file." << '\n';
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
                    color = stoi(input);
            }
        }

        cout << version << " " << width << " " << height << " " << color;
    }
}

void stegPPM::readImageData()
{
    inFile.ignore(256, '\n');
    pixels = new Rgb[width * height];
    unsigned char pix[3];
    for (int i = 0; i < width * height; i++)
    {
        inFile.read(reinterpret_cast<char *>(pix), 3);
        pixels[i].r = pix[0];
        pixels[i].g = pix[1];
        pixels[i].b = pix[2];
    }
}

void stegPPM::writeImageData()
{
    size_t size = height * width;
    ofstream newFile("testImg/newImg.ppm", ios::out | ios::binary);
    newFile << version << '\n';
    newFile << width << ' ' << height << '\n';
    newFile << color << '\n';

    vector<unsigned char> temp(size * 3);
    for (int i = 0; i < size; i++)
    {
        modifyLSB(pixels[i].r, 0);
        modifyLSB(pixels[i].g, 0);
        modifyLSB(pixels[i].b, 0);

        temp[i * 3] = pixels[i].r;
        temp[i * 3 + 1] = pixels[i].g;
        temp[i * 3 + 2] = pixels[i].b;
    }

    newFile.write(reinterpret_cast<char *>(&temp[0]), size * 3);
    delete[] pixels;

    if (newFile.fail())
    {
        cerr << "Could not write data" << endl;
    }

    newFile.close();
}

void stegPPM::modifyLSB(unsigned char &byte, int changeTo)
{
    int mask = 1;
    byte = ((byte & ~mask) | changeTo);
}

int main()
{
    stegPPM steg;
    steg.openFile("testImg/white.ppm");

    try
    {
        steg.readHeader();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        cout << "Corrupted file, or unsupported file type " << '\n';
    }

    steg.readImageData();
    steg.writeImageData();
}