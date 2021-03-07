#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<string>
#include<windows.h>
#include<bitset>
#include "rc4menu.h"

using namespace std;

// Global Variables
vector<unsigned char> S;
vector<unsigned char> keyStream;
string key = "";
string plaintext;
char cipherText[256] = { ' ' };
char decrypted[256] = { ' ' };
unsigned int temp = 0;


// Array Initialization
void arrayInit(vector<unsigned char> &S){
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
        cout << "         " << "S[" << i << "]" << " = " << (int)S[i] << endl << endl;
        }
        Sleep(10);
    }
    Sleep(500);
    cout << "the array will look like S[] = {0, 1, 2, 3, ...... , 254, 255}" << endl;
    Sleep(500);
    cout << "After this, we will run the KSA algorithm.";
}

// Key Scheduling Algorithm (KSA)
void keySchedulAlgor(string &key,vector<unsigned char> &S){
    Sleep(500);
    cout << ": Key Scheduling Algorithm (KSA) :" << endl << endl;
    int i = 0, j = 0;
    Sleep(500);
    cout << "[+] Your Plain Text: " << plaintext << endl << endl;
    Sleep(250);
    cout << "[+] Enter the secret key: ";
    cin >> key;
    Sleep(250);
    cout << "    Your Secret Key: " << key << endl;
    cout << "    Your Secret Key Length: " << key.length() << endl << endl ;
    Sleep(250);
    cout << "Press anykey to next step.";
        cin.ignore();
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
        cout << "         " << "Swapping.. " << endl << "         " << "S[" << i << "]" << " = " << (int)S[i] << endl;
        cout << "         " << "S[" << j << "]" << " = " << (int)S[j] << endl;
        Sleep(100);
    }
    }
    Sleep(500);
    cout << "\n\nRearranging the array is done by using a secret key.\n\n";
    Sleep(500);
    cout << "After this, we will run the PRGA algorithm.";
}

// Pseudo Random Generation Algorithm (PRGA)
void pseudoRanGen(string plaintext,vector<unsigned char> S){
    system("cls");
    Sleep(500);
    int i=0,j=0;
    for(int k = 0; k < plaintext.size(); k++){
        i = (i+1) % 256;
        j = (j + S[i]) % 256;
        swap(S[i], S[j]);
         temp = (S[i] + S[j]) % 256;
         keyStream.insert(keyStream.begin()+k,S[temp]); // Create Keystream
    }
}

// Encyption Algorithm [ Plaintext XOR with Keystream ] Need to run Array Init,KSA,PRGA before this
void rc4Encrypt(string plaintext,vector<unsigned char> keyStream){
    for(int i = 0; i < plaintext.size(); i++){
        cipherText[i] = keyStream[i] ^ plaintext[i];  // Plaintext XOR with Keystream = Ciphertext
    }
}


// Decryption Algorithm [ Ciphertext XOR with Keystream ] Need to run Array Init,KSA,PRGA before this
void rc4Decrypt(string ciphertext,vector<unsigned char> keyStream){
        for(int i = 0; i < plaintext.size()+1; i++){
         decrypted[i] = keyStream[i] ^ ciphertext[i]; // Ciphertext XOR with Keystream = Plaintext
    }
}


