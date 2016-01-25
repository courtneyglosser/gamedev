// game_manager.cc
// GameManager class

#ifndef __GAME_MANAGER_CC_INCLUDED__
#define __GAME_MANAGER_CC_INCLUDED__


#include <iostream>
#include "sdl_manager.cc"
#include "player.cc"
#include "save_file.cc"
#include "monster.cc"

using namespace std;

class GameManager {
    private:
        SaveFile fileManager;           // Manage players saved file state
        SDLManager display;

    public:
        // Empty constructor
        GameManager () {
        }

        // Initialize the game.  Here, just presents a welcome menu.  Options
        // are simply "New Character" or "Load a Saved Game"
        void Init();
 
        // If a new game, create character and return it as a Player objects.
        // Otherwise, present the user with existing character options read in
        // from file.
        Player SelectPlayer ();

        void DisplayPlayer(Player loadedPlayer);
 
        // Close out the game, save state and return appropriate exit code.
        int Exit (Player loadedPlayer);

        //  Handling combat.  Allowing a specific back and forth attack.
        //  Probably eventually want a combat-specific class, while allowing
        //  GameManager to focus on more fundamental gameplay management needs.
        void ResolveAttack(Player &loadedPlayer, Monster badGuy);

};  // End GameManager



void GameManager::Init() {
    display.Init();



    cout << "Welcome" << endl;
    cout << "Press 1 for a new game" << endl;
    cout << "Press 2 to load a saved game" << endl;
    cout << "Press any other key to exit" << endl;
    // TODO:  Add more options? -> Development tools?
}

Player GameManager::SelectPlayer() {
    char nextAction = '0';      // Initializing action
    Player actualPlayer;        // Return value for player

    cin >> nextAction;          // Retrieve user entered input

    if (nextAction == '2') {
        cout << "Loading an existing game!" << endl;

        //ensure saved there is a save file
        if (fileManager.GetNumSavedProfiles() > 0 ) {

            //Declare array of savedPlayers
            Player savedPlayers[fileManager.GetNumSavedProfiles()];

            //Done.  Now, load players
            fileManager.LoadPlayers(savedPlayers);

            // Present the user with existing player options for
            // selection.
            actualPlayer = fileManager.SelectPlayer(savedPlayers);
        } else {
            // Save.dat is empty or doesn't exist.  Must create a new
            // character.  Set nextAction = '1' to fall through to next
            // if conditional
            cout << "There are currently no saved profiles to load" << endl;
            nextAction = '1';
        }
    }
    if (nextAction == '1') {
        // Create a new Character
        string name = "";           // Name value

        // Get Character Name
        cout << "Brand new game!" << endl;
        cout << "Enter your name:  ";
        cin >> name;

        // Just initialize with simple values.
        // TODO: allow more customization here, eventually.
        actualPlayer.LoadPlayer(name, 0, 10);

        // Total number of profiles available is now larger, so
        // increment and manager this in the fileManager class.
        fileManager.AddNewProfile();
    }

    return actualPlayer;
}

void GameManager::DisplayPlayer(Player player) {
    display.DisplayCharacter(player);
}


int GameManager::Exit(Player loadedPlayer) {
    // Save player before exiting.
    fileManager.SavePlayer(loadedPlayer);

    cout << "Exit, you shall!" << endl;

    display.Exit();

    return 0;
}

void GameManager::ResolveAttack(Player &loadedPlayer, Monster badGuy) {
    // Pull player name for display
    string playerName = loadedPlayer.GetName();
    // Pull monster name for display
    string monsterName = badGuy.GetName();
    // Initial player damage to monster
    int damage = loadedPlayer.Attack();

    // Display attack
    cout << playerName << " is attacking! " << endl;
    cout << monsterName << " is going to take " << damage << endl;
    badGuy.TakeDamage(damage);

    // Result for monster
    int monsterHitPoints = badGuy.GetHitPoints();
    cout << monsterName << " has " << monsterHitPoints << endl;

    if (monsterHitPoints <= 0) {
        cout << "Monster is dead!!" << endl;
        cout << playerName << " receives " << badGuy.GetXp() << endl;
        loadedPlayer.Learn(badGuy.GetXp());
    }
    else {
        int badGuyDamage = badGuy.Attack();
        cout << "Monster is alive!!" << endl;
        cout << "And he's attacking!" << endl;
        cout << playerName << " is going to take " << badGuyDamage
             << endl;
        loadedPlayer.TakeDamage(badGuy.Attack());
    }
}

#endif
