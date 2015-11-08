// player.cc
// Player class

#ifndef __PLAYER_CC_INCLUDED__
#define __PLAYER_CC_INCLUDED__


#include <iostream>

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
        int getXp()  { return xp; }

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
};

#endif
