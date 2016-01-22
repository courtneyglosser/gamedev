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
        int currActiveProfile;

    public:
        SaveFile () {
            DefNumSavedProfiles();
        }

        void DefNumSavedProfiles() {
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

        int GetNumSavedProfiles () {
            return numSavedProfiles;
        }

        void AddNewProfile() {
            currActiveProfile = numSavedProfiles;
            numSavedProfiles++;
        }

        void LoadPlayers (Player savedPlayers[]) {
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

        Player SelectPlayer(Player savedPlayers[]) {
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

        int SavePlayer(Player toSave) {
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

};

#endif
