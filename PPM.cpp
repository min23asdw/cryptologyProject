#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

class PPM
{
public:
    ~PPM();
    PPM(int height, int width);
    PPM() {}

    struct RGB
    {
        unsigned char r;
        unsigned char g;
        unsigned char b;
    };

    void set_width(int width) { this->width = width; }
    void set_height(int height) { this->height = height; }
    void set_version(string version) { this->version = version; }

    void save(string file_name);
    void read(string file_name);

    RGB **image = nullptr;

    int width = 0;
    int height = 0;
    string version = "P6";

    void create_image();
    void delete_image();
};

PPM::~PPM()
{
    delete_image();
}

PPM::PPM(int height, int width)
{
    set_height(height);
    set_width(width);

    create_image();
}

void PPM::save(string file_name)
{
    ofstream output(file_name, ios::binary);

    if (output.is_open())
    {
        output << version << endl;
        output << width << endl;
        output << height << endl;
        output << 255 << endl;

        if (version == "P6")
        {
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    output.write((char *)&image[i][j], sizeof(RGB));
                }
            }
        }
        else
        {
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    output << (int)image[i][j].r << ' ';
                    output << (int)image[i][j].g << ' ';
                    output << (int)image[i][j].b << '\n';
                }
            }
        }

        output.close();
    }
}

void PPM::read(string file_name)
{
    ifstream input(file_name, ios::binary);

    if (input.is_open())
    {
        int color;
        char ver[3];

        input.read(ver, 2);
        version = ver;
        input >> width;
        input >> height;
        input >> color;
        input.read(ver, 1);

        create_image();

        int box;
        if (version == "P6")
        {
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    input.read((char *)&image[i][j], sizeof(RGB));
                }
            }
        }
        else
        {
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    input >> box;
                    image[i][j].r = box;
                    input >> box;
                    image[i][j].g = box;
                    input >> box;
                    image[i][j].b = box;
                }
            }
        }

        input.close();
    }
}

void PPM::create_image()
{
    if (image != nullptr)
        delete_image();

    image = new RGB *[height];

    for (int i = 0; i < height; i++)
    {
        image[i] = new RGB[width];
        for (int j = 0; j < width; j++)
        {
            image[i][j].r = 255;
            image[i][j].g = 255;
            image[i][j].b = 255;
        }
    }
}

void PPM::delete_image()
{
    if (image != nullptr)
    {
        for (int i = 0; i < height; i++)
        {
            delete image[i];
        }
        delete image;
    }
}

int main()
{
    PPM ppm1(500, 1000);

    for (int i = 0; i < 500; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            ppm1.image[i][j].r = 50;
            ppm1.image[i][j].g = 168;
            ppm1.image[i][j].b = 20;
        }
    }

    ppm1.set_version("P3");
    ppm1.save("res.ppm");
}