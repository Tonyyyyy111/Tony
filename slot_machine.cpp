#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <sstream>
#include <limits>
#include <cstdio>
using namespace std;

void displayGameRules() {
    cout << "=== Slot Machine Game Rules ===" << endl;
    cout << "1. Nine numbers will be generated between 1 and 9." << endl;
    cout << "2. If three numbers in a row are the same, you win." << endl;
    cout << "3. Otherwise, you lose!" << endl;
}

void displaySlotMachine(const int nums[3][3]) {
    cout << "=== Slot Machine ===" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "[" << nums[i][j] << "]";
        }
        cout << endl;
    }
}

bool check_number(string str) {
   for (int i = 0; i < str.length(); i++)
   if (isdigit(str[i]) == false)
      return false;
      return true;
}

int playSlotMachine(int balance) {
    // Generate three random numbers between 1 and 9
    if (balance == 0){
        cout << "You have bankrupted, please earn enough money to play the slot machine" << endl;
        return 0;
    }
    string input;
    int bet;
    cout << "Amount to bet: $";
    cin >> input;
    bool continue_game = false;
    while (continue_game == false){
        if (check_number(input) == false){
            cout << "Invalid choice. Please try again." << endl;
            cout << "Amount to bet: $";
            cin >> input;
        }
        else{
            bet = stoi(input);
            if (bet > 0 && bet < balance){
                continue_game = true;
            }
            else if (bet <= 0){
                cout << "You should bet at least one dollar." << endl;
                cout << "Amount to bet: $";
                cin >> input;
            }
            else if (bet > balance){
                cout << "You dont have " << bet << " dollars." <<endl;
                cout << "Amount to bet: $";
                cin >> input;
            }
        }
    }
    int nums[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    srand(time(NULL));
    for (int k = 0; k < 15; ++k){
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                nums[i][j] = rand() % 9 + 1;
                if (i == 0){
                    while(nums[1][j] == nums[i][j] || nums[2][j] == nums[i][j]){
                        nums[i][j] = rand() % 9 + 1;
                    }
                }
                else if (i == 1){
                    while (nums[0][j] == nums[i][j] || nums[2][j] == nums[i][j]){
                        nums[i][j] = rand() % 9 + 1;
                    }
                }
                else if (i == 2){
                    while (nums[0][j] == nums[i][j] || nums[1][j] == nums[i][j]){
                        nums[i][j] = rand() % 9 + 1;
                    }
                }
            }
        } 
        system("clear");
        displaySlotMachine(nums);
        usleep(100000);
    }

    // Check for win or loss
    int centerNum = nums[1][1];
    if (nums[1][0] == centerNum && nums[1][2] == centerNum) {
        cout << "You have just won $" << bet*999 << " !!!" << endl;
        cout << "   $$\\       $$$$$\\  $$$$$$\\   $$$$$$\\  $$\\   $$\\ $$$$$$$\\   $$$$$$\\ $$$$$$$$\\   $$\\    " << endl;
        cout << " $$$$$$\\     \\__$$ |$$  __$$\\ $$  __$$\\ $$ | $$  |$$  __$$\\ $$  __$$\\\\__$$  __|$$$$$$\\  "<< endl;
        cout << "$$  __$$\\       $$ |$$ /  $$ |$$ /  \\__|$$ |$$  / $$ |  $$ |$$ /  $$ |  $$ |  $$  __$$\\\\ "<< endl;
        cout << "$$ /  \\__|      $$ |$$$$$$$$ |$$ |      $$$$$  /  $$$$$$$  |$$ |  $$ |  $$ |  $$ /  \\__|"<< endl;
        cout << "\\$$$$$$\\  $$\\   $$ |$$  __$$ |$$ |      $$  $$<   $$  ____/ $$ |  $$ |  $$ |  \\$$$$$$\\  "<< endl;
        cout << " \\___ $$\\ $$ |  $$ |$$ |  $$ |$$ |  $$\\ $$ |\\$$\\  $$ |      $$ |  $$ |  $$ |   \\___ $$\\ "<< endl;
        cout << "$$\\  \\$$ |\\$$$$$$  |$$ |  $$ |\\$$$$$$  |$$ | \\$$\\ $$ |       $$$$$$  |  $$ |  $$\\  \\$$ |"<< endl;
        cout << "\\$$$$$$  | \\______/ \\__|  \\__| \\______/ \\__|  \\__|\\__|       \\______/   \\__|  \\$$$$$$  |"<< endl;
        cout << " \\_$$  _/                                                                      \\_$$  _/ "<< endl;
        cout << "   \\ _/                                                                          \\ _/   "<< endl;
        return bet * 999;
    } 
    else if (nums[0][0] == centerNum && nums[2][2] == centerNum){
        cout << "You have just won $" << bet*999 << " !!!" << endl;
        cout << "   $$\\       $$$$$\\  $$$$$$\\   $$$$$$\\  $$\\   $$\\ $$$$$$$\\   $$$$$$\\ $$$$$$$$\\   $$\\    " << endl;
        cout << " $$$$$$\\     \\__$$ |$$  __$$\\ $$  __$$\\ $$ | $$  |$$  __$$\\ $$  __$$\\\\__$$  __|$$$$$$\\  "<< endl;
        cout << "$$  __$$\\       $$ |$$ /  $$ |$$ /  \\__|$$ |$$  / $$ |  $$ |$$ /  $$ |  $$ |  $$  __$$\\\\ "<< endl;
        cout << "$$ /  \\__|      $$ |$$$$$$$$ |$$ |      $$$$$  /  $$$$$$$  |$$ |  $$ |  $$ |  $$ /  \\__|"<< endl;
        cout << "\\$$$$$$\\  $$\\   $$ |$$  __$$ |$$ |      $$  $$<   $$  ____/ $$ |  $$ |  $$ |  \\$$$$$$\\  "<< endl;
        cout << " \\___ $$\\ $$ |  $$ |$$ |  $$ |$$ |  $$\\ $$ |\\$$\\  $$ |      $$ |  $$ |  $$ |   \\___ $$\\ "<< endl;
        cout << "$$\\  \\$$ |\\$$$$$$  |$$ |  $$ |\\$$$$$$  |$$ | \\$$\\ $$ |       $$$$$$  |  $$ |  $$\\  \\$$ |"<< endl;
        cout << "\\$$$$$$  | \\______/ \\__|  \\__| \\______/ \\__|  \\__|\\__|       \\______/   \\__|  \\$$$$$$  |"<< endl;
        cout << " \\_$$  _/                                                                      \\_$$  _/ "<< endl;
        cout << "   \\ _/                                                                          \\ _/   "<< endl;
        return bet * 999;
    }
    else if (nums[0][2] == centerNum && nums[2][0] == centerNum){
        cout << "You have just won $" << bet*999 << " !!!" << endl;
        cout << "   $$\\       $$$$$\\  $$$$$$\\   $$$$$$\\  $$\\   $$\\ $$$$$$$\\   $$$$$$\\ $$$$$$$$\\   $$\\    " << endl;
        cout << " $$$$$$\\     \\__$$ |$$  __$$\\ $$  __$$\\ $$ | $$  |$$  __$$\\ $$  __$$\\\\__$$  __|$$$$$$\\  "<< endl;
        cout << "$$  __$$\\       $$ |$$ /  $$ |$$ /  \\__|$$ |$$  / $$ |  $$ |$$ /  $$ |  $$ |  $$  __$$\\\\ "<< endl;
        cout << "$$ /  \\__|      $$ |$$$$$$$$ |$$ |      $$$$$  /  $$$$$$$  |$$ |  $$ |  $$ |  $$ /  \\__|"<< endl;
        cout << "\\$$$$$$\\  $$\\   $$ |$$  __$$ |$$ |      $$  $$<   $$  ____/ $$ |  $$ |  $$ |  \\$$$$$$\\  "<< endl;
        cout << " \\___ $$\\ $$ |  $$ |$$ |  $$ |$$ |  $$\\ $$ |\\$$\\  $$ |      $$ |  $$ |  $$ |   \\___ $$\\ "<< endl;
        cout << "$$\\  \\$$ |\\$$$$$$  |$$ |  $$ |\\$$$$$$  |$$ | \\$$\\ $$ |       $$$$$$  |  $$ |  $$\\  \\$$ |"<< endl;
        cout << "\\$$$$$$  | \\______/ \\__|  \\__| \\______/ \\__|  \\__|\\__|       \\______/   \\__|  \\$$$$$$  |"<< endl;
        cout << " \\_$$  _/                                                                      \\_$$  _/ "<< endl;
        cout << "   \\ _/                                                                          \\ _/   "<< endl;
        return bet * 999;
    }
     else if (nums[0][0] == nums[0][1] && nums[0][0] == nums[0][2]){
        cout << "You have just won $" << bet*999 << " !!!" << endl;
        cout << "   $$\\       $$$$$\\  $$$$$$\\   $$$$$$\\  $$\\   $$\\ $$$$$$$\\   $$$$$$\\ $$$$$$$$\\   $$\\    " << endl;
        cout << " $$$$$$\\     \\__$$ |$$  __$$\\ $$  __$$\\ $$ | $$  |$$  __$$\\ $$  __$$\\\\__$$  __|$$$$$$\\  "<< endl;
        cout << "$$  __$$\\       $$ |$$ /  $$ |$$ /  \\__|$$ |$$  / $$ |  $$ |$$ /  $$ |  $$ |  $$  __$$\\\\ "<< endl;
        cout << "$$ /  \\__|      $$ |$$$$$$$$ |$$ |      $$$$$  /  $$$$$$$  |$$ |  $$ |  $$ |  $$ /  \\__|"<< endl;
        cout << "\\$$$$$$\\  $$\\   $$ |$$  __$$ |$$ |      $$  $$<   $$  ____/ $$ |  $$ |  $$ |  \\$$$$$$\\  "<< endl;
        cout << " \\___ $$\\ $$ |  $$ |$$ |  $$ |$$ |  $$\\ $$ |\\$$\\  $$ |      $$ |  $$ |  $$ |   \\___ $$\\ "<< endl;
        cout << "$$\\  \\$$ |\\$$$$$$  |$$ |  $$ |\\$$$$$$  |$$ | \\$$\\ $$ |       $$$$$$  |  $$ |  $$\\  \\$$ |"<< endl;
        cout << "\\$$$$$$  | \\______/ \\__|  \\__| \\______/ \\__|  \\__|\\__|       \\______/   \\__|  \\$$$$$$  |"<< endl;
        cout << " \\_$$  _/                                                                      \\_$$  _/ "<< endl;
        cout << "   \\ _/                                                                          \\ _/   "<< endl;
        return bet * 999;
    }
     else if (nums[2][0] == nums[2][1] && nums[2][0]== nums[2][2]){
        cout << "You have just won $" << bet*999 << " !!!" << endl;
        cout << "   $$\\       $$$$$\\  $$$$$$\\   $$$$$$\\  $$\\   $$\\ $$$$$$$\\   $$$$$$\\ $$$$$$$$\\   $$\\    " << endl;
        cout << " $$$$$$\\     \\__$$ |$$  __$$\\ $$  __$$\\ $$ | $$  |$$  __$$\\ $$  __$$\\\\__$$  __|$$$$$$\\  "<< endl;
        cout << "$$  __$$\\       $$ |$$ /  $$ |$$ /  \\__|$$ |$$  / $$ |  $$ |$$ /  $$ |  $$ |  $$  __$$\\\\ "<< endl;
        cout << "$$ /  \\__|      $$ |$$$$$$$$ |$$ |      $$$$$  /  $$$$$$$  |$$ |  $$ |  $$ |  $$ /  \\__|"<< endl;
        cout << "\\$$$$$$\\  $$\\   $$ |$$  __$$ |$$ |      $$  $$<   $$  ____/ $$ |  $$ |  $$ |  \\$$$$$$\\  "<< endl;
        cout << " \\___ $$\\ $$ |  $$ |$$ |  $$ |$$ |  $$\\ $$ |\\$$\\  $$ |      $$ |  $$ |  $$ |   \\___ $$\\ "<< endl;
        cout << "$$\\  \\$$ |\\$$$$$$  |$$ |  $$ |\\$$$$$$  |$$ | \\$$\\ $$ |       $$$$$$  |  $$ |  $$\\  \\$$ |"<< endl;
        cout << "\\$$$$$$  | \\______/ \\__|  \\__| \\______/ \\__|  \\__|\\__|       \\______/   \\__|  \\$$$$$$  |"<< endl;
        cout << " \\_$$  _/                                                                      \\_$$  _/ "<< endl;
        cout << "   \\ _/                                                                          \\ _/   "<< endl;
        return bet * 999;
    }
    else {
        cout << "You have lost $" << bet << endl;
        cout << "NEXT ONE MIGHT BE JACKPOT!" << endl;
        return bet * (-1);
    }

}

