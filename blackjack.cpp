#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <limits>
#include <sstream>
#include "print_text.h"
using namespace std;

bool dragon(int hand[]){
    int count=0;
    for(int i =0;i<10;i++){
        if (hand[i]!=0){
            count+=1;
        }
    }
    if (count>=5)
        return true;
    else
        return false;
}
char showhand(int value){
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

void showallhand(int hand[]){
    cout<<endl<<" ";
    for(int i =0; i<10;i++){
        if (hand[i]!=0){
            cout<<"_   ";
        }
    }
    cout<<endl;
    for(int i =0; i<10;i++){
        if (hand[i]!=0){
            cout<<"|"<<showhand(hand[i])<<"| ";
        }
    }
    cout<< endl<<" ";
    for(int i =0; i<10;i++){
        if (hand[i]!=0){
            cout<<"-   ";
        }
    }
}
int total_number(int hand[]){
    int count=0,newcount=100;
    for (int i=0;i<10;i++){
        if (hand[i]==1)
            count+=11;
        else if (hand[i]>10)
            count+=10;
        else if (hand[i]<=10)
            count+=hand[i];
    }
    if (count>21){
        newcount=0;
        for (int i=0;i<10;i++){
            if (hand[i]>10)
                newcount+=10;
            else if (hand[i]<=10)
                newcount+=hand[i];
        }
    }
    if (newcount<count){
        count=newcount;
    }
    return count;
}

int blackjackgame(int balance,string username){
    int netvalue=0,count,bet,dealercount;
    char choice,move;
    string betanswer;
    srand(time(0));
    bool stopflag=false, finish_round, blackjackflag,bankruptflag=false,betflag;
    system("clear");
    cout<< "Hello "<<username<<"! Welcome to"<<endl<<endl;
    cout<< "██████╗ ██╗      █████╗  ██████╗██╗  ██╗     ██╗ █████╗  ██████╗██╗  ██╗"<<endl;
    cout<< "██╔══██╗██║     ██╔══██╗██╔════╝██║ ██╔╝     ██║██╔══██╗██╔════╝██║ ██╔╝"<<endl;
    cout<< "██████╔╝██║     ███████║██║     █████╔╝      ██║███████║██║     █████╔╝ "<<endl;
    cout<< "██╔══██╗██║     ██╔══██║██║     ██╔═██╗ ██   ██║██╔══██║██║     ██╔═██╗ "<<endl;
    cout<< "██████╔╝███████╗██║  ██║╚██████╗██║  ██╗╚█████╔╝██║  ██║╚██████╗██║  ██╗"<<endl;
    cout<< "╚═════╝ ╚══════╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝ ╚════╝ ╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝"<<endl;
    while (stopflag==false){
        cout<< "Your balance: $"<< balance+netvalue<<endl<<endl;
        cout<< "New Game (press N)" << endl;
        cout<< "Quit (press Q)"<<endl<<endl;
        cout<< "Enter your choice: ";
        cin >> choice;
        cout<< "****************************************"<<endl;
        if (choice=='N'||choice=='n'){
            int* dealerhand=new int[10];
            int* playerhand=new int[10];
            for (int i=0;i<10;i++){
                dealerhand[i]=0;
                playerhand[i]=0;
            }
            cout<< "amount to bet: $";
            betflag=false;
            cin>>betanswer;
            for (int i=0;i<betanswer.size();i++)
                if (betanswer[i]<48||betanswer[i]>57){
                    cout<<"Invalid bet."<<endl;
                    cout<<"Press Enter to return to menu.";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();
                    betflag=true;
                    system("clear");
                    break;
                }
            if (betflag){
                delete[] dealerhand;
                delete[] playerhand;
                continue;
            }
            stringstream ss;
            ss << betanswer;
            ss >> bet;
            if (bet>(balance+netvalue)){
                cout<<"Invalid bet. Balance is not enough!"<<endl;
                cout<<"Press Enter to return to menu.";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                delete[] dealerhand;
                delete[] playerhand;
                system("clear");
                continue;
            }
            system("clear");
            dealerhand[0]=rand()%13+1;
            playerhand[0]=rand()%13+1;
            playerhand[1]=rand()%13+1;
            finish_round=false;
            blackjackflag=false;
            if (total_number(playerhand)==21){
                blackjackflag=true;
            }
            count=2;
            while (finish_round==false && blackjackflag==false){
                if (dragon(playerhand)==true)
                    break;
                cout<< "Bet: $" <<bet<<endl<<endl;
                cout<< "Dealer's hand: ";
                showallhand(dealerhand);
                cout<< endl;
                cout<< "Player's hand: "<< "(total point: "<<total_number(playerhand)<<")";
                showallhand(playerhand);
                cout<<endl;
                cout<< "Moves:"<<endl;
                cout<< "1. Hit (Press H)"<<endl;
                cout<< "2. Stand (Press S)"<<endl;
                cout<< "3. Double (Press D)"<<endl;
                cout<< "Your move: ";
                cin >> move;
                if (move=='H'||move=='h'){
                    playerhand[count]=rand()%13+1;
                    count+=1;
                    if (total_number(playerhand)>=21){
                        finish_round=true;
                    }
                }
                else if (move=='S'||move=='s'){
                    finish_round=true;
                }
                else if (move=='D'||move=='d'){
                    if (bet*2>balance+netvalue){
                        cout<<"Balance is not enough!"<<endl;
                        continue;
                    }
                    bet = bet *2;
                    playerhand[count]=rand()%13+1;
                    count+=1;
                    finish_round=true;
                }
                else{
                    cout<<"Invalid input. Please try again!"<<endl;
                     cout<<"Press \"Enter\" to continue.";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();
                }
                system("clear");
            }
            dealercount = 1;
            while (total_number(dealerhand)<17){
                dealerhand[dealercount]=rand()%13+1;
                dealercount+=1;
            }
            system("clear");
            cout<< "Dealer's hand: ";
            cout<< "(Total: "<<total_number(dealerhand)<<")";
            showallhand(dealerhand);
            cout<<endl<< "Player's hand: ";
            cout<< "(Total: "<<total_number(playerhand)<<")";
            showallhand(playerhand);
            cout<<endl;
            if (blackjackflag==true){
                cout<<"You get Blackjack! You win $"<<bet*2;
                netvalue+=bet*2;
            }
            else if (dragon(playerhand)==true && total_number(playerhand)<=21){
                cout<<"You get more than 5 cards! You win $"<<bet*3;
                netvalue+=bet*3;
            }
            else if (total_number(playerhand)>21){
                cout<<"You busted!! You lose $"<<bet;
                netvalue-=bet;
            }
            else if (total_number(dealerhand)==21){
                cout<<"Dealer gets 21!! You lose $"<<bet;
                netvalue-=bet;
            }
            else if (total_number(playerhand)==21){
                cout<<"You get 21!! You win $"<<bet*2;
                netvalue+=bet*2;
            }
            else if (total_number(dealerhand)>21){
                cout<<"Dealer busted!! You win $"<<bet;
                netvalue+=bet;
            }
            else if (total_number(playerhand)<=total_number(dealerhand)){
                cout<<"Dealer's hand is bigger than or equal to yours!! You lose $"<<bet;
                netvalue-=bet;
            }   
            else if (total_number(playerhand)>total_number(dealerhand)){
                cout<<"Your hand is bigger than Dealer's!! You win $"<<bet;
                netvalue+=bet;
            }
            cout<<"!"<<endl;
            if(balance+netvalue<=0)
                bankruptflag=true;
            if (bankruptflag==true){
                cout<<endl;
                cout<<"Your balance is $0."<<endl;
                cout<<"Press \"Enter\" to go back to the lobby.";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                balance=0;
                system("clear");
                delete[] dealerhand;
                delete[] playerhand;
                return balance;
            }
            cout<<"Your balance: $"<<balance+netvalue<<endl<<endl;
            cout<<"Press \"Enter\" to continue."<<endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            delete[] dealerhand;
            delete[] playerhand;
            system("clear");
        }   
        else if (choice=='Q'||choice=='q'){
            balance += netvalue;
            cout<<"Thank you for playing Blackjack."<<endl;
            cout<<"Press \"Enter\" to continue."<<endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            system("clear");
            stopflag=true;
        }
        else{
            cout<<"Wrong input. Please try again!"<<endl;
            cout<<"Press \"Enter\" to continue.";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            system("clear");
        }
    }
    return balance;
}

// int main(){
//     int net;
//     net=blackjackgame(100,"Andy");
//     return 0;
// }
