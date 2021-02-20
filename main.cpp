#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;


string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void show_Command_and_showData_From_user(){
cout<<"if your want to use   type \"03\"   for enigma system\n"; }

void getCommand(string &UserOperator,string &CrypType){
cout << "Please inputs your Operator: ";

//string inputs;
string text;
getline(cin,text);
int length = text.length();
int end = text.find_first_of(" ");
UserOperator = text.substr(0,end);
CrypType = text.substr(end+1,length);

}
//system_scytale(inputs, CrypType, CrypType, outputs);
//system_Atbash(inputs, CrypType, key, outputs);
//system_Enigma(inputs, CrypType, key, outputs);
//system_SHA2(inputs, CrypType, key, outputs);
//system_Base64(inputs, CrypType, key, outputs);

int main(){
//  template<class T>
    vector<string> inputs;
    vector<string> key;
    vector<string> outputs;



    do{
        show_Command_and_showData_From_user();
        string UserOperator, CrypType;  //CrypType is encryption or decryption
        vector<string> key;
        //char endecryp = '';
        getCommand(UserOperator,CrypType);
        UserOperator = toUpperStr(UserOperator);
        CrypType = toUpperStr(CrypType);
        if(UserOperator == "EXIT") break;
        //Classic cryptography

        //else if(UserOperator == "01 ancient Greek scytale") {system("cls"); system("scytale.exe");system("cls");}  //system_scytale(inputs, CrypType, CrypType, outputs);
        //else if(UserOperator == "02 Atbash") { system("cls");system("Atbash.exe");system("cls");}  //system_Atbash(inputs, CrypType, key, outputs);

        //Mechanical

        else if(UserOperator == "03"){system("cls"); system("enigma.exe");system("cls");}    //system_Enigma(inputs, CrypType, key, outputs);


        //computer modern cryptography

        //else if(UserOperator == "04 SHA2") {system("cls"); system("SHA2.exe");system("cls");}  //system_SHA2(inputs, CrypType, key, outputs);
        //  else if(UserOperator == "05 Base64"){system("cls"); system("Base64.exe");system("cls");} //system_Base64(inputs, CrypType, key, outputs);

        else{
            cout << "---------------------------------\n";
            cout << "Invalid UserOperator.\n";
            cout << "---------------------------------\n";
        }
    }while(true);

    return 0;
}
