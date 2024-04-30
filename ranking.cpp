#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <list>
#include <map>
#include <iomanip>
#include "print_text.h"

using namespace std;

struct Node{
    string name;
    int money;
    Node * next; 
};

void append(string user_name, int user_money, Node * &head){
    Node * p = new Node, * previous = head;
    p->name = user_name;
    p->money = user_money;
    if (head == NULL){
        p->next = NULL;
        head = p;
    }
    else if (head->money <= user_money && head->next == NULL){
        p->next = NULL;
        head->next = p;
    }
    else if(head->money > user_money){
        p->next = head;
        head = p;
    }
    else{
        while (previous != NULL && previous->next != p){
            if (previous->next->money <= user_money){
                if (previous->next->next == NULL){
                    p->next = NULL;
                    previous->next->next = p;
                }
                previous = previous->next;
            }
            else
            {
                p->next = previous->next;
                previous->next = p;

            }
        }
    }
}

void reverse(Node * & head){
    Node * current = head;
    Node * prev = NULL;
    Node * next = new Node;

    while (current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void print_linked_list(Node * & head){
    Node * current = head;
    int count = 1,space;
    string spacing = "";
    while (current != NULL){
        if (count < 10){
            print_text_without_endl(to_string(count));
        }
        else if (count >= 10 && count < 1000){
            print_text_without_endl_choose_setw(to_string(count),29);
        }
        else if (count >= 1000 && count < 10000){
            print_text_without_endl_choose_setw(to_string(count),28);
        }
        print_text_without_endl(current->name);

        space = 34 - current->name.length();

        for (int y = 0; y < space; y++){
            spacing += " ";
        }
        
        print_text_without_endl_choose_setw(spacing,0);

        cout << current->money << endl;
        current = current->next;
        count += 1;
        spacing = "";
    }
    cout << endl;
}

void take_info(Node *& head){
    ifstream input("Money.txt");

    string line,money,name;

    while (getline(input, line)){
        
        for (int i = 0; i < line.length(); i++){
            if (line[i] == ','){
                name = line.substr(0,i);
                money = line.substr(i+1);
            }
            
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
        }

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

        append(name,money_int,head);
    }
    
    input.close();

}

void ranking_system(){
    Node * head = NULL;
    take_info(head);
    reverse(head);
    print_text_without_endl_choose_setw("#",30);
    print_text_without_endl_choose_setw("Name",30);
    print_text_without_endl_choose_setw("Balance",31);
    cout << endl;
    // cout << setw(30) << "#" << setw(33) << "Name" << setw(37) << "Balance" << endl;
    print_linked_list(head);
}
