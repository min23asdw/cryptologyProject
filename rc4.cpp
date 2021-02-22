#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
#include <windows.h>

using namespace std;

// Global Variables
vector<char> S;
string key = "";
string plaintext;

// Delay for Next Algorithm
void NextAlgor(){
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
        cout << "V";
        cout << endl << endl;
        Sleep(1000);
}

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
    cout << "the array will look like S[] = {0, 1, 2, 3, ...... , 254, 255}" << endl;
    Sleep(1000);
    cout << "After this, we will run the KSA algorithm.";
}

// Key Scheduling Algorithm (KSA)
void keySchedulAlgor(string &key,vector<char> &S){
    Sleep(1000);
    cout << ": Key Scheduling Algorithm (KSA) :" << endl << endl;
    unsigned int i = 0, j = 0;
    Sleep(1000);
    cout << "[+] Your Plain Text: " << plaintext << endl << endl;
    Sleep(500);
    cout << "[+] Enter the secret key: ";
    cin >> key;
    Sleep(500);
    cout << "    Your Secret Key: " << key << endl;
    cout << "    Your Secret Key Length: " << key.length() << endl << endl ;
    Sleep(500);
    cout << "Press anykey to next step.";
        cin.ignore();
        cin.get();
    Sleep(500);
    system("cls");
    Sleep(1000);
    cout << ": Key Scheduling Algorithm (KSA) :" << endl << endl; 
    Sleep(1000);
    cout << "The initialized array S[256] is now run through the KSA.\nThe KSA uses the secret key to scramble the array." << endl;
    Sleep(1000);
    cout << "KSA is a simple loop, in which we are having two variable i and j." << endl;
    Sleep(1000);
    cout << "We are using these variables to rearrange the array." << endl << endl;
    Sleep(1000);
    cout << "[+] The KSA scramble array S[256].. " << endl << endl;
    Sleep(500);
    cout << "         " << "Position J is : " << j << endl;
    Sleep(500);
    cout << "         " << "Swap S[i] with S[j]" << endl;
    Sleep(500);
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
        cout << "         " << "Position J is : " << j << endl;
        cout << "         " << "Swap S[i] with S[j]" << endl;
        cout << "         " << "Swapping.. " << endl << "         " << "S[" << i << "]" << " = " << S[i] << endl;
        cout << "         " << "S[" << j << "]" << " = " << S[j] << endl;
        Sleep(100);
    }
    }
    Sleep(1000);
    cout << "\n\nRearranging the array is done by using a secret key.\n\n";
    Sleep(1000);
    cout << "After this, we will run the PRGA algorithm.";
}

// Pseudo Random Generation Algorithm (PRGA)
void pseudoRanGen(){





}


// mainframe
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
        Sleep(1000);
        arrayInit(S);
        NextAlgor();
        cout << ": Key Scheduling Algorithm (KSA) :" << endl << endl;
        Sleep(500);
        cout << "Press anykey to next step.";
        cin.get();
        Sleep(1000);
        system("cls");
        keySchedulAlgor(key,S);
        NextAlgor();
        cout << ": Pseudo Random Generation Algorithm (PRGA) :" << endl << endl;
        Sleep(500);
        cout << "Press anykey to next step.";
        cin.get();
    
    }

    
}