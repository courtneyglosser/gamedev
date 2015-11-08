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
        }

        void DefNumSavedProfiles() {
            infile.open("save.dat");
            int lineCount = 0;
            string nameFromFile = "";
            int fileXp = 0;

            if (infile.is_open() ) {
                // each line represents a save file?
                while (infile >> nameFromFile >> fileXp) {
                    ++lineCount;
                }
            }

            numSavedProfiles = lineCount;

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
            string nameFromFile = "";
            int fileXp, fileHitPoints, selPlayer;
            Player actualPlayer;

            if (infile.is_open() ) {
                if (numSavedProfiles > 0) {
                    lineCount = 0;

                    while (infile >> nameFromFile >> fileXp) {
                        savedPlayers[lineCount].LoadPlayer(nameFromFile, fileXp, 0);
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
                    outfile << toSave.GetName() << " " << toSave.getXp() <<
"\n";
                }
                else {
                    outfile << savedPlayers[i].GetName() << " " <<
savedPlayers[i].getXp() << "\n";
                }
            }

            outfile.close();
        }

};

#endif
