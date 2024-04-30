#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <unistd.h>
#include <sstream>
#include "print_text.h"
using namespace std;

void betdisplay(int lst[]){
    cout<<"Your bet:"<<endl;
    for (int i=1;i<47;i++){
        if (lst[i]>0){
            if (i<=36){
                cout<<"Single Number "<<i<<": $"<<lst[i]<<endl;
            }
            else if (i==37){
                cout<<"Row 1: $"<<lst[i]<<endl;
            }
            else if (i==38){
                cout<<"Row 2: $"<<lst[i]<<endl;
            }
            else if (i==39){
                cout<<"Row 3: $"<<lst[i]<<endl;
            }
            else if (i==40){
                cout<<"1st 12: $"<<lst[i]<<endl;
            }
            else if (i==41){
                cout<<"2nd 12: $"<<lst[i]<<endl;
            }
            else if (i==42){
                cout<<"3rd 12: $"<<lst[i]<<endl;
            }
            else if (i==43){
                cout<<"Even: $"<<lst[i]<<endl;
            }
            else if (i==44){
                cout<<"Odd: $"<<lst[i]<<endl;
            }
            else if (i==45){
                cout<<"Red: $"<<lst[i]<<endl;
            }
            else if (i==46){
                cout<<"Black: $"<<lst[i]<<endl;
            }
        }
    }
}

bool checkbet(int lst[],int betoption){
    if (betoption>=47|| betoption<1){
        cout<<"Invalid option. Press Enter to return to betting menu."<<endl;
        cin.ignore(10,'\n');
        cin.get();
        return false;
    }
    else if (lst[betoption]>0){
        cout<<"You have placed a bet already. Press Enter to return to betting menu."<<endl;
        cin.ignore(10,'\n');
        cin.get();
        return false;
    }
    else
        return true;
}

int result(int lst[],int ball){
    int win = 0;
    win+=lst[ball]*36;      //SingleBet 1:35
    if (ball%3==0){         //RowBet 1:2
        win+=lst[37]*3;
    }
    else if (ball%3==2){
        win+=lst[38]*3;
    }
    else if (ball%3==1){
        win+=lst[39]*3;
    }
    if (ball>=1 && ball<=12){   //DozenBet 1:2
        win+=lst[40]*3;
    }
    else if (ball>=13 && ball<=24){
        win+=lst[41]*3;
    }
    else if (ball>=25 && ball<=36){
        win+=lst[42]*3;
    }
    if (ball%2==0){             //1:1
        win+=lst[43]*2;
    }
    else if (ball%2==1){
        win+=lst[44]*2;
    }
    if (ball==1||ball==3||ball==5||ball==7||ball==9||ball==12||ball==14||ball==16||ball==18||ball==19||ball==21||ball==23||ball==25||ball==27||ball==30||ball==32||ball==34||ball==36){
        win+=lst[45]*2;
    }
    else if ((ball==2||ball==4||ball==6||ball==8||ball==10||ball==11||ball==13||ball==15||ball==17||ball==20||ball==22||ball==24||ball==26||ball==28||ball==29||ball==31||ball==33||ball==35)){
        win+=lst[46]*2;
    }
    return win;
}

