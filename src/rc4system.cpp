#include "rc4system.h"

using namespace std;

// Array Initialization
void rc4System::arrayInit(vector<unsigned char>& S) {
    unsigned int i = 0;
    system("cls");
    cout << ": Array Initialization :" << endl << endl;
    Sleep(500);
    cout << "The first step is the array initialization. It is a character array of size 256" << endl;
    Sleep(500);
    cout << "for every element of the array, we initialize S[i] to i." << endl << endl;
    Sleep(500);
    cout << "[+] Array initialize.." << endl << endl;
    Sleep(500);
    for (i = 0; i < 256; i++) {
        S.insert(S.begin() + i, (unsigned char)i);
        if ((i % 15) == 0) {
            system("cls");
            cout << ": Array Initialization :" << endl << endl;
            cout << "The first step is the array initialization. It is a character array of size 256" << endl;
            cout << "for every element of the array, we initialize S[i] to i." << endl << endl;
            cout << "[+] Array initialize.." << endl << endl;
            cout << "         " << "S[" << i << "]" << " = " << (int)S[i] << " (ASCII) " << endl << endl;
        }
        Sleep(10);
    }
    Sleep(500);
    cout << "the array will look like S[] = {0, 1, 2, 3, ...... , 254, 255}" << endl;
    Sleep(500);
    cout << "After this, we will run the KSA algorithm.";
}

// Key Scheduling Algorithm (KSA)
void rc4System::keySchedulAlgor(string& key, vector<unsigned char>& S) {
    Sleep(500);
    cout << ": Key Scheduling Algorithm (KSA) :" << endl << endl;
    int i = 0, j = 0;
    Sleep(500);
    cout << "[+] Your Plain Text: " << plaintext << endl << endl;
    Sleep(250);
    cout << "[+] Enter the secret key: ";
    getline(cin, key);
    Sleep(250);
    cout << "    Your Secret Key: " << key << endl;
    cout << "    Your Secret Key Length: " << key.length() << endl << endl;
    Sleep(250);
    cout << "Press anykey to next step.";
    cin.get();
    Sleep(250);
    system("cls");
    Sleep(500);
    cout << ": Key Scheduling Algorithm (KSA) :" << endl << endl;
    Sleep(500);
    cout << "The initialized array S[256] is now run through the KSA.\nThe KSA uses the secret key to scramble the array." << endl;
    Sleep(500);
    cout << "KSA is a simple loop, in which we are having two variable i and j." << endl;
    Sleep(500);
    cout << "We are using these variables to rearrange the array." << endl << endl;
    Sleep(500);
    cout << "[+] The KSA scramble array S[256].. " << endl << endl;
    Sleep(250);
    cout << "         " << "Position I is : " << i << endl;
    cout << "         " << "Position J is : " << j << endl;
    Sleep(250);
    cout << "         " << "Swap S[i] with S[j]" << endl;
    Sleep(250);
    for (i = 0; i < 256; i++)
    {
        j = (j + S[i] + key.at(i % key.length())) % 256;
        swap(S[i], S[j]);
        if ((i % 5) == 0) {
            system("cls");
            cout << ": Key Scheduling Algorithm (KSA) :" << endl << endl;
            cout << "The initialized array S[256] is now run through the KSA.\nThe KSA uses the secret key to scramble the array." << endl;
            cout << "KSA is a simple loop, in which we are having two variable i and j." << endl;
            cout << "We are using these variables to rearrange the array." << endl << endl;
            cout << "[+] The KSA scramble array S[256].. " << endl << endl;
            cout << "         " << "Position I is : " << i << endl;
            cout << "         " << "Position J is : " << j << endl;
            cout << "         " << "Swap S[i] with S[j]" << endl;
            cout << "         " << "Swapping.. " << endl << "         " << "S[" << i << "]" << " = " << (int)S[i] << " (ASCII) " << endl;
            cout << "         " << "S[" << j << "]" << " = " << (int)S[j] << " (ASCII) " << endl;
            Sleep(100);
        }
    }
    Sleep(500);
    cout << "\n\nRearranging the array is done by using a secret key.\n\n";
    Sleep(500);
    cout << "After this, we will run the PRGA algorithm.";
}

