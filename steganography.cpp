#include "stegPPM.h"

int main()
{
    string filename;
    while (true)
    {
        cout << "------------------------------------------" << '\n';
        cout << "Steganography is..." << '\n';
        cout << "------------------------------------------" << '\n';
        cout << "Currently supporting PPM P6" << '\n';
        cout << "------------------------------------------" << '\n';
        cout << "Please input your file name. Your file name should be under the directory of your program." << '\n';
        cout << "Ex. filename.ppm, testImg/filename.ppm "
             << "\n\n";

        getline(cin, filename);

        stegPPM steg;
        try
        {
            steg.openFile(filename);
            steg.readHeader();
            steg.readImageData();
            steg.writeModifyImageData();
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