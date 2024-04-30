#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <unistd.h>
#include "print_text.h"

using namespace std;

bool verifylogin(const string & username, const string & passward, const string & filename){
    
    ifstream input(filename);

    if (!input){
        return false;
    }

    string line;
    string record = username + ',' + passward;

    while (getline(input, line)){
        if (line == record){
            return true;
        }
    }

    return false;
}

string old_user(){

    print_text_without_endl("If you want to creat a new account, type 'back' to back menu");
    cout << " " << endl;

    string username, passward;

    print_text_without_endl("Please enter your username: ");
    cin >> username;

    if (username == "back" || passward == "back"){
        return "q";
    }

    print_text_without_endl("Please enter your passward: ");
    cin >> passward;

    if (username == "back" || passward == "back"){
        return "q";
    }

    bool login_successfully = verifylogin(username,passward,"user_name.txt");

    while (login_successfully == false){
        
        print_text_without_endl("Incorrect username or passward.");
        cout << " " << endl;

        print_text_without_endl("Please enter your username: ");
        cin >> username;

        print_text_without_endl("Please enter your passward: ");
        cin >> passward;

        if (username == "back" || passward == "back"){
            return "q";
        }

        login_successfully = verifylogin(username,passward,"user_name.txt");

    }
    
    print_text_with_endl("Login successfully!");
    string toprint = "Hello " + username;
    print_text_with_endl(toprint);
    usleep(1000000);
    return username;
}

bool double_name(const string & username, const string & filename){
    
    ifstream input(filename);

    if (!input){
        return false;
    }

    string line;
    string name;
    while (getline(input, line)){
        for (int i = 0; i < line.length();i++){
            if (line[i] == ','){
                name = line.substr(0,i);
            }
            if (username == name){
                return true;
            }
        }
    }

    return false;
}

string new_user(){
    print_text_without_endl("If you have an old account, type 'back' to back menu");
    cout << " " << endl;
    string username, passward;
    print_text_without_endl("Please enter your username: ");
    cin >> username;
    if (username == "back"){
            return "q";
    }
    
    bool check_double = double_name(username, "user_name.txt");

    while (check_double){

        ifstream output("So_sad.txt");
        if (!output){
            exit(1);
        }
        string line;
        while (getline(output,line)){
            print(line,2000);
        }
        output.close();
        cout << " " << endl;

        print_text_without_endl("Please enter your username: ");
        cin >> username;

        if (username == "back"){
            return "q";
        }

        check_double = double_name(username,"user_name.txt");
    }

    print_text_without_endl("Please enter your passward: ");
    cin >> passward;

    if (passward == "back"){
        return "q";
    }

    ofstream fout("user_name.txt",ios::app);
    if (fout.fail()){
        exit(1);
    }

    fout << username << "," << passward << endl;
    fout.close();

    ofstream fout1("Money.txt",ios::app);
    if (fout1.fail()){
        exit(1);
    }

    fout1 << username << "," << "10000" << endl;
    fout1.close();

    string toprint = "Hello " + username;
    print_text_with_endl(toprint);
    cout << username << endl;
    return username;
}

string login_system(){

   string loginchoice;
   string username;

   cout << "***************************************************************************************************" << endl;
   print_text_with_endl("");
   print_text_with_endl("               1.New user");
   print_text_with_endl("               2.Old user");
   print_text_with_endl("               3.Quit");
   print_text_with_endl("");
   cout << "***************************************************************************************************" << endl;
   print_text_without_endl("Your choice(1-3): ");
   
   cin >> loginchoice;

   
   while (loginchoice != "3"){
      if (loginchoice == "1"){
         username = new_user();
         if (username == "q"){
            system("clear");
            username = login_system();
            break;
         }
         break;
      }
      else if (loginchoice == "2"){
         username = old_user();
         if (username == "q"){
            system("clear");
            username = login_system();
            break;
         }
         break;
      }
      else{
         print_text_without_endl("wrong input,please enter again");
      }
      cin >> loginchoice;
   }

   if (loginchoice == "3"){
        string line;
        ifstream output2("Goodbye.txt");
            if (!output2){
                exit(1);
            }
            // string line;
            while (getline(output2,line)){
                print(line,2000);
            }

        output2.close(); 
      
      return "q"; 
   }

   return username; 
}
