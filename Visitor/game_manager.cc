// game_manager.cc
// GameManager class

#ifndef __GAME_MANAGER_CC_INCLUDED__
#define __GAME_MANAGER_CC_INCLUDED__


#include <iostream>
#include "player.cc"
#include "save_file.cc"
#include "monster.cc"

using namespace std;


class GameManager {
    private:

    public:
        GameManager () {
        }

        void Init() {
            cout << "Welcome" << endl;
            cout << "Press 1 for a new game" << endl;
            cout << "Press 2 to load a saved game" << endl;
            cout << "Press any other key to exit" << endl;
        }

        Player HandleAction (SaveFile &fileManager) {
            char nextAction = '0';
            string name = "";
            Player actualPlayer;

            cin >> nextAction;

            if (nextAction == '2') {
                cout << "Loading an existing game!" << endl;

		//ensure saved there is a save file
		if (fileManager.GetNumSavedProfiles() > 0 ) {

			//Declare array of savedPlayers
			Player savedPlayers[fileManager.GetNumSavedProfiles()];

			//Done.  Now, load players
			fileManager.LoadPlayers(savedPlayers);

			actualPlayer = fileManager.SelectPlayer(savedPlayers);
		} else {
			cout << "There are currently no saved profiles to load" << endl;
			nextAction = '1';
		}
            }
            if (nextAction == '1') {
                cout << "Brand new game!" << endl;
                cout << "Enter your name:  ";
                cin >> name;

                actualPlayer.LoadPlayer(name, 0, 10);
                fileManager.AddNewProfile();
            }

            return actualPlayer;
        }

        int Exit () {

            cout << "Exit, you shall!" << endl;

            return 0;
        }

        void ResolveAttack(Player &loadedPlayer, Monster badGuy) {
            cout << loadedPlayer.GetName() << " is attacking! " << endl;
            int damage = loadedPlayer.Attack();
            cout << badGuy.GetName() << " is going to take " << damage << endl;
            badGuy.TakeDamage(damage);
            cout << badGuy.GetName() << " has " << badGuy.GetHitPoints() << endl;
            if (badGuy.GetHitPoints() <= 0) {
                cout << "Monster is dead!!" << endl;
                cout << loadedPlayer.GetName() << " receives "
                     << badGuy.GetXp() << endl;
                loadedPlayer.Learn(badGuy.GetXp());
            }
        }

};

#endif
