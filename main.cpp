#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>
#include <iomanip>
#include <unistd.h>
#include <limits>
#include "login.h"
#include "ranking.h"
#include "blackjack.h"
#include "slot_machine.h"
#include "roulette.h"
#include "soccer.h"
#include "print_text.h"
#include "earn.h"

using namespace std;

int take_money(string username){
    ifstream input("Money.txt");

    string line,money,name;
    int count = 0;
    while (getline(input, line)){
        for (int i = 0; i < line.length(); i++){
            if (line[i] == ','){
                name = line.substr(0,i);
                money = line.substr(i+1);
            }
            if (name == username){
                break;
            }
        }
    }

    input.close();

    int money_int = 0, temp;

    for (int j = 0; j < money.length(); j++){
        if (money[j] == '0'){
            temp = 0;
        }
        else if (money[j] == '1'){
            temp = 1;
        }
        else if (money[j] == '2'){
            temp = 2;
        }
        else if (money[j] == '3'){
            temp = 3;
        }
        else if (money[j] == '4'){
            temp = 4;
        }
        else if (money[j] == '5'){
            temp = 5;
        }
        else if (money[j] == '6'){
            temp = 6;
        }
        else if (money[j] == '7'){
            temp = 7;
        }
        else if (money[j] == '8'){
            temp = 8;
        }
        else if (money[j] == '9'){
            temp = 9;
        }
        
        money_int += temp * pow(10,(money.length()-j-1));
        
    }

    return money_int;

}

void change_money(int balance, string username){

    string line,name;

    ifstream input("Money.txt");

    ofstream output("New_Money.txt");

    while (getline(input,line)){
        for (int i = 0; i < line.length(); i++){
            if (line[i] == ','){
                name = line.substr(0,i);
                break;
            }
        }
        if (username != name){
            output << line << endl;
        }
    }

    input.close();
    output << username << ',' << balance << endl;
    output.close();

    remove("Money.txt");
    rename("New_Money.txt","Money.txt");
}

int main(){
    
    int balance;
    string username;

    system("clear");
    username = login_system();

    if (username == "q"){
        return 0;
    }

    balance = take_money(username);
    
    string gametype;
    
    cout << " " << endl;
    system("clear");
    ifstream output1("Welcome.txt");
    if (!output1){
        exit(1);
    }
    string line;
    while (getline(output1,line)){
        print(line,2000);
    }
    output1.close();

    cout << " " << endl;
    print_text_with_endl("Welcome to Grand Casino!!!");
    cout << " " << endl;
    print_text_with_endl("1.blackjack");
    print_text_with_endl("2.roulette");
    print_text_with_endl("3.slot_machine");
    print_text_with_endl("4.soccer");
    print_text_with_endl("5.Money You have");
    print_text_with_endl("q.quit");
    cout << " " << endl;
    print_text_without_endl("Please choose what you want to play (1,2,3,4,5,q): ");
    
    cin >> gametype;

    while (gametype != "q"){
        if (gametype == "1"){
            balance = earning(balance,username);
            change_money(balance,username);
            print_text_without_endl("Remain Blance: ");
            cout << balance << endl;
            cout << " " << endl;
            
            cout << setw(60) << "loading to blackjack..." << endl;
            usleep(800000);
            cout << setw(60) << "3.........." << endl;
            usleep(800000);
            cout << setw(60) << "2.........." << endl;
            usleep(800000);
            cout << setw(60) << "1.........." << endl;
            usleep(800000);
            cout << setw(60) << "loading.........." << endl;
            usleep(800000);
            cout << setw(60) << "loaded!!!!!!!!!!" << endl;
            usleep(800000);

            system("clear");
            balance = blackjackgame(balance,username);
            change_money(balance,username);
            system("clear");
        }
        else if (gametype == "2"){
            balance = earning(balance,username);
            change_money(balance,username);
            print_text_without_endl("Remain Blance: ");
            cout << balance << endl;
            cout << " " << endl;

            cout << setw(60) << "loading to roulette..." << endl;
            usleep(800000);
            cout << setw(60) << "3.........." << endl;
            usleep(800000);
            cout << setw(60) << "2.........." << endl;
            usleep(800000);
            cout << setw(60) << "1.........." << endl;
            usleep(800000);
            cout << setw(60) << "loading.........." << endl;
            usleep(800000);
            cout << setw(60) << "loaded!!!!!!!!!!" << endl;
            usleep(800000);

            system("clear");
            balance = roulettegame(balance,username);
            change_money(balance,username);
            system("clear");
        }
        else if (gametype == "3"){
            balance = earning(balance,username);
            change_money(balance,username);
            print_text_without_endl("Remain Blance: ");\
            cout << balance << endl;
            cout << " " << endl;

            cout << setw(60) << "loading to slot_machine..." << endl;
            usleep(800000);
            cout << setw(60) << "3.........." << endl;
            usleep(800000);
            cout << setw(60) << "2.........." << endl;
            usleep(800000);
            cout << setw(60) << "1.........." << endl;
            usleep(800000);
            cout << setw(60) << "loading.........." << endl;
            usleep(800000);
            cout << setw(60) << "loaded!!!!!!!!!!" << endl;
            usleep(800000);

            system("clear");
            balance = SlotMachine(balance, username);
            change_money(balance,username);
            system("clear");
        }
        else if (gametype == "4"){
            balance = earning(balance,username);
            change_money(balance,username);
            print_text_without_endl("Remain Blance: ");
            cout << balance << endl;
            cout << " " << endl;

            cout << setw(60) << "loading to soccer..." << endl;
            usleep(800000);
            cout << setw(60) << "3.........." << endl;
            usleep(800000);
            cout << setw(60) << "2.........." << endl;
            usleep(800000);
            cout << setw(60) << "1.........." << endl;
            usleep(800000);
            cout << setw(60) << "loading.........." << endl;
            usleep(800000);
            cout << setw(60) << "loaded!!!!!!!!!!" << endl;
            usleep(800000);

            system("clear");
            balance = shotball(balance,username);
            change_money(balance,username);
            system("clear");
        }
        else if (gametype == "5"){
            print_text_with_endl("You have $"+to_string(balance));
            cout << endl;
        }
        else{
            print_text_with_endl("wrong input,please enter again");
        }

        print_text_with_endl("1.blackjack");
        print_text_with_endl("2.roulette");
        print_text_with_endl("3.slot_machine");
        print_text_with_endl("4.soccer");
        print_text_with_endl("5.Money You have");
        print_text_with_endl("q.quit");
        cout << " " << endl;
        print_text_without_endl("Please choose what you want to play (1,2,3,4,5,q): ");
        
        cin >> gametype;

    }

    ranking_system();

    ifstream output2("Goodbye.txt");
    if (!output2){
        exit(1);
    }
    // string line;
    while (getline(output2,line)){
        print(line,2000);
    }

    output2.close();    
}

