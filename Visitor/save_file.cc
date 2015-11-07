// save_file.cc
// SaveFile class
#include <iostream>
#include <fstream>
#include "player.cc"

#ifndef __SAVE_FILE_CC_INCLUDED__
#define __SAVE_FILE_CC_INCLUDED__

using namespace std;


class SaveFile {
    private:
        ifstream infile;
        ofstream outfile;
        int numSavedProfiles;


        void defNumSavedProfiles() {
            int lineCount = 0;
            string nameFromFile = "";
            int fileXp = 0;

            if (infile.is_open() ) {
                // Validate file, and determine how many save slots are used.
                while (infile >> nameFromFile >> fileXp) {
                    if (!nameFromFile.empty() && fileXp>-1) {
                        ++lineCount;
                    }
                }
            }

            numSavedProfiles = lineCount;

            // Clear the file EOF flag.
            infile.clear();
            // Reset cursor to beginning of file
            infile.seekg(0, ios::beg);
        }

    public:
        SaveFile () {
            infile.open("save.dat");
            defNumSavedProfiles();
        }

        int getNumSavedProfiles () {
            return numSavedProfiles;
        }
    

        void loadPlayers (Player savedPlayers[]) {
            int lineCount = 0;
            string nameFromFile = "";
            int fileXp, fileHitPoints, selPlayer;
            Player actualPlayer;

            if (infile.is_open() ) {
                if (numSavedProfiles > 0) {
                    lineCount = 0;

                    while (infile >> nameFromFile >> fileXp) {
                        savedPlayers[lineCount].loadPlayer(nameFromFile, fileXp, 0);
                        lineCount++;
                    }

                }
                infile.close();
            }

        }

        Player selectPlayer(Player savedPlayers[]) {
            Player actualPlayer;
            char selPlayer;
            int input;

            for (int i = 0; i < numSavedProfiles; i++) {
                cout << "Press " << i+1 << " for this player: " << endl;
                cout << "======================== " << endl;
                savedPlayers[i].toString();
                cout << endl;
            }

            cin >> selPlayer;
            // Convert char input to integer for boolean check
            input = selPlayer - '0';
            input--;
            if (input >= 0 && input <= numSavedProfiles) {
                actualPlayer = savedPlayers[input];
            }

            return actualPlayer;
        }

};

#endif
