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
        cout << "Please input your text to be hid in the image" << '\n';
        getline(cin, dataToHide);
        cout << "------------------------------------------" << '\n';

        stegPPM steg;
        try
        {
            steg.openFile(filename);
            steg.readHeader();
            steg.readImageData();
            steg.writeModifyImageData(dataToHide);
        }
        catch (const CryptoExceptions &e)
        {
            cerr << '\n'
                 << e.what() << "\n\n";
            continue;
        }

        cout << "------------------------------------------" << '\n';
        break;
    }
}