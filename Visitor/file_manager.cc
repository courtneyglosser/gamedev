// file_manager.cc
// FileManager class
#include <iostream>
#include <fstream>
#include "player.cc"

#ifndef __FILE_MANAGER_CC_INCLUDED__
#define __FILE_MANAGER_CC_INCLUDED__

using namespace std;


class FileManager {
    private:
        ifstream infile;        // File reading stream
        ofstream outfile;       // File writing stream
        int numSavedProfiles;   // Count of saved profiles read from file
        int currActiveProfile;  // The current profile of user playing

    public:
        // Basic Constructor.  Read file and count total profiles
        FileManager () {
            DefNumSavedProfiles();
        }

        // Read in file and count number of profiles saved there.
        void DefNumSavedProfiles();

        int GetNumSavedProfiles () { return numSavedProfiles; }

        void AddNewProfile();

        void LoadPlayers (Player savedPlayers[]);

        Player SelectPlayer(Player savedPlayers[]);

        int SavePlayer(Player toSave);
};


void FileManager::DefNumSavedProfiles() {
    // TODO:  abstract this filename a bit more.  Maybe a base
    // "filemanager" class to handle this stuff.
    infile.open("save.dat");
    string line = "";

    numSavedProfiles = 0;

    if (infile.is_open() ) {
        // each line represents a save file
        while (getline(infile, line)) {
            ++numSavedProfiles;
        }
    }
    infile.close();
}

void FileManager::AddNewProfile() {
    currActiveProfile = numSavedProfiles;
    numSavedProfiles++;
}

void FileManager::LoadPlayers (Player savedPlayers[]) {
    infile.open("save.dat");
    int lineCount = 0;
    string myLine = "";

    if (infile.is_open() ) {
        if (numSavedProfiles > 0) {
            lineCount = 0;
            while (getline(infile, myLine) 
                    && lineCount < numSavedProfiles) {
                savedPlayers[lineCount].FromFile(myLine);
                lineCount++;
            }
        }
        infile.close();
    }

}

Player FileManager::SelectPlayer(Player savedPlayers[]) {
    Player actualPlayer;
    char selPlayer;
    int input;

    for (int i = 0; i < numSavedProfiles; i++) {
        cout << "Press " << i+1 << " for this player: " << endl;
        cout << "======================== " << endl;
        savedPlayers[i].ToString();
        cout << endl;
    }

    cin >> selPlayer;
    // Convert char input to integer for boolean check
    input = selPlayer - '0';
    input--;
    if (input >= 0 && input <= numSavedProfiles) {
        actualPlayer = savedPlayers[input];
        currActiveProfile = input;
    }

    return actualPlayer;
}

int FileManager::SavePlayer(Player toSave) {
    Player savedPlayers[numSavedProfiles];
    LoadPlayers(savedPlayers);
    ofstream outfile ("save.dat");

    for (int i = 0; i < numSavedProfiles; i++) {
        // If active profile, save that, instead
        if (i == currActiveProfile) {
            outfile << toSave.ToFile();
        }
        else {
            outfile << savedPlayers[i].ToFile();
        }
    }

    outfile.close();
}



#endif