// Pseudo Random Generation Algorithm (PRGA)
void rc4System::pseudoRanGen(string plaintext, vector<unsigned char> S) {
    system("cls");
    Sleep(500);
    cout << ": Pseudo Random Generation Algorithm (PRGA) :" << endl << endl;
    Sleep(500);
    cout << "For as many iterations as are needed, \nthe PRGA modifies the state and outputs a byte of the keystream." << endl << endl;
    Sleep(500);
    cout << "[+] incremets i" << endl;
    Sleep(500);
    cout << "[+] looks up the i element of S, S[i], and adds that to j" << endl << endl;
    Sleep(500);
    cout << "         " << "i is " << "0" << endl << "         " << "S[i] is " << "?" << " (ASCII) " << endl;
    Sleep(500);
    cout << "         " << "j is " << "0" << endl << endl;
    Sleep(500);
    cout << "[+] exchanges the values of S[i] and S[j]\n then uses the sum S[i] + S[j] % 256 as an index to fetch a third element of S (keystream)";
    Sleep(500);
    cout << "         " << "The index is " << temp << endl << "         " "add S[temp] to Keystream[" << "0" << "]" << " = " << "?" << " (ASCII) ";
    int i = 0, j = 0;
    for (int k = 0; k < plaintext.size(); k++) {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        swap(S[i], S[j]);
        temp = (S[i] + S[j]) % 256;
        keyStream.insert(keyStream.begin() + k, S[temp]); // Create Keystream
        system("cls");
        cout << ": Pseudo Random Generation Algorithm (PRGA) :" << endl << endl;
        cout << "For as many iterations as are needed, \nthe PRGA modifies the state and outputs a byte of the keystream." << endl << endl;
        cout << "[+] incremets i" << endl;
        cout << "[+] looks up the i element of S, S[i], and adds that to j" << endl << endl;
        cout << "         " << "i is " << i << endl << "         " << "S[i] is " << (int)S[i] << " (ASCII) " << endl;
        cout << "         " << "j is " << j << endl << endl;
        cout << "[+] exchanges the values of S[i] and S[j]\n    then uses the sum S[i] + S[j] % 256 as an index to fetch a third element of S (keystream)" << endl << endl;
        cout << "         " << "The index is " << temp << endl << "         " "add S[temp] to Keystream[" << k << "]" << " = " << (int)S[temp] << " (ASCII) ";
        Sleep(250);
    }
    Sleep(500);
    cout << endl << "\nThis produces a stream of Keystream[0],Keystream[1],... " << endl;
    Sleep(500);
    cout << "Your keystream (hex) is : ";
    for (int i = 0; i < keyStream.size(); i++) {
        cout << uppercase << hex << setfill('0') << setw(2) << (int)(*(unsigned char*)(&keyStream[i])) << " ";
    }
    Sleep(500);
    cout << "\n\nwhich are XOR'ed with the text to obtain the encryptedtext or decryptedtext.";
}

// Encyption Algorithm [ Plaintext XOR with Keystream ] Need to run Array Init,KSA,PRGA before this
void rc4System::rc4Encrypt(string plaintext, vector<unsigned char> keyStream) {
    Sleep(500);
    cout << "\nLet's XOR plaintext with keystream" << endl << endl;
    for (int i = 0; i < plaintext.size(); i++) {
        cipherText[i] = keyStream[i] ^ plaintext[i];  // Plaintext XOR with Keystream = Ciphertext
    }
}


// Decryption Algorithm [ Ciphertext XOR with Keystream ] Need to run Array Init,KSA,PRGA before this
void rc4System::rc4Decrypt(string ciphertext, vector<unsigned char> keyStream) {
    Sleep(500);
    cout << "Let's XOR ciphertext with keystream" << endl << endl;
    for (int i = 0; i < plaintext.size() + 1; i++) {
        decrypted[i] = keyStream[i] ^ ciphertext[i]; // Ciphertext XOR with Keystream = Plaintext
    }
}


