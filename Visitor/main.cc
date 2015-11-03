
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void welcome() {
    cout << "Welcome" << endl;
    cout << "Press 1 for a new game" << endl;
    cout << "Press 2 to load a saved game" << endl;
    cout << "Press any other key to exit" << endl;
}

void handleAction () {
    char nextAction = '0';
    string name = "";
    string line = "";
    string nameFromFile = "";
    int xp = 0;
    ifstream myFile ("save.dat");

    cin >> nextAction;

    if (nextAction == '1') {
        cout << "Brand new game!" << endl;
        cout << "Enter your name:  ";
        cin >> name;

    }
    else if (nextAction == '2') {
        cout << "Loading an existing game!" << endl;

        if (myFile.is_open() ) {
//            while (getline (myFile, line) ) {
//                cout << "Line:  " << line << endl;
            while (myFile >> nameFromFile >> xp) {
                cout << "Name:  " << nameFromFile << endl;
                cout << "XP:  " << xp << endl;
            }
            myFile.close();
        }
    }
}

int main () {
    welcome();

    handleAction();

    cout << "Exit, you shall!" << endl;
    return 0;
}

