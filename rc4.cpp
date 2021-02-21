#include<iostream>
#include<vector>
#include<conio.h>
#include<string>
#include<iomanip>

using namespace std;

void menuRC4(){
    cout << ": The RC4 Cipher :" << endl;
    cout << "------------------" << endl;
    cout << "[01] History of RC4 Encryption" << endl;
    cout << "[02] Working of RC4" << endl;
    cout << "[03] Encryption" << endl;
    cout << "[04] Decryption" << endl << endl;
    cout << "Enter number like" << " 01 " << "to select: ";
}
void historyrc4(){
    system("cls");
    cout << ": History of RC4 Encryption :" << endl << endl;
    cout << "RC4 means Rivest Cipher 4 invented by Ron Rivest in 1987 for RSA Security.\n It is a Stream Ciphers. Stream Ciphers operate on a stream of data byte by byte.\n RC4 stream cipher is one of the most widely used stream ciphers because of its simplicity and speed of operation.\n It is a variable key-size stream cipher with byte-oriented operations.\n It uses either 64 bit or 128-bit key sizes.\n It is generally used in applications such as Secure Socket Layer (SSL), Transport Layer Security (TSL), and also used in IEEE 802.11 wireless LAN std. ";
}
void workingOfRC4(){
    system("cls");
    cout << ": Working of RC4 :" << endl << endl;
    cout << "- Encryption Procedure -" << endl << endl;
    cout << "1. The user inputs a plain text file and a secret key." << endl;
    cout << "2. The encryption engine then generates the keystream by using KSA and PRGA Algorithm." << endl;
    cout << "3. This keystream is now XOR with the plain text, this XORing is done byte by byte to produce the encrypted text." << endl;
    cout << "4. The encrypted text is then sent to the intended receiver, the \n    intended receiver will then decrypted the text and after decryption, the receiver will get the original plain text." << endl;
    cout << "- Decryption Procedure -" << endl << endl;
    cout << "Decryption is achieved by doing the same byte-wise X-OR operation on the Ciphertext.";
}


// Array Initialization
void arrayInit(vector<char> &s){
    cout << "The first step is the array initialization. It is a character array of size 256" << endl;
    for(int i = 0; i<256; i++){
        system("cls");
        s[i] = i;
        cout << "for every element of the array, we initialize S[i] to i." << endl;
        cout << "Array initialize.." << endl << endl;
        cout << "S[" << i << "]" << " = " << i; << endl;
    }
    cout << "After this, we will run the KSA algorithm";
}

// Key Scheduling Algorithm (KSA)
void keySchedulingAlgo(vector<char> &s, char KSAkey[]){
    unsigned int i = 0, j = 0;
    unsigned KSAkeylength = strlen(KSAkey);
    char tempS;

    for(i = 0; i<256; i++){
        j = (j + s[i] + KSAkey[ i % KSAkeylength]) % 256;
        tempS = s[i]; // Swap the S[i] , S[j]
        s[i] = s[j];
        s[j] = tempS; 
    }
}

void psudoRanGenAlgor(vector<char> &s,)

// RC4 Encryption Processing ..
void rc4Encrypt(vector<char> &s,string &plaintext){
    string encrypted;
    vector<char> KSAkey;
    char KSAtemp[100];
    arrayInit(s);
    cout << "Enter a secret key for KSA algorithm :";
    cin >> KSAtemp;
    keySchedulingAlgo(s,KSAtemp);
    
    
    
    
    
    
    
    

    

}

void commandsCheck(string key,vector<char> &s,){
    if(key == "01"){
        historyrc4();
    }
    else if(key == "02"){
        workingOfRC4();
    }
    else if(key == "03"){
        cout << "Enter text for encrypt: ";
    
        cout << "Let see how RC4 encryption" << endl;
        rc4Encrypt(s,plaintext);
    }
    else if(key == "04"){
        cout << "Let see how RC4 decryption" << endl;

    }
    else if(key == "exit"){
        system("cls");
        menuRC4();
        do{
        cin >> key;
        if(key!= "01" || key!= "02"  || key!= "03" || key!= "04"){
        cout << "Invalid Please Re-enter number 01-04" << endl;
        system("cls");
        menuRC4();
        }
        else{
         break;
         }
        }while(true);
    }
}


int main(){
    string key;
    string plaintext;
    vector<char> s;
    system("cls");
    menuRC4();

    do{
    cin >> key;
    if(key!= "01" || key!= "02"  || key!= "03" || key!= "04"){
        cout << "Invalid Please Re-enter number 01-04" << endl;
        system("cls");
        menuRC4();
    }
    else{
        break;
    }
    }while(true);

    commandsCheck(key,s);

    

    
    
    
    
}