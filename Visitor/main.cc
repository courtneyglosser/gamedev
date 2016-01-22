
#include <iostream>
#include "player.cc"
#include "game_manager.cc"
#include "monster.cc"

using namespace std;

int main () {
    Player loadedPlayer;
    GameManager game;

    // #TODO:  Eventually pull this out of main all-together
    // #TODO:  Pull monsters from file as needed.
    Monster badGuy("Kobold", 3, 15);

    // Initialize - print out "Welcome screen" options
    game.Init();

    // Load in either a new player, or select from save file
    loadedPlayer = game.SelectPlayer();

    // XP for loading the character
    loadedPlayer.Learn(2);

    // Spit out player details
    loadedPlayer.ToString();

    // Spit out monster details
    badGuy.ToString();

    // Execute a single attack
    game.ResolveAttack(loadedPlayer, badGuy);

    return game.Exit(loadedPlayer);
}

