#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

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
    pixels = new Rgb[width*height];
    unsigned char pix[3];
    for(int i = 0; i < width * height; i++)
    {
        inFile.read(reinterpret_cast<char *> (pix), 3);
        pixels[i].r = pix[0];
        pixels[i].g = pix[1];
        pixels[i].b = pix[2];
    }

    cout << static_cast<int>(pixels[1].r);

    delete [] pixels;
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
}