int SlotMachine(int balance, string username) {
    system("clear");
    cout <<"Hello " << username << "! Welcome to" << endl << endl;
    cout <<"▄▄███▄▄·██╗      ██████╗ ████████╗    ███╗   ███╗ █████╗  ██████╗██╗  ██╗██╗███╗   ██╗███████╗"<<endl;
    cout <<"██╔════╝██║     ██╔═══██╗╚══██╔══╝    ████╗ ████║██╔══██╗██╔════╝██║  ██║██║████╗  ██║██╔════╝"<<endl;
    cout <<"███████╗██║     ██║   ██║   ██║       ██╔████╔██║███████║██║     ███████║██║██╔██╗ ██║█████╗  "<<endl;
    cout <<"╚════██║██║     ██║   ██║   ██║       ██║╚██╔╝██║██╔══██║██║     ██╔══██║██║██║╚██╗██║██╔══╝  "<<endl;
    cout <<"███████║███████╗╚██████╔╝   ██║       ██║ ╚═╝ ██║██║  ██║╚██████╗██║  ██║██║██║ ╚████║███████╗"<<endl;
    cout <<"╚═▀▀▀══╝╚══════╝ ╚═════╝    ╚═╝       ╚═╝     ╚═╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝╚══════╝|"<<endl;


    char understand;
    cout << "Do you understand the game rules? (y/n): ";
    cin >> understand;

    if (understand == 'n' || understand == 'N') {
        system("clear");
        displayGameRules();
        cout<<"========================================"<<endl;
    }

    string choice;
    do {
        cout << "Press 's' to start the game or 'q' to quit: ";
        cin >> choice;
        cout<< "****************************************"<<endl;
        if (choice == "s" || choice == "S") {
            if (balance == 0){
                cout << "You have bankrupted, please earn enough money to play the slot machine" << endl;
                cout<<"Thank you for playing Blackjack."<<endl;
                cout<<"Press \"Enter\" to continue."<<endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                system("clear");

                return balance;
            }
            balance += playSlotMachine(balance);
        } else if (choice == "q" || choice == "Q") {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }

        string playAgain;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

        if (playAgain == "n" || playAgain == "N") {
            break;
        }

        else if (playAgain == "y" || playAgain == "Y") continue;
        else{
            while (playAgain != "y" && playAgain != "Y" && playAgain != "N" && playAgain != "n"){
                cout << "Invalid choice. Please try again." << endl;
                cout << "Do you want to play again? (y/n): ";
                cin >> playAgain;
                if (playAgain == "n" || playAgain == "N") {
                    cout<<"Thank you for playing Blackjack."<<endl;
                    cout<<"Press \"Enter\" to continue."<<endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.get();
                    system("clear");
                    return balance;
                }

            }
        }
    } while (true);

    cout<<"Thank you for playing Blackjack."<<endl;
    cout<<"Press \"Enter\" to continue."<<endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    system("clear");

    return balance;
}

// int main(){
//     cout << SlotMachine(1000,"111") << endl;
// }

