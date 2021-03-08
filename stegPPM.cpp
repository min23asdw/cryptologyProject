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
    string version = "";

    void openFile(string filename);
    void readHeader();
};

void stegPPM::openFile(string filename)
{
    inFile.open(filename);
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

int main()
{
    stegPPM steg;
    steg.openFile("testImg/test.ppm");

    try
    {
        steg.readHeader();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        cout << "Corrupted file, or unsupported file type " << '\n';
    }
}