

#include <iostream>
#include "player.cc"
#include "save_file.cc"

using namespace std;

int main () {
    Player loadedPlayer;
    Player savedPlayers[12];
    SaveFile fileManager;

    ifstream infile;

    loadedPlayer.LoadPlayer("Testing", 100, 10);

    cout << loadedPlayer.ToFile();

    infile.open("save.dat");
    int lineCount = 0;
    string myLine = "";

    if (infile.is_open() ) {
        lineCount = 0;

        while (getline(infile, myLine)) {
            savedPlayers[lineCount].FromFile(myLine);

            savedPlayers[lineCount].ToString();

            lineCount++;
        }
        infile.close();
    }


    return 0;
}

