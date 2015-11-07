
#include <iostream>
#include <string>
#include <fstream>
#include "player.cc"
#include "save_file.cc"

using namespace std;

void welcome() {
    cout << "Welcome" << endl;
    cout << "Press 1 for a new game" << endl;
    cout << "Press 2 to load a saved game" << endl;
    cout << "Press any other key to exit" << endl;
}

Player handleAction () {
    SaveFile fileManager;
    char nextAction = '0';
    string name = "";
    string line = "";
    string nameFromFile = "";
    int xp = -1;
    ifstream myFile ("save.dat");
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

        //Declare array of savedPlayers
        Player savedPlayers[fileManager.getNumSavedProfiles()];

        //Done.  Now, loadPlayers
        fileManager.loadPlayers(savedPlayers);

        actualPlayer = fileManager.selectPlayer(savedPlayers);
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

