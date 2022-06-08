#include <iostream>
#include <fstream>
#include <string>


using namespace::std;

bool isLoggedIn(){
    string username, password, un, pw;

    cout << "Enter username: "; cin >> username;
    cout << "Enter password: "; cin >> password;

    ifstream read(username + ".txt");
    getline(read, un);
    getline(read, pw);

    if (un == username && pw == password){
        return true;
    }
    else {
        return false;
    }
}

int main(){

    int choice;

    cout << "1: Register\n2: Login\n3: Quit\nYour choice: "; cin >> choice;
    string username, password;
    if (choice == 1){
        

        cout << "Select a username: "; cin >> username;
        cout << "Select a password: "; cin >> password;

        ofstream file;
        file.open(username + ".txt");
        file << username << endl << password;
        file.close();

        main();
    }
    else if (choice == 2){
        bool status = isLoggedIn();

        if (!status){
            cout << "No Account Found" << endl;
            cout << endl;
            main();
        }
        else {
            cout << "Login Successful" << endl;


            string entry;
            ofstream journal;
            journal.open(username + ".txt");
            cin >> entry;

            journal << entry;
            
            
            


        }
    }
    else if (choice == 3){
        system("PAUSE");
        return 0;
    }


    return 0;

}