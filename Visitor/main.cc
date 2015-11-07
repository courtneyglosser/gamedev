
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

Player handleAction (SaveFile &fileManager) {
    char nextAction = '0';
    string name = "";
    string line = "";
    string nameFromFile = "";
    int xp = -1;
    int selPlayer = 0;
    Player actualPlayer;

    cin >> nextAction;

    if (nextAction == '1') {
        cout << "Brand new game!" << endl;
        cout << "Enter your name:  ";
        cin >> name;

        actualPlayer.loadPlayer(name, 0, 10);
        fileManager.AddNewProfile();
    }
    else if (nextAction == '2') {
        cout << "Loading an existing game!" << endl;

        //Declare array of savedPlayers
        Player savedPlayers[fileManager.GetNumSavedProfiles()];

        //Done.  Now, loadPlayers
        fileManager.LoadPlayers(savedPlayers);

        actualPlayer = fileManager.SelectPlayer(savedPlayers);
    }

    return actualPlayer;
}

int main () {
    Player loadedPlayer;
    SaveFile fileManager;

    fileManager.DefNumSavedProfiles();

    welcome();

    loadedPlayer = handleAction(fileManager);

    cout << "Selected:  " << endl;
    loadedPlayer.toString();

    cout << "XP for loading the character!" << endl;
    loadedPlayer.learn(2);

    cout << "Save player, now!" << endl;
    fileManager.SavePlayer(loadedPlayer);

    cout << "Exit, you shall!" << endl;
    return 0;
}

