// monster.cc
// Monster class

#ifndef __MONSTER_CC_INCLUDED__
#define __MONSTER_CC_INCLUDED__

#include <iostream>
#include <sstream>

using namespace std;


class Monster {
    private:
        string name;            // Player's name
        int xp;                 // Experience
        int hitPoints;          // Hit Points


    public:
        Monster () {
        }

        Monster (string inname, int inxp, int inhitPoints) {
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
};

#endif
