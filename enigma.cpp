//Enigma Machine beta
#include <iostream>
#include <string>
#include <conio.h>
#include <algorithm>
#include <vector>
#include <iterator>
#include <array>
//Namespace
using namespace std;
//Global variables
string option;
string choiceforencr;
string chosen_roter_one_s;
string chosen_roter_two_s;
string chosen_roter_three_s;
string currentLetter;
string encrypt_decrypt_output = "";
int chosen_roter_one;
int chosen_roter_two;
int chosen_roter_three;
int rotate_position_one;
int rotate_position_two;
int rotate_position_three;
int error = 0;
bool encrypt_Toggle = true;
int encr_decry_length;
//Function declarations
int enc_Decry_f_string();
//Roters
int roter_1(){
        string myArray_one[26] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
        string myArray_one_decrypt[26] = {"z","y","x","w","v","u","t","s","r","q","p","o","n","m","l","k","j","i", "h","g","f","e","d","c","b","a"};
    // rotation to the right by x amount
    if (encrypt_Toggle == true){
        rotate(reverse_iterator<string*>(end(myArray_one)),
                reverse_iterator<string*>(end(myArray_one)) + rotate_position_one,
                reverse_iterator<string*>(myArray_one));
    }
    else if (encrypt_Toggle == false){
        rotate(reverse_iterator<string*>(end(myArray_one_decrypt)),
                reverse_iterator<string*>(end(myArray_one_decrypt)) + (rotate_position_one + 26),
                reverse_iterator<string*>(myArray_one_decrypt));
    }
    if(currentLetter == "a"){currentLetter = myArray_one[0];}
    else if(currentLetter == "b"){currentLetter = myArray_one[1];}
    else if(currentLetter == "c"){currentLetter = myArray_one[2];}
    else if(currentLetter == "d"){currentLetter = myArray_one[3];}
    else if(currentLetter == "e"){currentLetter = myArray_one[4];}
    else if(currentLetter == "f"){currentLetter = myArray_one[5];}
    else if(currentLetter == "g"){currentLetter = myArray_one[6];}
    else if(currentLetter == "h"){currentLetter = myArray_one[7];}
    else if(currentLetter == "i"){currentLetter = myArray_one[8];}
    else if(currentLetter == "j"){currentLetter = myArray_one[9];}
    else if(currentLetter == "k"){currentLetter = myArray_one[10];}
    else if(currentLetter == "l"){currentLetter = myArray_one[11];}
    else if(currentLetter == "m"){currentLetter = myArray_one[12];}
    else if(currentLetter == "n"){currentLetter = myArray_one[13];}
    else if(currentLetter == "o"){currentLetter = myArray_one[14];}
    else if(currentLetter == "p"){currentLetter = myArray_one[15];}
    else if(currentLetter == "q"){currentLetter = myArray_one[16];}
    else if(currentLetter == "r"){currentLetter = myArray_one[17];}
    else if(currentLetter == "s"){currentLetter = myArray_one[18];}
    else if(currentLetter == "t"){currentLetter = myArray_one[19];}
    else if(currentLetter == "u"){currentLetter = myArray_one[20];}
    else if(currentLetter == "v"){currentLetter = myArray_one[21];}
    else if(currentLetter == "w"){currentLetter = myArray_one[22];}
    else if(currentLetter == "x"){currentLetter = myArray_one[23];}
    else if(currentLetter == "y"){currentLetter = myArray_one[24];}
    else if(currentLetter == "z"){currentLetter = myArray_one[25];}
    else{currentLetter = currentLetter;}
rotate_position_one += 1;
}
int roter_2(){
        string myArray_one[26] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
        string myArray_one_decrypt[26] = {"z","y","x","w","v","u","t","s","r","q","p","o","n","m","l","k","j","i", "h","g","f","e","d","c","b","a"};
    // rotation to the right by x amount
    if (encrypt_Toggle == true){
        rotate(reverse_iterator<string*>(end(myArray_one)),
                reverse_iterator<string*>(end(myArray_one)) + rotate_position_one,
                reverse_iterator<string*>(myArray_one));
    }
    else if (encrypt_Toggle == false){
        rotate(reverse_iterator<string*>(end(myArray_one_decrypt)),
                reverse_iterator<string*>(end(myArray_one_decrypt)) + (rotate_position_one + 26) ,
                reverse_iterator<string*>(myArray_one_decrypt));
    }
    if(currentLetter == "a"){currentLetter = myArray_one[0];}
    else if(currentLetter == "b"){currentLetter = myArray_one[1];}
    else if(currentLetter == "c"){currentLetter = myArray_one[2];}
    else if(currentLetter == "d"){currentLetter = myArray_one[3];}
    else if(currentLetter == "e"){currentLetter = myArray_one[4];}
    else if(currentLetter == "f"){currentLetter = myArray_one[5];}
    else if(currentLetter == "g"){currentLetter = myArray_one[6];}
    else if(currentLetter == "h"){currentLetter = myArray_one[7];}
    else if(currentLetter == "i"){currentLetter = myArray_one[8];}
    else if(currentLetter == "j"){currentLetter = myArray_one[9];}
    else if(currentLetter == "k"){currentLetter = myArray_one[10];}
    else if(currentLetter == "l"){currentLetter = myArray_one[11];}
    else if(currentLetter == "m"){currentLetter = myArray_one[12];}
    else if(currentLetter == "n"){currentLetter = myArray_one[13];}
    else if(currentLetter == "o"){currentLetter = myArray_one[14];}
    else if(currentLetter == "p"){currentLetter = myArray_one[15];}
    else if(currentLetter == "q"){currentLetter = myArray_one[16];}
    else if(currentLetter == "r"){currentLetter = myArray_one[17];}
    else if(currentLetter == "s"){currentLetter = myArray_one[18];}
    else if(currentLetter == "t"){currentLetter = myArray_one[19];}
    else if(currentLetter == "u"){currentLetter = myArray_one[20];}
    else if(currentLetter == "v"){currentLetter = myArray_one[21];}
    else if(currentLetter == "w"){currentLetter = myArray_one[22];}
    else if(currentLetter == "x"){currentLetter = myArray_one[23];}
    else if(currentLetter == "y"){currentLetter = myArray_one[24];}
    else if(currentLetter == "z"){currentLetter = myArray_one[25];}
    else{currentLetter = currentLetter;}
rotate_position_one += 1;
}
int roter_3(){
        string myArray_one[26] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
        string myArray_one_decrypt[26] = {"z","y","x","w","v","u","t","s","r","q","p","o","n","m","l","k","j","i", "h","g","f","e","d","c","b","a"};
    // rotation to the right by x amount
    if (encrypt_Toggle == true){
        rotate(reverse_iterator<string*>(end(myArray_one)),
                reverse_iterator<string*>(end(myArray_one)) + rotate_position_one,
                reverse_iterator<string*>(myArray_one));
    }
    else if (encrypt_Toggle == false){
        rotate(reverse_iterator<string*>(end(myArray_one_decrypt)),
                reverse_iterator<string*>(end(myArray_one_decrypt)) + (rotate_position_one + 26),
                reverse_iterator<string*>(myArray_one_decrypt));
    }
    if(currentLetter == "a"){currentLetter = myArray_one[0];}
    else if(currentLetter == "b"){currentLetter = myArray_one[1];}
    else if(currentLetter == "c"){currentLetter = myArray_one[2];}
    else if(currentLetter == "d"){currentLetter = myArray_one[3];}
    else if(currentLetter == "e"){currentLetter = myArray_one[4];}
    else if(currentLetter == "f"){currentLetter = myArray_one[5];}
    else if(currentLetter == "g"){currentLetter = myArray_one[6];}
    else if(currentLetter == "h"){currentLetter = myArray_one[7];}
    else if(currentLetter == "i"){currentLetter = myArray_one[8];}
    else if(currentLetter == "j"){currentLetter = myArray_one[9];}
    else if(currentLetter == "k"){currentLetter = myArray_one[10];}
    else if(currentLetter == "l"){currentLetter = myArray_one[11];}
    else if(currentLetter == "m"){currentLetter = myArray_one[12];}
    else if(currentLetter == "n"){currentLetter = myArray_one[13];}
    else if(currentLetter == "o"){currentLetter = myArray_one[14];}
    else if(currentLetter == "p"){currentLetter = myArray_one[15];}
    else if(currentLetter == "q"){currentLetter = myArray_one[16];}
    else if(currentLetter == "r"){currentLetter = myArray_one[17];}
    else if(currentLetter == "s"){currentLetter = myArray_one[18];}
    else if(currentLetter == "t"){currentLetter = myArray_one[19];}
    else if(currentLetter == "u"){currentLetter = myArray_one[20];}
    else if(currentLetter == "v"){currentLetter = myArray_one[21];}
    else if(currentLetter == "w"){currentLetter = myArray_one[22];}
    else if(currentLetter == "x"){currentLetter = myArray_one[23];}
    else if(currentLetter == "y"){currentLetter = myArray_one[24];}
    else if(currentLetter == "z"){currentLetter = myArray_one[25];}
    else{currentLetter = currentLetter;}
rotate_position_one += 1;
}
int roter_4(){
        string myArray_one[26] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
        string myArray_one_decrypt[26] = {"z","y","x","w","v","u","t","s","r","q","p","o","n","m","l","k","j","i", "h","g","f","e","d","c","b","a"};
    // rotation to the right by x amount
    if (encrypt_Toggle == true){
        rotate(reverse_iterator<string*>(end(myArray_one)),
                reverse_iterator<string*>(end(myArray_one)) + rotate_position_one,
                reverse_iterator<string*>(myArray_one));
    }
    else if (encrypt_Toggle == false){
        rotate(reverse_iterator<string*>(end(myArray_one_decrypt)),
                reverse_iterator<string*>(end(myArray_one_decrypt)) + (rotate_position_one + 26),
                reverse_iterator<string*>(myArray_one_decrypt));
    }
    if(currentLetter == "a"){currentLetter = myArray_one[0];}
    else if(currentLetter == "b"){currentLetter = myArray_one[1];}
    else if(currentLetter == "c"){currentLetter = myArray_one[2];}
    else if(currentLetter == "d"){currentLetter = myArray_one[3];}
    else if(currentLetter == "e"){currentLetter = myArray_one[4];}
    else if(currentLetter == "f"){currentLetter = myArray_one[5];}
    else if(currentLetter == "g"){currentLetter = myArray_one[6];}
    else if(currentLetter == "h"){currentLetter = myArray_one[7];}
    else if(currentLetter == "i"){currentLetter = myArray_one[8];}
    else if(currentLetter == "j"){currentLetter = myArray_one[9];}
    else if(currentLetter == "k"){currentLetter = myArray_one[10];}
    else if(currentLetter == "l"){currentLetter = myArray_one[11];}
    else if(currentLetter == "m"){currentLetter = myArray_one[12];}
    else if(currentLetter == "n"){currentLetter = myArray_one[13];}
    else if(currentLetter == "o"){currentLetter = myArray_one[14];}
    else if(currentLetter == "p"){currentLetter = myArray_one[15];}
    else if(currentLetter == "q"){currentLetter = myArray_one[16];}
    else if(currentLetter == "r"){currentLetter = myArray_one[17];}
    else if(currentLetter == "s"){currentLetter = myArray_one[18];}
    else if(currentLetter == "t"){currentLetter = myArray_one[19];}
    else if(currentLetter == "u"){currentLetter = myArray_one[20];}
    else if(currentLetter == "v"){currentLetter = myArray_one[21];}
    else if(currentLetter == "w"){currentLetter = myArray_one[22];}
    else if(currentLetter == "x"){currentLetter = myArray_one[23];}
    else if(currentLetter == "y"){currentLetter = myArray_one[24];}
    else if(currentLetter == "z"){currentLetter = myArray_one[25];}
    else{currentLetter = currentLetter;}
rotate_position_one += 1;
}
int roter_5(){
        string myArray_one[26] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
        string myArray_one_decrypt[26] = {"z","y","x","w","v","u","t","s","r","q","p","o","n","m","l","k","j","i", "h","g","f","e","d","c","b","a"};
    // rotation to the right by x amount
    if (encrypt_Toggle == true){
        rotate(reverse_iterator<string*>(end(myArray_one)),
                reverse_iterator<string*>(end(myArray_one)) + rotate_position_one,
                reverse_iterator<string*>(myArray_one));
    }
    else if (encrypt_Toggle == false){
        rotate(reverse_iterator<string*>(end(myArray_one_decrypt)),
                reverse_iterator<string*>(end(myArray_one_decrypt)) + (rotate_position_one + 26),
                reverse_iterator<string*>(myArray_one_decrypt));
    }
    if(currentLetter == "a"){currentLetter = myArray_one[0];}
    else if(currentLetter == "b"){currentLetter = myArray_one[1];}
    else if(currentLetter == "c"){currentLetter = myArray_one[2];}
    else if(currentLetter == "d"){currentLetter = myArray_one[3];}
    else if(currentLetter == "e"){currentLetter = myArray_one[4];}
    else if(currentLetter == "f"){currentLetter = myArray_one[5];}
    else if(currentLetter == "g"){currentLetter = myArray_one[6];}
    else if(currentLetter == "h"){currentLetter = myArray_one[7];}
    else if(currentLetter == "i"){currentLetter = myArray_one[8];}
    else if(currentLetter == "j"){currentLetter = myArray_one[9];}
    else if(currentLetter == "k"){currentLetter = myArray_one[10];}
    else if(currentLetter == "l"){currentLetter = myArray_one[11];}
    else if(currentLetter == "m"){currentLetter = myArray_one[12];}
    else if(currentLetter == "n"){currentLetter = myArray_one[13];}
    else if(currentLetter == "o"){currentLetter = myArray_one[14];}
    else if(currentLetter == "p"){currentLetter = myArray_one[15];}
    else if(currentLetter == "q"){currentLetter = myArray_one[16];}
    else if(currentLetter == "r"){currentLetter = myArray_one[17];}
    else if(currentLetter == "s"){currentLetter = myArray_one[18];}
    else if(currentLetter == "t"){currentLetter = myArray_one[19];}
    else if(currentLetter == "u"){currentLetter = myArray_one[20];}
    else if(currentLetter == "v"){currentLetter = myArray_one[21];}
    else if(currentLetter == "w"){currentLetter = myArray_one[22];}
    else if(currentLetter == "x"){currentLetter = myArray_one[23];}
    else if(currentLetter == "y"){currentLetter = myArray_one[24];}
    else if(currentLetter == "z"){currentLetter = myArray_one[25];}
    else{currentLetter = currentLetter;}
rotate_position_one += 1;
}


    auto final_Roter_one = roter_1;
    auto final_Roter_two = roter_2;
    auto final_Roter_three = roter_3;
