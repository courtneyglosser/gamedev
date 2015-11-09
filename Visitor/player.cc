// player.cc
// Player class

#ifndef __PLAYER_CC_INCLUDED__
#define __PLAYER_CC_INCLUDED__

#include <iostream>
#include <sstream>

using namespace std;


class Player {
    private:
        string name;            // Player's name
        int xp;                 // Experience
        int hitPoints;          // Hit Points


    public:
        Player () {
        }

        Player (string inname, int inxp, int inhitPoints) {
            name = inname;
            xp = inxp;
            hitPoints = inhitPoints;
        }

        string GetName() { return name; }
        int GetXp()  { return xp; }

        void LoadPlayer (string inname, int inxp, int inhitPoints) {
            name = inname;
            xp = inxp;
            hitPoints = inhitPoints;
        }

        void Learn(int addXp) {
            xp += addXp;
        }

        void ToString() {
            cout << "Name:  " << name << endl;
            cout << "================" << endl;
            cout << "XP:  " << xp << endl;
            cout << "Hit Points:  " << hitPoints << endl;
        }

        /**
         * Format the player's information for writing out to file.
         *
         * Returns a string formatted to be written to file.
         */
        string ToFile() {
            string rtn; // String to capture player info.
            // http://stackoverflow.com/questions/64782/how-do-you-append-an-int-to-a-string-in-c
            // Super helpful link on integer string concatenation
            ostringstream oss;
            
            oss << name << " " << xp << " " << hitPoints << "\n";
    
            rtn = oss.str();

            return rtn;
        }

        void FromFile(string fileLine) {
            // Initiate the stringstream
            stringstream ss;
            // Stream in the string from the file.
            ss << fileLine;
            // Parse out the space delimited values into private data members
            ss >> name >> xp >> hitPoints;
        }
};

#endif