int roulettegame(int balance,string username){
    bool stopflag=false,betflag,optionflag,betbetflag;
    char choice,finishbet;
    int betoption,bet,ball,win,totalbet;
    string optionanswer,betanswer;
    srand(time(0));
    system("clear");
    cout<<"Hello "<<username<<"! Welcome to"<<endl<<endl;
    cout<<"██████╗  ██████╗ ██╗   ██╗██╗     ███████╗████████╗████████╗███████╗"<<endl;
    cout<<"██╔══██╗██╔═══██╗██║   ██║██║     ██╔════╝╚══██╔══╝╚══██╔══╝██╔════╝"<<endl;
    cout<<"██████╔╝██║   ██║██║   ██║██║     █████╗     ██║      ██║   █████╗  "<<endl;
    cout<<"██╔══██╗██║   ██║██║   ██║██║     ██╔══╝     ██║      ██║   ██╔══╝  "<<endl;
    cout<<"██║  ██║╚██████╔╝╚██████╔╝███████╗███████╗   ██║      ██║   ███████╗"<<endl;
    cout<<"╚═╝  ╚═╝ ╚═════╝  ╚═════╝ ╚══════╝╚══════╝   ╚═╝      ╚═╝   ╚══════╝"<<endl<<endl;
    while (stopflag==false){
        cout<< "Your balance: $"<< balance <<endl<<endl;
        cout<< "New Game (press N)" << endl;
        cout<< "Quit (press Q)"<<endl<<endl;
        cout<< "Enter your choice: ";
        cin >> choice;
        if (choice=='N'||choice=='n'){ 
            betflag=false;
            int *betlist =new int[47];
            for (int i=0;i<47;i++)
                betlist[i]=0;
            totalbet=0;
            while (betflag==false){
                system("clear");
                cout<< "Your balance: $"<< balance<<endl;
                cout<< "  \033[30;47m ---------------------------------------------------------------- \033[0m"<<endl;
                cout<< "  \033[30;47m|\033[37;41m 3 \033[30;47m|\033[37;40m 6 \033[30;47m|\033[37;41m 9 \033[30;47m|\033[37;41m 12 \033[30;47m|\033[37;40m 15 \033[30;47m|\033[37;41m 18 \033[30;47m|\033[37;41m 21 \033[30;47m|\033[37;40m 24 \033[30;47m|\033[37;41m 27 \033[30;47m|\033[37;41m 30 \033[30;47m|\033[37;40m 33 \033[30;47m|\033[37;41m 36 \033[30;47m|\033[30;42m row 1 \033[30;47m|\033[0m"<<endl;
                cout<< "  \033[30;47m ---------------------------------------------------------------- \033[0m"<<endl;
                cout<< "  \033[30;47m|\033[37;40m 2 \033[30;47m|\033[37;41m 5 \033[30;47m|\033[37;40m 8 \033[30;47m|\033[37;40m 11 \033[30;47m|\033[37;41m 14 \033[30;47m|\033[37;40m 17 \033[30;47m|\033[37;40m 20 \033[30;47m|\033[37;41m 23 \033[30;47m|\033[37;40m 26 \033[30;47m|\033[37;40m 29 \033[30;47m|\033[37;41m 32 \033[30;47m|\033[37;40m 35 \033[30;47m|\033[30;42m row 2 \033[30;47m|\033[0m"<<endl;
                cout<< "  \033[30;47m ---------------------------------------------------------------- \033[0m"<<endl;
                cout<< "  \033[30;47m|\033[37;41m 1 \033[30;47m|\033[37;40m 4 \033[30;47m|\033[37;41m 7 \033[30;47m|\033[37;40m 10 \033[30;47m|\033[37;40m 13 \033[30;47m|\033[37;41m 16 \033[30;47m|\033[37;41m 19 \033[30;47m|\033[37;40m 22 \033[30;47m|\033[37;41m 25 \033[30;47m|\033[37;40m 28 \033[30;47m|\033[37;40m 31 \033[30;47m|\033[37;41m 34 \033[30;47m|\033[30;42m row 3 \033[30;47m|\033[0m"<<endl;
                cout<< "  \033[30;47m ---------------------------------------------------------------- \033[0m"<<endl;
                cout<< "  \033[30;47m|\033[30;42m     1st 12     \033[30;47m|\033[30;42m      2nd 12       \033[30;47m|\033[30;42m       3rd 12      \033[30;47m|\033[0m" <<endl;
                cout<< "  \033[30;47m -------------------------------------------------------- \033[0m"  <<endl<<endl;
                betdisplay(betlist);
                cout<<endl;
                cout<< "Options for betting: (Enter 0 for no more betting.)"<<endl;
                cout<< "| Single Number (Enter the number you want to bet)           |"<<endl ;
                cout<< "| Row 1  (Enter 37)  | Row 2  (Enter 38) | Row 3  (Enter 39) |"<<endl;
                cout<< "| 1st 12 (Enter 40)  | 2nd 12 (Enter 41) | 3rd 12 (Enter 42) |"<<endl;
                cout<< "| Even   (Enter 43)  | Odd    (Enter 44) |"<<endl;
                cout<< "| Red    (Enter 45)  | Black  (Enter 46) |"<<endl<<endl;
                cout<< "Your option: ";
                optionflag=false;
                cin>>optionanswer;
                for (int i=0;i<optionanswer.size();i++)
                    if (optionanswer[i]<48||optionanswer[i]>57){
                        cout<<"Invalid option."<<" Press Enter to return to betting menu.";
                        cin.ignore(10, '\n');
                        cin.get();
                        optionflag=true;
                        system("clear");
                        break;
                    }
                if (optionflag){
                    continue;
                }
                stringstream ss;
                ss << optionanswer;
                ss >> betoption;
                if (betoption==0){
                    betflag=true;
                    system("clear");
                    break;
                }
                if (checkbet(betlist,betoption)==false){
                    continue;
                }
                cout<< "Amount to Bet: $";
                betbetflag=false;
                cin>>betanswer;
                for (int i=0;i<betanswer.size();i++)
                    if (betanswer[i]<48||betanswer[i]>57){
                        cout<<"Invalid option."<<" Press Enter to return to betting menu.";
                        cin.ignore(10, '\n');
                        cin.get();
                        betbetflag=true;
                        system("clear");
                        break;
                    }
                if (betbetflag){
                    continue;
                }
                stringstream yy;
                yy << betanswer;
                yy >> bet;
                if (bet<=balance && bet>=1){
                    balance-=bet;
                    betlist[betoption]=bet;
                    totalbet+=bet;
                    cout<<"A bet is placed successfully."<<endl<<endl;
                }
                else{
                    cout<<"Balance not enough. Press Enter to return to betting menu."<<endl;
                    cin.ignore(10,'\n');
                    cin.get();
                    continue;
                }
                if (balance>0){
                    cout<< "Have you finished placing your bet? (Y/N): ";
                    cin>>finishbet;
                    if (finishbet=='Y'||finishbet=='y'){
                        betflag=true;
                        system("clear");
                    }
                    else if (finishbet=='N'||finishbet=='n'){
                        cout<<"Press Enter to return to betting menu."<<endl;
                        cin.ignore(10,'\n');
                        cin.get();
                    }
                    else{
                        cout<<"Invalid option."<<" Press Enter to return to betting menu."<<endl;
                        cin.ignore(10,'\n');
                        cin.get();
                    }
                }
                else{
                    betflag=true;
                    cout<< "Your balance is $0."<<endl;
                    cout<<"Press Enter to roll the ball."<<endl;
                    cin.ignore(10,'\n');
                    cin.get();
                    system("clear");
                }
            }
            cout<< "  \033[30;47m ---------------------------------------------------------------- \033[0m"<<endl;
            cout<< "  \033[30;47m|\033[37;41m 3 \033[30;47m|\033[37;40m 6 \033[30;47m|\033[37;41m 9 \033[30;47m|\033[37;41m 12 \033[30;47m|\033[37;40m 15 \033[30;47m|\033[37;41m 18 \033[30;47m|\033[37;41m 21 \033[30;47m|\033[37;40m 24 \033[30;47m|\033[37;41m 27 \033[30;47m|\033[37;41m 30 \033[30;47m|\033[37;40m 33 \033[30;47m|\033[37;41m 36 \033[30;47m|\033[30;42m row 1 \033[30;47m|\033[0m"<<endl;
            cout<< "  \033[30;47m ---------------------------------------------------------------- \033[0m"<<endl;
            cout<< "  \033[30;47m|\033[37;40m 2 \033[30;47m|\033[37;41m 5 \033[30;47m|\033[37;40m 8 \033[30;47m|\033[37;40m 11 \033[30;47m|\033[37;41m 14 \033[30;47m|\033[37;40m 17 \033[30;47m|\033[37;40m 20 \033[30;47m|\033[37;41m 23 \033[30;47m|\033[37;40m 26 \033[30;47m|\033[37;40m 29 \033[30;47m|\033[37;41m 32 \033[30;47m|\033[37;40m 35 \033[30;47m|\033[30;42m row 2 \033[30;47m|\033[0m"<<endl;
            cout<< "  \033[30;47m ---------------------------------------------------------------- \033[0m"<<endl;
            cout<< "  \033[30;47m|\033[37;41m 1 \033[30;47m|\033[37;40m 4 \033[30;47m|\033[37;41m 7 \033[30;47m|\033[37;40m 10 \033[30;47m|\033[37;40m 13 \033[30;47m|\033[37;41m 16 \033[30;47m|\033[37;41m 19 \033[30;47m|\033[37;40m 22 \033[30;47m|\033[37;41m 25 \033[30;47m|\033[37;40m 28 \033[30;47m|\033[37;40m 31 \033[30;47m|\033[37;41m 34 \033[30;47m|\033[30;42m row 3 \033[30;47m|\033[0m"<<endl;
            cout<< "  \033[30;47m ---------------------------------------------------------------- \033[0m"<<endl;
            cout<< "  \033[30;47m|\033[30;42m     1st 12     \033[30;47m|\033[30;42m      2nd 12       \033[30;47m|\033[30;42m       3rd 12      \033[30;47m|\033[0m" <<endl;
            cout<< "  \033[30;47m -------------------------------------------------------- \033[0m"  <<endl<<endl;
            ball=rand()%36+1;
            cout<<"Ball rolling";
            for (int i=0;i<10;i++){
                cout<<"."<< flush;
                usleep(300000);
            }
            cout<< ball<<endl<<endl;
            betdisplay(betlist);
            cout<<endl<<"****************"<<endl;
            win = result(betlist,ball);
            balance +=win;
            if (win-totalbet>0){
                cout<<"You win $"<<win-totalbet<<endl;
            }
            else if (win-totalbet<0){
                cout<<"You lose $"<<totalbet-win<<endl;
            }
            else
                cout<<"You do not win or lose this time."<<endl;
            if (balance==0){
                stopflag=true;
                cout<<endl<<"Your balance: $0" << endl;
                cout<<"Press Enter to go back to the lobby.";
                cin.ignore(10,'\n');
                cin.get();
                system("clear");
                break;
            }
            cout<< "Press Enter to continue."<<endl;
            cin.ignore(10,'\n');
            cin.get();
            delete[] betlist;
            system("clear");
        }   
        else if (choice=='Q'||choice=='q'){
            cout<<endl<<"Your balance: $"<< balance << endl;
            cout<<"Thank you for playing Roulette."<<endl;
            cout<<"Press Enter to continue."<<endl;
            cin.ignore(10,'\n');
            cin.get();
            system("clear");
            stopflag=true;
        }
        else{
            cout<<"Wrong input. Please try again!"<<endl;
            cout<<"Press Enter to continue.";
            cin.ignore(10, '\n');
            cin.get();
            system("clear");
        }
    }
    return balance;
}

//int main(){
//    roulettegame(100,"Andy");
//    return 0;
//}
