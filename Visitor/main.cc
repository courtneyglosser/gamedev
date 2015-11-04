
#include <iostream>
#include <string>
#include <fstream>
#include "player.cc"

using namespace std;

void welcome() {
    cout << "Welcome" << endl;
    cout << "Press 1 for a new game" << endl;
    cout << "Press 2 to load a saved game" << endl;
    cout << "Press any other key to exit" << endl;
}

Player handleAction () {
    char nextAction = '0';
    string name = "";
    string line = "";
    string nameFromFile = "";
    int xp = -1;
    ifstream myFile ("save.dat");
    int lineCount = 0;
    int selPlayer = 0;
    Player actualPlayer;

    cin >> nextAction;

    if (nextAction == '1') {
        cout << "Brand new game!" << endl;
        cout << "Enter your name:  ";
        cin >> name;

        actualPlayer.loadPlayer(name, 0, 10);

    }
    else if (nextAction == '2') {
        cout << "Loading an existing game!" << endl;

        if (myFile.is_open() ) {
            // Validate file, and determine how many save slots are used.
            while (myFile >> nameFromFile >> xp) {
                if (!nameFromFile.empty() && xp>-1) {
                    ++lineCount;
                }
            }
            if (lineCount > 0) {
                // ASSERT:  I've read at least on player in.
                // Clear the file EOF flag.
                myFile.clear();
                // Reset cursor to beginning of file
                myFile.seekg(0, ios::beg);

                Player myPlayers[lineCount];

                lineCount = 0;

                while (myFile >> nameFromFile >> xp) {
                    myPlayers[lineCount].loadPlayer(nameFromFile, xp, 0);
                    lineCount++;
                }

                for (int i = 0; i < lineCount; i++) {
                    cout << "Press " << i+1 << " for this player: " << endl;
                    cout << "======================== " << endl;
                    myPlayers[i].toString();
                    cout << endl;
                }

                cin >> selPlayer;
                selPlayer--;
                if (selPlayer >= 0 && selPlayer <= lineCount) {
                    actualPlayer = myPlayers[selPlayer];
                }
            }
            myFile.close();
        }
    }

    return actualPlayer;
}

int main () {
    Player loadedPlayer;

    welcome();

    loadedPlayer = handleAction();

    cout << "Selected:  " << endl;
    loadedPlayer.toString();

    cout << "Exit, you shall!" << endl;
    return 0;
}

