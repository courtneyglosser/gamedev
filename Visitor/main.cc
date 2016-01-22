
#include <iostream>
#include "player.cc"
#include "save_file.cc"
#include "game_manager.cc"
#include "monster.cc"

using namespace std;

int main () {
    Player loadedPlayer;
    SaveFile fileManager;
    GameManager game;
    
    Monster badGuy("Kobold", 3, 15);

    game.Init();

    fileManager.DefNumSavedProfiles();

    loadedPlayer = game.HandleAction(fileManager);

    // XP for loading the character
    loadedPlayer.Learn(2);

    loadedPlayer.ToString();
    badGuy.ToString();

    game.ResolveAttack(loadedPlayer, badGuy);

    fileManager.SavePlayer(loadedPlayer);

    return game.Exit();
}

