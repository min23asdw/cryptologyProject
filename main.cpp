// ทำหน้าที่เก็บสิ่งที่ผู้ใช้พิมมา  และนำไปเข้ารหัสผ่านวิธีการต่างๆ
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>
#include<windows.h>

//#include "enigma.h"
#include"enigma.cpp"
#include"rc4.cpp"






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
cout<<"if your want to use\n";
cout<<"type \"01\"   for enigma system [Partly Work]\n";
cout<<"type \"02\"   for RSA system[-]\n";
cout<<"type \"03\"   for RC4 system[Not yet finished]\n";
cout<<"type \"04\"   for Steganography system[Not yet finished]\n";
cout<<"type \"quit\"   to EXIT program\n";
cout<<"-------------------------------\n";
cout<<"then Choose a method encrypting or decrypting(e/d) \n";
cout<<"-------------------------------\n";


 }
void enigmainfo(){
cout << "The Enigma machine is a cipher device developed and used in the early- to mid-20th century to protect commercial, diplomatic, and military communication.\n";
cout << "It was employed extensively by Nazi Germany during World War II\n";





}
int engimasystem(){ // Don't touch  Don't touch  Don't touch  Don't touch
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
}
return 0;
}

int Rc4System(){
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


return 0;
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

    HWND console = GetConsoleWindow();
      RECT ConsoleRect;
      GetWindowRect(console, &ConsoleRect);

       MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1280, 720, TRUE);

    do{
        system("cls");
          show_Command_and_showData_From_user();
          string UserOperator, CrypType;  //CrypType is encryption or decryption
          vector<string> key;
          //char endecryp = '';
          getCommand(UserOperator,CrypType);
          UserOperator = toUpperStr(UserOperator);
          CrypType = toUpperStr(CrypType);
          if(UserOperator == "QUIT") break;

          //Mechanical

          else if(UserOperator == "01"){





            system("cls");
            enigmainfo();
            Sleep(3000);
            engimasystem();
            system("cls");
          }    //system_Enigma(inputs, CrypType, key, outputs);


          //computer modern cryptography
        //    else if(UserOperator == "02") {system("cls"); PoorishSystem();system("cls");}  //system_Poorish(inputs, CrypType, key, outputs);
           else if(UserOperator == "03") {system("cls"); Rc4System();system("cls");}  //system_Rc4(inputs, CrypType, key, outputs);
          //  else if(UserOperator == "04"){system("cls"); ShaSystem();system("cls");} //system_Sha(inputs, CrypType, key, outputs);

          else{
              cout << "---------------------------------\n";
              cout << "Invalid UserOperator.\n";
              cout << "---------------------------------\n";
          }

    }while(true);

    return 0;
}
