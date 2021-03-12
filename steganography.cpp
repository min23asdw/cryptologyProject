#include "stegPPM.h"

int main()
{
    while (true)
    {
        string filename;
        string dataToHide;

        cout << "------------------------------------------" << '\n';
        cout << "Steganography is..." << '\n';
        cout << "------------------------------------------" << '\n';
        cout << "Currently supporting PPM P6" << '\n';
        cout << "------------------------------------------" << '\n';
        cout << "Please input your file name. Your file name should be under the directory of your program." << '\n';
        cout << "Ex. filename.ppm, testImg/filename.ppm "
             << "\n\n";

        getline(cin, filename);
        cout << "------------------------------------------" << '\n';
        cout << "Please input your text to be hidden in the image" << '\n';
        getline(cin, dataToHide);
        cout << "------------------------------------------" << '\n';
        // filename = "testImg/test.ppm";
        // int length = dataToHide.size();
        int length;
        stegPPM steg;

        string hiddenMsg;
        if(steg.encode(filename, dataToHide))
        {
            cout << "------------------------------------------" << '\n';
            cout << "Enter length of your hidden message." << '\n';
            cin >> length;
            filename = "testImg/img.ppm";
            hiddenMsg = steg.decodeMsg(filename, length);
            cout << hiddenMsg << '\n';
        }

        cout << "------------------------------------------" << '\n';
        break;
    }
}