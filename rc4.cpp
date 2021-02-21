#include<iostream>
#include<vector>
#include <algorithm>
#include<string>
#include<iomanip>
#include <windows.h>

using namespace std;

// Global Variables
vector<char> S;
string key = "";
string plaintext;

// Array Initialization
void arrayInit(vector<char> &S){
    unsigned int i = 0;
        system("cls");
        cout << ": Array Initialization :" << endl << endl;
        Sleep(1000);
        cout << "The first step is the array initialization. It is a character array of size 256" << endl;
        Sleep(1000);
        cout << "for every element of the array, we initialize S[i] to i." << endl << endl;
        Sleep(1000);
        cout << "[+] Array initialize.." << endl << endl;
        Sleep(1000);
    for(i = 0; i<256 ; i++){
        S.insert(S.begin()+i,i);
        if((i % 15) == 0){
        system("cls");
        cout << ": Array Initialization :" << endl << endl;
        cout << "The first step is the array initialization. It is a character array of size 256" << endl;
        cout << "for every element of the array, we initialize S[i] to i." << endl << endl;
        cout << "[+] Array initialize.." << endl << endl;
        cout << "         " << "S[" << i << "]" << " = " << i << endl << endl;
        }
        Sleep(10);
    }
    Sleep(1000);
    cout << "the array will look like S[] = {0, 1, 2, 3, ------, 254, 255}" << endl;
    Sleep(1000);
    cout << "After this, we will run the KSA algorithm.";
}

// Key Scheduling Algorithm
void keySchedulAlgor(string &key,vector<char> &S){
    Sleep(1000);
    cout << ": Key Scheduling Algorithm :" << endl << endl;
    unsigned int i = 0, j = 0;
    Sleep(1000);
    cout << "[+] Your Plain Text: " << plaintext << endl << endl;
    Sleep(500);
    cout << "[+] Enter the secret key: ";
    cin >> key;
    Sleep(500);
    cout << "    Your Secret Key: " << key << endl;
    for (i = 0; i < 256; i++)
    {
        j = (j + S[i] + key.at(i % key.length())) % 256;
        swap(S[i], S[j]);
    }
}

int main(){
    string select;
    system("cls");
    cout << "The RC4 cipher" << endl << endl;
    cout << "[00] How it work ?" << endl;
    cout << "[01] Encryption" << endl;
    cout << "[02] Decryption" << endl;
    cout << "Select by enter number 00-02 : ";
    cin >> select;
    if(select == "01"){
        system("cls");
        Sleep(500);
        cout << "[ Encryption ]";
        cout << endl << endl << "Input the text: ";
        cin >> plaintext;
        cout << "[+] Your Plain Text: " << plaintext << endl << endl;
        Sleep(500);
        cout << "Let's encrypt your text.." << endl;
        cout << "Press anykey to next step.";
        cin.ignore();
        cin.get();
        Sleep(2000);
        arrayInit(S);
        Sleep(500);
        cout << endl << endl;
        Sleep(500);
        cout << "___________________________________________________________________________________" << endl << endl;
        Sleep(1000);
        cout << "|\n";
        Sleep(500);
        cout << "|\n";
        Sleep(500);
        cout << "|\n";
        Sleep(500);
        cout << "|\n";
        Sleep(500);
        cout << "|\n";
        Sleep(500);
        cout << "V";
        cout << endl << endl;
        Sleep(1000);
        cout << ": Key Scheduling Algorithm :" << endl << endl;
        Sleep(500);
        cout << "Press anykey to next step.";
        cin.ignore();
        cin.get();
        Sleep(1000);
        system("cls");
        keySchedulAlgor(key,S);
    }

    
}