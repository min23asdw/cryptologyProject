#include "stegPPM.h"
#define cimg_use_jpeg
#include "display/CLmgLibrary/CImg.h"

using namespace cimg_library;

void convertFile(string filename)
{
    int length = filename.size();
    int dot = filename.find_last_of('.');

    if (dot > 0)
    {
        string fileType = filename.substr(dot + 1, length);
        string newName = filename.substr(0, dot - 1) + ".ppm";
        if (fileType != "ppm")
        {
            CImg<unsigned char> image(filename.c_str());
            image.save(newName.c_str());
        }
    }
}

int main()
{
    stegPPM steg;

    int menu = -1;
    string input = "";
    while (true)
    {
        cout << "Enter 0 to hide a message (Encode)" << '\n';
        cout << "Enter 1 to reveal a message (Decode)" << '\n';
        cout << "------------------------------------------" << '\n';
        getline(cin, input);
        menu = stoi(input);

        while (menu == 0)
        {
            string filename = "";
            string dataToHide = "";

            while (filename == "")
            {
                cout << '\n';
                cout << "ENCODING------------------------------------------" << '\n';
                cout << "Please input your image file name to be used as a cover image."
                     << "\n";
                cout << "ex. <img.ppm>, <testImg/img.ppm>, <img.jpg>"
                     << "\n\n";
                getline(cin, filename);
                convertFile(filename);
                cout << "------------------------------------------" << '\n';
            }
            while (dataToHide == "")
            {
                cout << "Please input your message, you wish to hide inside an image..."
                     << "\n";
                getline(cin, dataToHide);
                cout << "------------------------------------------" << '\n';
            }

            if (steg.encode(filename, dataToHide))
            {
                cout << "Encoding Succeed"
                     << "\n";
                cout << "------------------------------------------" << '\n';
                break;
            }
            cout << "------------------------------------------" << '\n';
            break;
        }
        while (menu == 1)
        {
            string filename = "";
            int length = 0;
            string hiddenMsg = "";

            while (filename == "")
            {
                cout << '\n';
                cout << "DECODING------------------------------------------" << '\n';
                cout << "Please input your image file name to decode a hidden message."
                     << "\n";
                cout << "ex. <img.ppm>, <testImg/img.ppm>"
                     << "\n\n";
                getline(cin, filename);
                cout << "------------------------------------------" << '\n';
            }

            while (length == 0)
            {
                cout << "Please input your expected length of the hidden message."
                     << "\n";
                getline(cin, input);
                cout << "------------------------------------------" << '\n';
                length = stoi(input);
            }

            hiddenMsg = steg.decodeMsg(filename, length);
            if (hiddenMsg == "")
            {
                cout << "Cannot find hidden message."
                     << "\n";
                cout << "------------------------------------------" << '\n';
                continue;
            }

            cout << "Decoding Succeed"
                 << "\n";
            cout << "Your hidden message is \n";
            cout << hiddenMsg << "\n";
            cout << "------------------------------------------" << '\n';
            break;
        }
    }
}