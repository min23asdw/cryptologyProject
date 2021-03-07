#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

void color(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}
void gotoxy(int x,int y){
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void back();

void whatIsRC4(){
	system("cls");
	color(7);
	gotoxy(5,2);
	cout << "What is RC4?";
	gotoxy(10,4);
	cout << "RC4 was designed in 1987 by Ron Rivest and is one of the most widely software stream cipher and used";
	gotoxy(10,5);
	cout << "in popular protocols, such as SSL (protect Internet traffic), WEP (secure wireless networks) and PDF.";
	gotoxy(10,6);
	cout << "It's considered to be fast and simple in terms of software.";
	
}


void RC4menu(){

int Set[] = {7,7,7}; // Default colors
    int counter = 1;
    char select;
    gotoxy(5,2);
    Set[0] = 12;
    cout << "The RC4 Algorithm (Use arrow key to select the menu)" << endl << endl;
    for(int i = 0;;){
    
        
        gotoxy(10,5);
        color(Set[0]);
        cout << "1. What is RC4 ?";

        gotoxy(10,6);
        color(Set[1]);
        cout << "2. Encryption";

        gotoxy(10,7);
        color(Set[2]);
        cout << "3. Decryption";

        select = _getch();

        if(select == 72 && (counter >= 2 && counter <=3)){   // 72 = up arrow key
            counter--;
        }
        if(select == 80 && (counter >= 1 && counter <=2)){   // 80 = down arrow key
            counter++;
        }
        if(select == '\r') //carriage return = enter key
        {
            if(counter == 1){
                whatIsRC4();
                break;
            }
            if(counter == 2){
                cout << "Menu 2 is Open";
            }
            if(counter == 3){
                cout << "Menu 3 is Open";
            }
        }
        Set[0] = 7;
        Set[1] = 7;
        Set[2] = 7;
        if(counter == 1){
            Set[0] = 12; // 12 is color red
        }
        if(counter == 2){
            Set[1] = 12; // 12 is color red
        }
        if(counter == 3){
            Set[2] = 12; // 12 is color red
        }


    }
}

void back(){
	RC4menu();
}
