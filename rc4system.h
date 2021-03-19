#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<string>
#include<windows.h>
#include<bitset>
#include "rc4menu.h"

using namespace std;

class rc4System{
    vector<unsigned char> S;
    vector<unsigned char> keyStream;
    string hexCipher = "";
    string cipher = "";
    string key = "";
    string plaintext = "";
    char cipherText[256] = { ' ' };
    char decrypted[256] = { ' ' };
    unsigned int temp = 0;
    bool checkEncrypt = false;
    rc4Menu menu;
    public:
        void arrayInit(vector<unsigned char> &);
        void keySchedulAlgor(string &, vector<unsigned char> &,string);
        void pseudoRanGen(string,vector<unsigned char>);
        void rc4Encrypt(string,vector<unsigned char>);
        void rc4Decrypt(string,vector<unsigned char>);
        void modeEncrypt();
        void modeDecrypt();
        string hexToASCII(string);
};

string rc4System::hexToASCII(string hex){

    // initialize the ASCII code string as empty. 
    string ascii = ""; 
    for (size_t i = 0; i < hex.length(); i += 2) 
    { 
        // extract two characters from hex string 
        string part = hex.substr(i, 2); 
  
        // change it into base 16 and  
        // typecast as the character 
        char ch = stoul(part, nullptr, 16); 
  
        // add this char to final ASCII string 
        ascii += ch; 
    } 
    return ascii; 
} 

// Array Initialization
void rc4System::arrayInit(vector<unsigned char> &S){
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
    for(i = 0; i<256 ; i++){
        S.insert(S.begin()+i,(unsigned char) i);
        if((i % 15) == 0){
        system("cls");
        cout << ": Array Initialization :" << endl << endl;
        cout << "The first step is the array initialization. It is a character array of size 256" << endl;
        cout << "for every element of the array, we initialize S[i] to i." << endl << endl;
        cout << "[+] Array initialize.." << endl << endl;
        cout << "         " << "S[" << i << "]" << " = " << dec << (int)S[i] << " (ASCII) " << endl << endl;
        }
        Sleep(10);
    }
    Sleep(500);
    cout << "the array will look like S[] = {0, 1, 2, 3, ...... , 254, 255}" << endl;
    Sleep(500);
    cout << "After this, we will run the KSA algorithm.";
}