//Other functions
void encrypt_enigma(){
    //Defaults
    auto final_Roter_one = roter_1;
    auto final_Roter_two = roter_2;
    auto final_Roter_three = roter_3;
    //chosen roter one
    if(chosen_roter_one == 1){
        final_Roter_one = roter_1;

    }
    else if(chosen_roter_one == 2){
        final_Roter_one = roter_2;

    }
    else if(chosen_roter_one == 3){
        final_Roter_one = roter_3;

    }
    else if(chosen_roter_one == 4){
        final_Roter_one = roter_4;

    }
    else{
        final_Roter_one = roter_5;

    }
    //Chosen roter two
    if(chosen_roter_two == 1){
        final_Roter_two = roter_1;

    }
    else if(chosen_roter_two == 2){
        final_Roter_two = roter_2;

    }
    else if(chosen_roter_two == 3){
        final_Roter_two = roter_3;

    }
    else if(chosen_roter_two == 4){
        final_Roter_two = roter_4;

    }
    else{
        final_Roter_two = roter_5;

    }
    //chosen roter three
    if(chosen_roter_three == 1){
        final_Roter_three = roter_1;

    }
    else if(chosen_roter_three == 2){
        final_Roter_three = roter_2;

    }
    else if(chosen_roter_three == 3){
        final_Roter_three = roter_3;

    }
    else if(chosen_roter_three == 4){
        final_Roter_three = roter_4;

    }
    else{
        final_Roter_three = roter_5;

    }
    enc_Decry_f_string();
}

