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
        Player svedPlayers[5];

    public:
        SaveFile () {
        }

};

#endif