// Encryption Mode
void rc4System::modeEncrypt() {
    menu.color(7);
    char select;
    system("cls");
    cout << "[ Encryption ]";
    cout << endl << endl << "Input the text: ";
    getline(cin, plaintext);
    Sleep(250);
    cout << "[+] Your Plain Text: " << plaintext << endl << endl;
    Sleep(250);
    cout << "Let's encrypt your text.." << endl;
    Sleep(500);
    cout << "Press anykey to next step.";
    cin.get();
    Sleep(500);
    arrayInit(S);
    menu.NextAlgor();
    cout << ": Key Scheduling Algorithm (KSA) :" << endl << endl;
    Sleep(250);
    cout << "Press anykey to next step.";
    cin.get();
    Sleep(500);
    system("cls");
    keySchedulAlgor(key, S);
    menu.NextAlgor();
    cout << ": Pseudo Random Generation Algorithm (PRGA) :" << endl << endl;
    Sleep(250);
    cout << "Press anykey to next step.";
    cin.get();
    pseudoRanGen(plaintext, S);
    menu.NextAlgor();
    cout << "Press anykey to next step.";
    cin.get();
    system("cls");
    Sleep(500);
    cout << "[ Result ]" << endl << endl;
    Sleep(500);
    cout << "Your Plaintext: " << plaintext;
    Sleep(500);
    cout << endl << "Your Secret Key: " << key << endl << endl;
    Sleep(500);
    cout << "Your keystream (hex) is : ";
    for (int i = 0; i < keyStream.size(); i++) {
        cout << uppercase << hex << setfill('0') << setw(2) << (int)(*(unsigned char*)(&keyStream[i])) << " ";
    }
    Sleep(500);
    rc4Encrypt(plaintext, keyStream);
    Sleep(500);
    cout << "\nYour Cipher text (hex): ";
    for (int j = 0; j < plaintext.length(); j++) {
        cout << uppercase << hex << setfill('0') << setw(2) << (int)(*(unsigned char*)(&cipherText[j])) << " ";
    }
    checkEncrypt = true;
    Sleep(1000);
    menu.gotoxy(5, 24);
    menu.color(12);
    cout << "Press Q to main menu";
    menu.color(7);
    for (int i = 0;;) {
        select = _getch();
        if (select == 'Q' || select == 'q') {
            break;
        }
    }

}

// Decryption Mode
void rc4System::modeDecrypt() {
    menu.color(7);
    system("cls");
    if (checkEncrypt == false)
    {
        menu.gotoxy(5, 2);
        cout << "You must encrypted the text first !";
    }
    else {
        cout << "[ Decryption ]" << endl << endl;
        cout << "\nYour Cipher text (hex): ";
        for (int j = 0; j < plaintext.length(); j++) {
            cout << uppercase << hex << setfill('0') << setw(2) << (int)(*(unsigned char*)(&cipherText[j])) << " ";
        }
        Sleep(500);
        cout << endl << "Your Secret Key: " << key << endl << endl;
        Sleep(500);
        cout << "Decryption do the same as Encryption for generating Keystream from Secret key";
        Sleep(500);
        cout << "and XOR the ciphertext with Keystream again will get decrypted text\n";
        Sleep(250);
        cout << "\nExample: Let A be the plain text and B be the keystream (A xor B) xor B = A \n";
        Sleep(500);
        cout << "\nYour keystream (hex) is : ";
        Sleep(250);
        for (int i = 0; i < keyStream.size(); i++) {
            cout << uppercase << hex << setfill('0') << setw(2) << (int)(*(unsigned char*)(&keyStream[i])) << " ";
        }
        cout << endl << endl;
        Sleep(500);
        rc4Decrypt(cipherText, keyStream);
        Sleep(500);
        cout << "\nYour Decrypted text (char): " << decrypted;

    }
    char select;
    Sleep(1000);
    menu.gotoxy(5, 24);
    menu.color(12);
    cout << "Press Q to main menu";
    menu.color(7);
    for (int i = 0;;) {
        select = _getch();
        if (select == 'Q' || select == 'q') {
            break;
        }
    }
}


/* main
int main(){
    HWND console = GetConsoleWindow();
    RECT ConsoleRect;
    GetWindowRect(console, &ConsoleRect);
    MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1280, 720, TRUE);
    rc4System rc4;
    rc4Menu menu;
    while(true){
    int mode = menu.RC4menu();
    if(mode == 2){
        rc4.modeEncrypt(); // Run Encrypt Mode
    }
    if(mode == 3){
        rc4.modeDecrypt(); // Run Decrypt Mode
    }
    }
    return 0;
}*/
