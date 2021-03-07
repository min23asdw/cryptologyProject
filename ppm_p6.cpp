#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int width = 0;
int height = 0;
int color = 0;

int main()
{
    int row = 0;
    int col = 0;
    string version = "";

    ifstream infile("test.ppm");
    stringstream ss;
    string input = "";

    getline(infile, input);
    if(input == "P6")
    {
        version = "P6";
        getline(infile, input);
        char format[] = "%d %d";
        sscanf(input.c_str(), format, &width, &height);
        getline(infile, input);
        if(input[0] == '#') getline(infile, input);
        color = stoi(input);
    }
    else
    {
        char format[] = "%s %d %d %d";
        char ver[2];
        sscanf(input.c_str(), format, ver, &width, &height, &color);
        version = ver;
    }
    // cout << version << " " << width << " " << height << " " << color;

    if(version == "P6")
    {
        
    }
}