#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstring>
#include "display.h"
#include "enigmaSystem.h"


using namespace std;

    void writetext(){
      ofstream target;
      target.open("manual.txt");
      string text;
      while(getline(cin,text)){
        if(  text   ==  "#Y"){break;}
        target << text << "\n";
      }
      target.close();
    }



    void showtext(string sourcetext){
      ifstream file;

      file.open (sourcetext);
      string text;
      int i =0;
      while(getline(file,text)){
        if(i==17){Sleep(10000);}
        if(i>17){Sleep(100);}
        cout << text << "\n";
        i++;
      }
      file.close();
    }


    int main(){

      HWND console = GetConsoleWindow();
      RECT ConsoleRect;
      GetWindowRect(console, &ConsoleRect);

      MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1280, 720, TRUE);

      display show;

      while(true){ system("cls");
      cout << "01 for encrypt / 02 for decrypt(X) / 03 for exit to main\n";
      string Command;
      cin >> Command;



      if(Command == "01"){
        char* sourcelocation = "plain.txt";
        char* outputlocation = "encrypt.txt";
        char* steplocation = "elog.txt";
        system("cls");       cout << "01 for text file / 02 for manual\n";
        string Op;
        cin >> Op;
        InitEnigma();
        TryUserSetup();

        if(Op == "01"){
          system("cls");
          ProcessFile(sourcelocation, outputlocation, steplocation );
          cout << "You text data is:  \n" << "\n"<< "\n"<< "\n";

          showtext(sourcelocation);

        }else if(Op == "02"){
          system("cls");

          cout << "You text data is: (type \"#Y\" to encrypt) \n" << "\n";
          writetext();
          ProcessFile( "manual.txt", outputlocation, steplocation );
        }



        reset();

        cout << "\n\nencrypt data is:  \n" << "\n"<< "\n"<< "\n";
        Sleep(2000);
        showtext(outputlocation);
        show.showImage("display/howitwork.bmp", "howitwork", 420, 209);
        Sleep(2000);
        showtext(steplocation);
        cout << "Press Enter to Continue";
        cin.ignore();
        system("cls");
      }



      else if(Command == "02"){
        char* sourcelocation = "encrypttext.txt";
        char* outputlocation = "decrypt.txt";
        char* steplocation = "dlog.txt";
        system("cls");       cout << "01 for text file / 02 for manual\n";
        string Op;
        cin >> Op;
        InitEnigma();
        TryUserSetup();

        if(Op == "01"){
          system("cls");
          reset();
          ProcessFile(sourcelocation, outputlocation, steplocation );
          cout << "You encrypt data is:  \n" << "\n"<< "\n"<< "\n";
          showtext(sourcelocation);

        }else if(Op == "02"){
          system("cls");
          cout << "You text data is: (type \"#Y\" to decrypt) \n" << "\n";
          writetext();
          ProcessFile( "manual.txt", outputlocation, steplocation );


        }

        cout << "\n\ndecrypt data is:  \n" << "\n"<< "\n"<< "\n";
        Sleep(2000);
        showtext(outputlocation);
        show.showImage("display/howitwork.bmp", "howitwork", 420, 209);
        Sleep(2000);
        showtext(steplocation);
        cout << "Press Enter to Continue";
        cin.ignore();
        system("cls");}
        if(Command == "03"){system("cls");break;}


        std::remove("encrypt.txt");
        std::remove("decrypt.txt");
        std::remove("dlog.txt");
        std::remove("elog.txt");
        std::remove("manual.txt");
      }

      return 0;
    }
