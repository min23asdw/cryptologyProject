#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <cstring>
#include <vector>
#include "display.h"
#include "UI.h"
#include "enigmaSystem.h"
#include "enigmaMain.h"


using namespace std;

    void enigmaMain::writetext(){
      ofstream target;
      target.open("manual.txt");
      string text;
      while(getline(cin,text)){
        if(  text   ==  "#Y"){break;}
        target << text << "\n";
      }
      target.close();
    }



    void enigmaMain::showtext(string sourcetext){
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


    void enigmaMain::run(){

      HWND console = GetConsoleWindow();
      RECT ConsoleRect;
      GetWindowRect(console, &ConsoleRect);

      MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1280, 720, TRUE);

      display show;
      Enigma enigma;
      
      cout << "Take a look at the image. You can set up the maching by creating and editing <eSetup>\n";
      cout << "Close the image to continue\n";

      cout << "Close the image to continue\n";
      show.showImage("display/setup.bmp", "howitwork-setup", 1268, 498);

      cout << "Close the image to continue\n";
      show.showImage("display/wiring.bmp", "howitwork-wiring", 1840, 634);

      while(true){ system("cls");
      cout << "TYPE THE NUMBER TO SELECT\n";
      cout << "[01] to encrypt / [02] to decrypt(X) / [03] to exit\n";
      string Command;
      cin >> Command;



      if(Command == "01" || Command == "1"){
        char* sourcelocation = "plain.txt";
        char* outputlocation = "encrypt.txt";
        char* steplocation = "elog.txt";
        system("cls");       cout << "01 for text file / 02 for manual\n";
        string Op;
        cin >> Op;
        enigma.InitEnigma();
        enigma.TryUserSetup();

        if(Op == "01" || Op == "1"){
          system("cls");
          enigma.ProcessFile(sourcelocation, outputlocation, steplocation );
          cout << "You text data is:  \n" << "\n"<< "\n"<< "\n";

          showtext(sourcelocation);
          cin.clear();
          cout << "Press Enter to Continue";
          cin.ignore();
        }else if(Op == "02" || Op == "2"){
          system("cls");

          cout << "You text data is: (type \"#Y\" and enter to encrypt) \n" << "\n";
          writetext();
          enigma.ProcessFile( "manual.txt", outputlocation, steplocation );
        }



        enigma.reset();

        cout << "\n\nencrypt data is:  \n" << "\n"<< "\n"<< "\n";
        Sleep(2000);
        showtext(outputlocation);
        cout << "Close the image to continue\n";
        show.showImage("display/howitwork.bmp", "howitwork", 420, 209);
        cout << "Close the image to continue\n";
        Sleep(2000);
        showtext(steplocation);
        cin.clear();
        cout << "Press Enter to Continue";
        cin.ignore();
        system("cls");
      }



      else if(Command == "02" || Command == "2"){
        char* sourcelocation = "encrypttext.txt";
        char* outputlocation = "decrypt.txt";
        char* steplocation = "dlog.txt";
        system("cls");       cout << "01 for text file / 02 for manual\n";
        string Op;
        cin >> Op;
        enigma.InitEnigma();
        enigma.TryUserSetup();

        if(Op == "01" || Op == "1"){
          system("cls");
          enigma.reset();
          enigma.ProcessFile(sourcelocation, outputlocation, steplocation );
          cout << "You encrypt data is:  \n" << "\n"<< "\n"<< "\n";
          showtext(sourcelocation);
          cin.clear();
          cout << "Press Enter to Continue";
          cin.ignore();
        }else if(Op == "02" || Op == "2"){
          system("cls");
          cout << "You text data is: (type \"#Y\" and enter to decrypt) \n" << "\n";
          writetext();
          enigma.ProcessFile( "manual.txt", outputlocation, steplocation );


        }

        cout << "\n\ndecrypt data is:  \n" << "\n"<< "\n"<< "\n";
        Sleep(2000);
        showtext(outputlocation);
        cout << "Close the image to continue\n";
        show.showImage("display/howitwork.bmp", "howitwork", 420, 209);
        Sleep(2000);
        showtext(steplocation);
        cin.clear();
        cout << "Press Enter to Continue";
        cin.ignore();
        system("cls");}
        if(Command == "03" || Command == "3"){system("cls");break;}


        std::remove("encrypt.txt");
        std::remove("decrypt.txt");
        std::remove("dlog.txt");
        std::remove("elog.txt");
        std::remove("manual.txt");
      }
    }

    bool enigmaMain::menu()
    {
        UI enigmaMenu;

        const vector<string> textFileName
        {
            "resources/enigma1.txt",
            "resources/enigma2.txt",
            "resources/enigma3.txt"
        };

        const vector<string> headings
        {
            "Enigma",
            "History",
            "How it works?"
        };

        enigmaMenu.addMenuItems("What is Enigma?", 7);
        enigmaMenu.addMenuItems("Encrypt/Decrypt", 7);
        enigmaMenu.addMenuItems("Exit to main menu", 7);

        while (true)
        {
            enigmaMenu.clearScreen();
            int menuRes = enigmaMenu.menu("Enigma");
            int textRes;
            if (menuRes == 0)
            {
                textRes = enigmaMenu.textPage(textFileName, headings);
                if (textRes)
                {
                    enigmaMenu.clearScreen();
                    continue;
                }
            }
            if (menuRes == 1)
            {
                enigmaMenu.clearScreen();
                run();
            }
            if (menuRes == 2)
            {
                enigmaMenu.clearScreen();
                return true;
            }
        }

        return true;
    }
