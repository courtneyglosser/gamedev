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
        int minAttack;          // Guaranteed minimum damage, on successful hit
        int maxAttack;          // Maximum attack damage possible


    public:
        // Empty constructor
        Monster () {
        }

        // Normal constructor
        Monster (string inname, int inxp, int inhitPoints) {
            name = inname;
            xp = inxp;
            hitPoints = inhitPoints;
            maxAttack = 2;
        }

        // Couple simple getters.
        string GetName() { return name; }
        int GetXp()  { return xp; }
        int GetHitPoints() { return hitPoints; }

        // Load in specific monster data.
        void LoadMonster (string inname, int inxp, int inhitPoints) {
            name = inname;
            xp = inxp;
            hitPoints = inhitPoints;
        }

        // Display for monster
        void ToString() {
            cout << "Name:  " << name << endl;
            cout << "================" << endl;
            cout << "XP:  " << xp << endl;
            cout << "Hit Points:  " << hitPoints << endl;
        }

        // Receive damage and reduce current hit points.
        void TakeDamage(int damage) {
            hitPoints -= damage;
        }
        
        // Calculate and return attack total
        // TODO:  Will eventually have to figure out chance to hit
        int Attack() {
            cout << "Attacking function = maxAttack = " << maxAttack << endl;
            return maxAttack;
        }
};

#endif