// Key Scheduling Algorithm (KSA)
void rc4System::keySchedulAlgor(string &key,vector<unsigned char> &S,string text){
    Sleep(500);
    cout << ": Key Scheduling Algorithm (KSA) :" << endl << endl;
    int i = 0, j = 0;
    Sleep(500);
    cout << "[+] Your Text as (char) is: " << text << endl << endl;
    Sleep(250);
    do{
    cout << "[+] Enter the secret key: ";
    getline(cin,key);
        if(key == ""){
            cout << "Invalid Input" << endl;
        }
    }while(key == "");
    Sleep(250);
    cout << "    Your Secret Key: " << key << endl;
    cout << "    Your Secret Key Length: " << key.length() << endl << endl ;
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
        if((i % 5) == 0){
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
void rc4System::pseudoRanGen(string plaintext,vector<unsigned char> S){
    system("cls");
    keyStream.clear();
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
    int i=0,j=0;
    for(int k = 0; k < plaintext.size(); k++){
        i = (i+1) % 256;
        j = (j + S[i]) % 256;
        swap(S[i], S[j]);
         temp = (S[i] + S[j]) % 256;
         keyStream.insert(keyStream.begin()+k,S[temp]); // Create Keystream
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
        for(int i = 0 ; i<keyStream.size(); i++){
            cout << uppercase << hex << setfill('0') << setw(2) << (int)(*(unsigned char*)(&keyStream[i])) << " ";
        }
    Sleep(500);
    cout << "\n\nwhich are XOR'ed with the text to obtain the encryptedtext or decryptedtext.";
}

// Encyption Algorithm [ Plaintext XOR with Keystream ] Need to run Array Init,KSA,PRGA before this
void rc4System::rc4Encrypt(string plaintext,vector<unsigned char> keyStream){
    Sleep(500);
    cout << "\nLet's XOR plaintext with keystream" << endl << endl;
    for(int i = 0; i < plaintext.size(); i++){
        cipherText[i] = keyStream[i] ^ plaintext[i];  // Plaintext XOR with Keystream = Ciphertext
    }
}


// Decryption Algorithm [ Ciphertext XOR with Keystream ] Need to run Array Init,KSA,PRGA before this
void rc4System::rc4Decrypt(string ciphertext,vector<unsigned char> keyStream){
        Sleep(500);
        cout << "\nLet's XOR ciphertext with keystream" << endl << endl;
        for(int i = 0; i < ciphertext.size()+1; i++){
         decrypted[i] = keyStream[i] ^ ciphertext[i]; // Ciphertext XOR with Keystream = Plaintext
    }
}


// Encryption Mode
void rc4System::modeEncrypt(){
		menu.color(7);
		char select;
		system("cls");
	  	cout << "[ Encryption ]";
        do{
        cout << endl << endl << "Input the text: ";
        getline(cin,plaintext);
            if(plaintext == ""){
                cout << "Invalid Input\n";
            }
        }while(plaintext == "");
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
        keySchedulAlgor(key,S,plaintext);
        menu.NextAlgor();
        cout << ": Pseudo Random Generation Algorithm (PRGA) :" << endl << endl;
        Sleep(250);
        cout << "Press anykey to next step.";
        cin.get();
        pseudoRanGen(plaintext,S);
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
        for(int i = 0 ; i<keyStream.size(); i++){
            cout << uppercase << hex << setfill('0') << setw(2) << (int)(*(unsigned char*)(&keyStream[i])) << " ";
        }
        Sleep(500);
        rc4Encrypt(plaintext,keyStream);
        Sleep(500);
        cout << "\nYour Cipher text (hex): " ;
        for(int j = 0; j < plaintext.length(); j++){
		cout << uppercase << hex << setfill('0') << setw(2) << (int)(*(unsigned char*)(&cipherText[j])) << " ";
        }
        checkEncrypt = true;
        	Sleep(1000);
        	menu.gotoxy(5,24);
			menu.color(12);
			cout << "Press Q to main menu";
			menu.color(7);
			for(int i = 0;;){
				select = _getch();
				if(select == 'Q' || select == 'q'){
					break;
				}
			}
			
}

// Decryption Mode
void rc4System::modeDecrypt(){
	menu.color(7);
    system("cls");
        cout << "[ Decryption ]" << endl << endl;
        cout << "\nInput Your Cipher text as (hex) like this (Input: a63f8a110e): " ;
        do{
            cin >> hexCipher;
            cipher = hexToASCII(hexCipher);
        }while(hexCipher == "");
        Sleep(250);
        cout << endl << "Run the KSA,PRGA to generate keystream from your secret key" << endl;
        Sleep(500);
        cout << "Press anykey to next step.";
        cin.ignore();
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
        keySchedulAlgor(key,S,cipher);
        menu.NextAlgor();
        cout << ": Pseudo Random Generation Algorithm (PRGA) :" << endl << endl;
        Sleep(250);
        cout << "Press anykey to next step.";
        cin.get();
        pseudoRanGen(cipher,S);
        menu.NextAlgor();
        cout << "Press anykey to next step.";
        cin.get();
        system("cls");
        Sleep(500);
        cout << "[ Result ]" << endl << endl;
        Sleep(500);
        cout << "Your Ciphertext as (hex): " << hexCipher;
        Sleep(500);
        cout << endl << "Your Secret Key: " << key << endl << endl;
        Sleep(500);
        cout << "Your keystream (hex) is : ";
        for(int i = 0 ; i<keyStream.size(); i++){
            cout << uppercase << hex << setfill('0') << setw(2) << (int)(*(unsigned char*)(&keyStream[i])) << " ";
        }
        Sleep(500);
        rc4Decrypt(cipher,keyStream);
        Sleep(500);
        cout << "\nYour Decrypted text (char): " << decrypted << endl;

    
	char select;
	Sleep(1000);
        	menu.gotoxy(5,24);
			menu.color(12);
			cout << "Press Q to main menu";
			menu.color(7);
			for(int i = 0;;){
				select = _getch();
				if(select == 'Q' || select == 'q'){
					break;
				}
			}
}