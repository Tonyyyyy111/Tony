#include <iostream>
#include <iomanip>
#include <unistd.h>
#include "print_text.h"
using namespace std;

void print_text_with_endl(string s){
    cout << setw(30);
    for (int i = 0; i < s.size(); i++){
        if (i % 2 == 0 || i == 0){
            cout << s[i] << flush;
        }
        else{
            usleep(25000);
            cout << s[i] << flush;
        }
    }
    
    cout << endl;
}

void print_text_without_endl(string s){
    cout << setw(30);
    for (int i = 0; i < s.size(); i++){
        if (i % 2 == 0 || i == 0){
            cout << s[i] << flush;
        }
        else{
            usleep(25000);
            cout << s[i] << flush;
        }
    }
}

void print(string s, int a){
    cout << setw(30);
    for (int i = 0; i < s.size(); i++){
        if (i % 2 == 0 || i == 0){
            cout << s[i] << flush;
        }
        else{
            usleep(a);
            cout << s[i] << flush;
        }
    }
    cout << endl;
}

void print_text_without_endl_choose_setw(string s,int a){
    cout << setw(a);
    for (int i = 0; i < s.size(); i++){
        if (i % 2 == 0 || i == 0){
            cout << s[i] << flush;
        }
        else{
            usleep(2000);
            cout << s[i] << flush;
        }
    }
}
