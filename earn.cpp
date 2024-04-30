#include <iostream>
#include <string>
#include <iomanip>
#include <unistd.h>
#include "print_text.h"

using namespace std;

string words(int number,int separate){
    int n1,n2,choose;
    string final;
    srand(time(NULL));
    for (int i = 0; i < number; i++){
        n1 = rand() % (70 - 65 + 1) + 65;
        n2 = rand() % (122 - 97 + 1) + 97;
        choose = rand() % 2 + 1;
        if (choose == 1){
            final += char(n1);
        }
        else if (choose == 2){
            final += char(n2);
        }
        if (i % separate == 0){
            final += ' ';
        }
    }
    print_text_with_endl(final);
    return final;
}

int display(){
    print_text_with_endl("The mini game here is a word typing game, you have to enter all the words shown");
    print_text_with_endl("There is total of 3 levels. You can earn 10 in level 1, 100 in level 2, 1000 in level 3");
    print_text_with_endl("Dont use copy and paste!!!");
    int earned = 0;
    bool check;
    print_text_without_endl("Please enter your choice (1,2,3): ");
    string difficulty, texts, user_in, input;
    getline(cin,difficulty);

    while (difficulty != "1" && difficulty != "2" && difficulty != "3"){
        getline(cin,difficulty);
        if (difficulty == "1" || difficulty == "2" || difficulty == "3"){
            break;
        }
        print_text_with_endl("wrong input, please enter again");
        print_text_without_endl("Please enter your choice (1,2,3): ");
    }
    system("clear");
    usleep(800000);
    cout << setw(60) << "Ready?" << endl;
    usleep(800000);
    cout << setw(60) << "3.........." << endl;
    usleep(800000);
    cout << setw(60) << "2.........." << endl;
    usleep(800000);
    cout << setw(60) << "1.........." << endl;
    usleep(800000);
    cout << setw(60) << "Start!!!!!!!!!!" << endl;
    usleep(800000);
    
    if (difficulty == "1"){
        texts = words(20,3);
        for (int q = 0; q < 8; q++){
            cin >> input;
            if (q == 7){
                user_in += input;
            }
            else{
                user_in += input;
                user_in += " ";
            }
        }
        if (texts == user_in){
            earned = 10;
            print_text_without_endl("You have earned ");
            cout << earned << " !!!!!!!!" << endl;
        }
        else{
            print_text_without_endl("You have typed wrong, please try again");
            cout << endl;
            return display();
        }
    }
    else if (difficulty == "2"){
        texts = words(50,5);
        for (int w = 0; w < 11; w++){
            cin >> input;
            if (w == 10){
                user_in += input;
            }
            else{
                user_in += input;
                user_in += " ";
            }
        }
        if (texts == user_in){
            earned = 100;
            print_text_without_endl("You have earned ");
            cout << earned << " !!!!!!!!" << endl;
        }
        else{
            print_text_without_endl("You have typed wrong, please try again");
            cout << endl;
            return display();
        }
    }
    else if (difficulty == "3"){
        texts = words(70,6);
        for (int e = 0; e < 13; e++){
            cin >> input;
            if (e == 12){
                user_in += input;
            }
            else{
                user_in += input;
                user_in += " ";
            }
        }
        if (texts == user_in){
            earned = 1000;
            print_text_without_endl("You have earned ");
            cout << earned << " !!!!!!!!" << endl;
        }
        else{
            print_text_without_endl("You have typed wrong, please try again");
            cout << endl;
            return display();
        }
    }
    return earned;
}

int mini_game(){
    int earned = display();
    return earned;
}

int earning(int balance, string username){
    string command;
    if (balance < 100){
        if (balance > 0){
            print_text_with_endl("Your balance is under 100, you can attempt a mini game to earn at most 1000 dollars!!!");
            print_text_with_endl("1. Attempt");
            print_text_with_endl("2. Don't attempt");
            print_text_without_endl("Your choice (1,2): ");
            cin >> command;
            while (command != "1" && command != "2"){
                print_text_with_endl("wrong input, please enter again");
                print_text_without_endl("Your choice (1,2): ");
                cin >> command;
            }
            if (command == "2")
            {
                return balance;
            }
        }
        else if (balance <= 0){
            print_text_with_endl("You have bankrupted, a mini game is provided for you to earn money back.");
        }
    }
    else{
        return balance;
    }
    
    balance += mini_game();
    return balance;
}


// int main(){
//     cout << earning(50, "ggggg") << endl;
//     return 0;
// }
