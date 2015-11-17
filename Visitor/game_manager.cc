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

            if (nextAction == '1') {
                cout << "Brand new game!" << endl;
                cout << "Enter your name:  ";
                cin >> name;

                actualPlayer.LoadPlayer(name, 0, 10);
                fileManager.AddNewProfile();
            }
            else if (nextAction == '2') {
                cout << "Loading an existing game!" << endl;

                //Declare array of savedPlayers
                Player savedPlayers[fileManager.GetNumSavedProfiles()];

                //Done.  Now, load players
                fileManager.LoadPlayers(savedPlayers);

                actualPlayer = fileManager.SelectPlayer(savedPlayers);
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
        }

};

#endif
