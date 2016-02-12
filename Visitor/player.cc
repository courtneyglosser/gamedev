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
        int maxHP;              // Total Hit Points
        int hitPoints;          // Current Hit Points
        int minAttack;          // Lower bound for randomized damage range
        int maxAttack;          // Upper bound for randomized damage range
        int toHit;              // Percentile _above_ which is a miss.


    public:
        // Empty constructor
        Player () {
            name = "";
        }

        // Constructor with data
        Player (string inname, int inxp, int inhitPoints) {
            name = inname;
            xp = inxp;
            hitPoints = inhitPoints;
            minAttack = 0;
            maxAttack = 10;
            toHit = 75;
        }

        // Getters
        string GetName() { return name; }
        int GetXp()  { return xp; }
        int GetHP()  { return hitPoints; }
        int GetMaxHP () { return maxHP; }
        string GetCurrHP () {

            std::stringstream ss;
            ss << hitPoints << "/" << maxHP;
            string characterHP = ss.str(); 

            return characterHP;

        }

        string GetCurrXP () {

            std::stringstream ss;
            ss << xp << "/" << "Next Level";
            string characterXP = ss.str(); 

            return characterXP;

        }

        // Load in a new player
        void LoadPlayer (string inname, int inxp, int inhitPoints) {
            name = inname;
            xp = inxp;
            hitPoints = inhitPoints;
            maxHP = inhitPoints;
            minAttack = 0;
            maxAttack = 10;
            toHit = 75;
        }

        // gain experience for stuff
        void Learn(int addXp) {
            xp += addXp;
        }

        // Display for Player Character
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
            
            oss << name << " " << xp << " " << hitPoints << " " << maxHP << " "
                << minAttack << " " << maxAttack << " " << toHit << "\n";
    
            rtn = oss.str();

            return rtn;
        }


        // Pull the player data in from the file.  Assumed a strict format
        void FromFile(string fileLine) {
            // Initiate the stringstream
            stringstream ss;
            // Stream in the string from the file.
            ss << fileLine;
            // Parse out the space delimited values into private data members
            ss >> name >> xp >> hitPoints >> maxHP >> minAttack >> maxAttack >> toHit;
        }

        // Reduce HP appropriate amount
        void TakeDamage(int damage) {
            hitPoints -= damage;
        }

        // Calculate and return appropriate attack damage.
        // TODO:  Need to calculate chance to hit, as well.
        int Attack() {
            cout << "Attacking function = maxAttack = " << maxAttack << endl;
            return maxAttack;
        }
};

#endif
