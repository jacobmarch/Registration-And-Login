#include <iostream>
#include <fstream>
#include <string>


using namespace::std;

string u, p, entry;

bool isLoggedIn(){
    string username, password, un, pw;

    cout << "Enter username: "; cin >> username;
    cout << "Enter password: "; cin >> password;

    ifstream read(username + ".txt");
    getline(read, un);
    getline(read, pw);

    if (un == username && pw == password){
        u = username;
        p = password;
        return true;
    }
    else {
        return false;
    }
}

int main(){

    int choice;

    cout << "1: Register\n2: Login\n3: Quit\nYour choice: "; cin >> choice;
    
    if (choice == 1){
        string username, password;

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

            cout << endl << "Type your journal entry: " << endl;
            getline(cin, entry);
            
            ofstream journal;
            journal.open(u + ".txt", ios_base::app);
            

            journal << entry;
            
            
            


        }
    }
    else if (choice == 3){
        system("PAUSE");
        return 0;
    }


    return 0;

}