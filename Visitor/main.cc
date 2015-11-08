
#include <iostream>
#include "player.cc"
#include "save_file.cc"
#include "game_manager.cc"

using namespace std;

int main () {
    Player loadedPlayer;
    SaveFile fileManager;
    GameManager game;

    game.Init();

    fileManager.DefNumSavedProfiles();

    loadedPlayer = game.HandleAction(fileManager);

    loadedPlayer.ToString();

    // XP for loading the character
    loadedPlayer.Learn(2);

    fileManager.SavePlayer(loadedPlayer);

    return game.Exit();
}

