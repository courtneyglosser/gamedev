// player.h
// player class
#include <iostream>

using namespace std;


class Player {
    private:
        string name;
        int xp, hitPoints;

    public:
        Player () {
        }

        Player (string inname, int inxp, int inhitPoints) {
            name = inname;
            xp = inxp;
            hitPoints = inhitPoints;
        }

        void loadPlayer (string inname, int inxp, int inhitPoints) {
            name = inname;
            xp = inxp;
            hitPoints = inhitPoints;
        }

        void toString() {
            cout << "Name:  " << name << endl;
            cout << "================" << endl;
            cout << "XP:  " << xp << endl;
            cout << "Hit Points:  " << hitPoints << endl;
        }
};
