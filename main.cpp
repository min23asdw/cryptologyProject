// ทำหน้าที่เก็บสิ่งที่ผู้ใช้พิมมา  และนำไปเข้ารหัสผ่านวิธีการต่างๆ 
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>
//#include "enigma.h"
#include"enigma.cpp"






using namespace std;

// data form User



//

//simple text of random




//

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void show_Command_and_showData_From_user(){
cout<<"cryptography"   <<"\n";
cout<<"if your want to use   type \"number \"   for enigma system\n";
cout<<"if your want to use   type \"number \"   for enigma system\n";
cout<<"if your want to use   type \"number \"   for enigma system\n";
cout<<"if your want to use   type \"number \"   for enigma system\n";
cout<<"if your want to use   type \"number \"   for enigma system\n";
cout<<"if your want to use   type \"number \"   for enigma system\n";
cout<<"if your want to use   type \"number \"   for enigma system\n";
cout<<"if your want to use   type \"number \"   for enigma system\n";
cout<<"if your want to use   type \"number \"   for enigma system\n";


 }
int engimasystem(){
bool repeat = true;
while(repeat){
    option = "";
    choiceforencr = "";
    chosen_roter_one_s = "";
        chosen_roter_two_s = "";
        chosen_roter_three_s = "";
            currentLetter = "";
            encrypt_decrypt_output = "";
                chosen_roter_one = 0;
                chosen_roter_two = 0;
            chosen_roter_three = 0;
            rotate_position_one = 0;
        rotate_position_two = 0;
        rotate_position_three = 0;
    error = 0;
    encr_decry_length = 0;
        error = 0;
        encrypt_Toggle = NULL;
            encrypt_decrypt_output = "";
  cout << "Welcome to the Enigma console. Are you encrypting or decrypting(e/d) or to end the program press Q" << endl;

  cin >> option;

  if (option == "e" || option == "encrypting")
    {
      encrypt_Toggle = true;
      cout << "You are encrypting what would you like to encrypte:\n";
      cin >> choiceforencr;
      chose_a_roter(0);
      convert ();
      encrypt_enigma();
      cout << "Your encrypted text is <<" << encrypt_decrypt_output << ">>" << endl;
    }
  else if (option == "d" || option == "decrypting")
    {
      encrypt_Toggle = false;
      cout << "You are decrypting what would you like to decrypte:\n";
      cin >> choiceforencr;
      chose_a_roter(0);
      convert();
      encrypt_enigma();
      cout << "Your decrypted text is <<" << encrypt_decrypt_output << ">>" << endl;
    }
  else if (option == "q"){
    return 0;
  }

  else
    {
      do{
        r_option ();
    }while (option != "e" || option != "d" || option != "decrypting" || option != "encrypting" || option != "q");
    }
}return 0;
}

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

        else if(UserOperator == "03"){system("cls"); engimasystem();system("cls");}    //system_Enigma(inputs, CrypType, key, outputs);


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