class EncryDecry
{

    public:
        void updateStrings(string sentence){
            currentLetter = sentence[0];

        int stringLength = sentence.length();
        string wordLetters[stringLength];
        int initializer = 0;

        do{
        wordLetters[initializer] = currentLetter;
        currentLetter = sentence[initializer];
        initializer++;
        //Do it
        final_Roter_one();
        final_Roter_two();
        final_Roter_three();
        encrypt_decrypt_output += currentLetter;

        }while(initializer != stringLength);

        }
};
//Change the string
int enc_Decry_f_string(){
    EncryDecry machine;
    encr_decry_length = choiceforencr.length();
    machine.updateStrings(choiceforencr);
    printf("No segmentation fault");
}
void r_option(){
    cout << "Sorry that is not a valid input please try again(e/d)" << endl;
    cin >> choiceforencr;
}

void chose_a_roter(int stateof){
        int problem = 0;
        string message;

        if (stateof == 0){message = "What roters(1, 2, 3, 4, 5) would you like to use (You may only use 3):\n";}
        else{message = "Sorry your one of your last choices was not valid please try again\nWhat roters(1, 2, 3, 4, 5) would you like to use (You may only use 3):\n";}
        cout << message;
        cin >> chosen_roter_one_s;
        cin >> chosen_roter_two_s;
        cin >> chosen_roter_three_s;
        cout << "please enter your roter position(1-26)" << endl;
        do{
        if (problem >= 1){
            cout << "Sorry one of your last entrys was not valid please try again\nPlease enter your roter position" << endl;
        }
        else{
        cin >> rotate_position_one;
        cin >> rotate_position_two;
        cin >> rotate_position_three;

        }
        while(rotate_position_one >= 27 || rotate_position_two >= 27 || rotate_position_three >= 27);

        if (stateof == 1)
            if(chosen_roter_one == chosen_roter_two || chosen_roter_two == chosen_roter_three || chosen_roter_three == chosen_roter_one || chosen_roter_one > 5 || chosen_roter_two > 5 || chosen_roter_three > 5){
                error = 1;
            }
            else{
                error = 0;
            }
        }while(error == 1);
}
void convert(){
//positions for roter one

    do{
        int gone_trough = 0;
        int reason = 0;
    //if there was a problem...
        if (error == 1 && gone_trough > 0){
            chose_a_roter(1);
        }

    //Chosen roter one
        if (chosen_roter_one_s == "1" || chosen_roter_one_s == "one"){chosen_roter_one = 1;}
        else if (chosen_roter_one_s == "2" || chosen_roter_one_s == "two"){chosen_roter_one = 2;}
        else if (chosen_roter_one_s == "3" || chosen_roter_one_s == "three"){chosen_roter_one = 3;}
        else if (chosen_roter_one_s == "4" || chosen_roter_one_s == "four"){chosen_roter_one = 4;}
        else if (chosen_roter_one_s == "5" || chosen_roter_one_s == "five"){chosen_roter_one = 5;}
        else{
            error = 1;
        }
    //chosen Roter two
        if (chosen_roter_two_s == "1" || chosen_roter_two_s == "one"){chosen_roter_two = 1;}
        else if (chosen_roter_two_s == "2" || chosen_roter_two_s == "two"){chosen_roter_two = 2;}
        else if (chosen_roter_two_s == "3" || chosen_roter_two_s == "three"){chosen_roter_two = 3;}
        else if (chosen_roter_two_s == "4" || chosen_roter_two_s == "four"){chosen_roter_two = 4;}
        else if (chosen_roter_two_s == "5" || chosen_roter_two_s == "five"){chosen_roter_two = 5;}
        else{
            error = 1;
        }
    //Chosen Roter three
        if (chosen_roter_three_s == "1" || chosen_roter_three_s == "one"){chosen_roter_three = 1;}
        else if (chosen_roter_three_s == "2" || chosen_roter_three_s == "two"){chosen_roter_three = 2;}
        else if (chosen_roter_three_s == "3" || chosen_roter_three_s == "three"){chosen_roter_three = 3;}
        else if (chosen_roter_three_s == "4" || chosen_roter_three_s == "four"){chosen_roter_three = 4;}
        else if (chosen_roter_three_s == "5" || chosen_roter_three_s == "five"){chosen_roter_three = 5;}
        else{
            error = 1;
        }
        gone_trough++;
    }while(error == 1 || chosen_roter_one == chosen_roter_two || chosen_roter_two == chosen_roter_three || chosen_roter_three == chosen_roter_one);

}