// Encryption implement
void modeEncrypt(){
		color(7);
		char select;
		system("cls");
	  	cout << "[ Encryption ]";
        cout << endl << endl << "Input the text: ";
        cin >> plaintext;
        Sleep(250);
        cout << "[+] Your Plain Text: " << plaintext << endl << endl;
        Sleep(250);
        cout << "Let's encrypt your text.." << endl;
        Sleep(500);
        cout << "Press anykey to next step.";
        cin.ignore();
        cin.get();
        Sleep(500);
        arrayInit(S);
        NextAlgor();
        cout << ": Key Scheduling Algorithm (KSA) :" << endl << endl;
        Sleep(250);
        cout << "Press anykey to next step.";
        cin.get();
        Sleep(500);
        system("cls");
        keySchedulAlgor(key,S);
        NextAlgor();
        cout << ": Pseudo Random Generation Algorithm (PRGA) :" << endl << endl;
        Sleep(250);
        cout << "Press anykey to next step.";
        cin.get();
        pseudoRanGen(plaintext,S);
        Sleep(500);
        cout << "[ Result ]" << endl << endl;
        Sleep(250);
        cout << "Your Plaintext: " << plaintext;
        Sleep(250);
        cout << endl << "Your Secret Key: " << key << endl << endl;
        Sleep(500);
        cout << "Your keystream (hex) is : ";
        for(int i = 0 ; i<keyStream.size(); i++){
            cout << uppercase << hex << setfill('0') << setw(2) << (int)(*(unsigned char*)(&keyStream[i])) << " ";
        }
        Sleep(500);
        rc4Encrypt(plaintext,keyStream);
        Sleep(250);
        cout << "\nYour Encrypted text (hex): " ;
        for(int j = 0; j < plaintext.length(); j++){
		cout << uppercase << hex << setfill('0') << setw(2) << (int)(*(unsigned char*)(&cipherText[j])) << " ";
        }
        	Sleep(1000);
        	gotoxy(5,24);
			color(12);
			cout << "Press Q to main menu";
			color(7);
			for(int i = 0;;){
				select = _getch();
				if(select == 'Q' || select == 'q'){
					break;
				}
			}
			
}

// Decryption implement
void modeDecrypt(){
	color(7);
	char select;
	system("cls");
	cout << "In the process of building...";
	Sleep(1000);
        	gotoxy(5,24);
			color(12);
			cout << "Press Q to main menu";
			color(7);
			for(int i = 0;;){
				select = _getch();
				if(select == 'Q' || select == 'q'){
					break;
				}
			}
}


// mainframe
int main(){
	while(true){
    int mode = RC4menu();
    if(mode == 2){
    	modeEncrypt();
	}
	if(mode == 3){
		modeDecrypt();
	}
    }
    return 0;
    


/*
    
        cout << "[ Encryption ]";
        cout << endl << endl << "Input the text: ";
        cin >> plaintext;
        cout << "[+] Your Plain Text: " << plaintext << endl << endl;
    //    Sleep(500);
        cout << "Let's encrypt your text.." << endl;
        cout << "Press anykey to next step.";
        cin.ignore();
        cin.get();
     //   Sleep(1000);
        arrayInit(S);
        NextAlgor();
        cout << ": Key Scheduling Algorithm (KSA) :" << endl << endl;
      //  Sleep(500);
        cout << "Press anykey to next step.";
        cin.get();
     //   Sleep(1000);
        system("cls");
        keySchedulAlgor(key,S);
        NextAlgor();
        cout << ": Pseudo Random Generation Algorithm (PRGA) :" << endl << endl;
      //  Sleep(500);
        cout << "Press anykey to next step.";
        cin.get();
        pseudoRanGen(plaintext,S);
        cout << "Your Plaintext: " << plaintext;
        cout << endl << "Your Secret Key: " << key << endl << endl;
        cout << "Your keystream (hex) is : ";
        for(int i = 0 ; i<keyStream.size(); i++){
            cout << uppercase << hex << setfill('0') << setw(2) << (int)(*(unsigned char*)(&keyStream[i])) << " ";
        }
        rc4Encrypt(plaintext,keyStream);
        cout << "\nYour Encrypted text (hex): " ;
        for(int j = 0; j < plaintext.length(); j++){
		cout << uppercase << hex << setfill('0') << setw(2) << (int)(*(unsigned char*)(&cipherText[j])) << " ";
        }

        rc4Decrypt(cipherText,keyStream);
        cout << "\nYour Decrypted text (char): " ;
        cout << decrypted;

    */

    
}