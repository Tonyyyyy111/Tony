#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio> 
#include <stdio.h> 
#include <limits>
#include "print_text.h"
using namespace std;

//change card to english letter
char showhand1(int value){
    if (value==1)
        return 'A';
    else if (value==10)
        return 'T';
    else if (value==11)
        return 'J';
    else if (value==12)
        return 'Q';
    else if (value==13)
        return 'K';
    else
        return value + '0';
}


//main function of soccer
int shotball(int balance,string username){
    int netvalue=0, frame1 , frame2 , playercard, bet, gamelose;
    string choice;
    char shootchoice;
    bool stopflag=false;
    char nothing;
    srand(time(0));
    system("clear");

    while (stopflag==false){

        gamelose=0;
        cout<< "Your balance: $"<< balance+netvalue<<endl<<endl;
        cout<< "New Game (press N)" << endl;
        cout<< "Quit (press Q)"<<endl<<endl;
        cout<< "Enter your choice: ";
        getline(cin, choice);
        system("clear");  

        if (choice=="N"||choice=="n"){
            cout<< "Hello "<<username<<"! Welcome to"<<endl<<endl;
            cout<< "███████╗ ██████╗  ██████╗ ██████╗███████╗██████╗"<<endl;
            cout<< "██╔════╝██╔═══██╗██╔════╝██╔════╝██╔════╝██╔══██╗"<<endl;
            cout<< "███████╗██║   ██║██║     ██║     █████╗  ██████╔"<<endl;
            cout<< "╚════██║██║   ██║██║     ██║     ██╔══╝  ██╔══██"<<endl;
            cout<< "███████║╚██████╔╝╚██████╗╚██████╗███████╗██║  ██"<<endl;
            cout<< "╚══════╝ ╚═════╝  ╚═════╝ ╚═════╝╚══════╝╚═╝  ╚═╝"<<endl<<endl;
            cout << "Your balance: $" << balance+netvalue <<endl;
            cout << "Maximum of your bet: $" << (balance+netvalue)/3 << endl;
            cout << "Reminder: You can not bet more than one third of your balance!"<< endl;
            cout << "amount to bet: ";
            while (!(cin >> bet) || cin.peek() != '\n'|| bet != static_cast<int>(bet)){
                cout << "Invalid input." << endl;
                cout << "amount to bet: ";
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            while (bet > (balance+netvalue)/3){
                cout<<"Invalid bet. Balance is not enough!"<<endl;
                cout << "amount to bet: ";
                cin >> bet;
            }
            while (bet<=0){
                cout<<"Please enter a postive amount."<<endl;
                cout << "amount to bet: ";
                cin >> bet;
            }
            system("clear");
            
            //random card
            frame1 = rand()%13+1;
            frame2 = rand()%13+1;
            playercard = rand()%13+1;


            //print frame
            //need compare frame1 or frame2 is bigger because the smaller should be printed first
            cout << "The frame:" << endl;
            if (frame2 > frame1){
                cout << "                 " << showhand1(frame1) << "           " << showhand1(frame2) << endl;
                cout << "Press Enter to get your card!!!" << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                system("clear");
            }
            else if (frame1 > frame2){
                cout << "                 " << showhand1(frame2) << "           " << showhand1(frame1) << endl;
                cout << "Press Enter to get your card!!!" << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                system("clear");
            }
            else if (frame1 == frame2){
                cout << "                 " << showhand1(frame2) << "           " << showhand1(frame1) << endl;
                cout << "choose your card whether bigger or smaller than the frame(B or S)";
                cin >> shootchoice;
            }
            

            //to show player lose or win
            cout << "The frame:" << endl;
            if (frame2 > frame1){
                cout << "                 " << showhand1(frame1) << "           " << showhand1(frame2) << endl;
                cout << "Your card is           " << showhand1(playercard) << endl;
                if (playercard < frame1 || playercard > frame2){
                    netvalue -= bet;
                    gamelose -= bet;
                    cout << "You lose $" << -gamelose << endl;
                }
                else if (playercard > frame1 && playercard < frame2){
                    netvalue += bet;
                    gamelose += bet;
                    cout << "You win $" << gamelose << endl;
                }
                else if (playercard == frame1 || playercard == frame2){
                    netvalue -= bet*2;
                    gamelose -= bet*2;
                    cout << "You lose $" << -gamelose << endl;
                }
            }
            else if (frame1 > frame2){
                cout << "                 " << showhand1(frame2) << "           " << showhand1(frame1) << endl;
                cout << "Your card is           " << showhand1(playercard) << endl;
                if (playercard < frame2 || playercard > frame1){
                    netvalue -= bet;
                    gamelose -= bet;
                    cout << "You lose $" << -gamelose << endl;
                }
                else if (playercard > frame2 && playercard < frame1){
                    netvalue += bet;
                    gamelose += bet;
                    cout << "You win $" << gamelose << endl;
                }
                else if (playercard == frame1 || playercard == frame2){
                    netvalue -= bet*2;
                    gamelose -= bet*2;
                    cout << "You lose $" << -gamelose << endl;
                }
            }
            else if (frame1 == frame2){
                cout << "                 " << showhand1(frame2) << "           " << showhand1(frame1) << endl;
                cout << "Your card is           " << showhand1(playercard) << endl;
                if (playercard < frame2 && (shootchoice == 'B' || shootchoice == 'b')){
                    netvalue -= bet;
                    gamelose -= bet;
                    cout << "You lose $" << -gamelose << endl;
                }
                else if (playercard > frame2 && (shootchoice == 'B' || shootchoice == 'b')){
                    netvalue += 2*bet;
                    gamelose += 2*bet;
                    cout << "You win $" << gamelose << endl;
                }
                else if (playercard < frame2 && (shootchoice == 'S' || shootchoice == 's')){
                    netvalue += 2*bet;
                    gamelose += 2*bet;
                    cout << "You win $" << gamelose << endl;
                }
                else if (playercard > frame2 && (shootchoice == 'S' || shootchoice == 's')){
                    netvalue -= bet;
                    gamelose -= bet;
                    cout << "You lose $" << -gamelose << endl;
                }
                else if (playercard == frame1){
                    netvalue -= bet*3;
                    gamelose -= bet*3;
                    cout << "You lose $" << -gamelose << endl;
                }
            }
        }
        else if (choice=="Q"||choice=="q"){
            balance += netvalue;
            cout<<"Your balance: $"<< balance << endl;
            cout<<"Thank you for playing Soccer."<<endl;
            cout<<"Press \"Enter\" to Quit."<<endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("clear");
            stopflag=true;

        }

    }

    return balance;

} 

//int main(){
    //shotball(300, "tony");
//}
