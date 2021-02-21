#include<iostream>
#include<vector>
#include<conio.h>
#include<string>
#include<iomanip>

using namespace std;

void historyrc4(){
    cout << ": History of RC4 Encryption :" << endl << endl;
    cout << "RC4 means Rivest Cipher 4 invented by Ron Rivest in 1987 for RSA Security.\n It is a Stream Ciphers. Stream Ciphers operate on a stream of data byte by byte.\n RC4 stream cipher is one of the most widely used stream ciphers because of its simplicity and speed of operation.\n It is a variable key-size stream cipher with byte-oriented operations.\n It uses either 64 bit or 128-bit key sizes.\n It is generally used in applications such as Secure Socket Layer (SSL), Transport Layer Security (TSL), and also used in IEEE 802.11 wireless LAN std. ";
}
void workingOfRC4(){
    cout << ": Working of RC4 :" << endl << endl;
    cout << "- Encryption Procedure -" << endl << endl;
    cout << "1. The user inputs a plain text file and a secret key." << endl;
    cout << "2. The encryption engine then generates the keystream by using KSA and PRGA Algorithm." << endl;
    cout << "3. This keystream is now XOR with the plain text, this XORing is done byte by byte to produce the encrypted text." << endl;
    cout << "4. The encrypted text is then sent to the intended receiver, the \n    intended receiver will then decrypted the text and after decryption, the receiver will get the original plain text." << endl;
    cout << "- Decryption Procedure -" << endl << endl;
    cout << "Decryption is achieved by doing the same byte-wise X-OR operation on the Ciphertext.";
}

string rc4Encrypt(string input){
    string encrypted;
    

}

void commandsCheck(string key){
    if(key == "01"){
        historyrc4();
    }
    else if(key == "02"){

    }
}


int main(){
    string key;
    cout << ": The RC4 Cipher :" << endl;
    cout << "------------------" << endl;
    cout << "[01] History of RC4 Encryption" << endl;
    cout << "[02] Working of RC4" << endl;
    cout << "[03] Encryption" << endl;
    cout << "[04] Decryption" << endl << endl;
    cout << "Enter number like" << " 01 " << "to select: ";

    do{
    cin >> key;
    if(key!= "01" || key!= "02"  || key!= "03" || key!= "04"){
        cout << "Invalid Please Re-enter number 01-04" << endl;
        cout << "Enter number like" << " 01 " << "to select: ";
    }
    else{
        break;
    }
    }while(true);

    commandsCheck(key);

    

    
    
    
    
}