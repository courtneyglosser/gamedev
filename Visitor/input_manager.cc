// input_manager.cc
// InputManager class

#ifndef __INPUT_MANAGER_CC_INCLUDED__
#define __INPUT_MANAGER_CC_INCLUDED__


#include <iostream>
#include <SDL2/SDL.h>
#include "player.cc"

using namespace std;

class InputManager {
    private:

    public:
        // Empty constructor
        InputManager () {
        }

        char WelcomeMenuInput();
        Player SelectPlayer(Player savedPlayers[], int numPlayers);



};  // End InputManager


char InputManager::WelcomeMenuInput() {
    char nextAction = '0';

    bool quit = false;
    SDL_Event e;
    while (!quit) {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            if( e.type == SDL_KEYDOWN )
            {
                //Select surfaces based on key press
                switch( e.key.keysym.sym )
                {
                    case SDLK_1:
                        nextAction = '1';
                    break;

                    case SDLK_2:
                        nextAction = '2';
                    break;
                }
                quit = true;
            }
        }
    }

    return nextAction;
}

Player InputManager::SelectPlayer (Player savedPlayers[], int numPlayers) {
    int keyInput = 0;
    bool quit = false;
    Player rtn;

    SDL_Event e;
    while (!quit) {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            if( e.type == SDL_KEYDOWN )
            {
                //Select surfaces based on key press
                switch( e.key.keysym.sym )
                {
                    case SDLK_1:
                        keyInput = 1;
                    break;

                    case SDLK_2:
                        keyInput = 2;
                    break;
                    
                    case SDLK_3:
                        keyInput = 3;
                    break;

                }
                if (keyInput != 0) {
                    cout << "Got keyInput != 0" << endl;
                    cout << keyInput << endl;
                    quit = true;
                }
            }
        }
    }

    keyInput--;

    if (keyInput < numPlayers)
    {
        cout << "return player:  " << endl;
        cout << keyInput << endl;
        rtn = savedPlayers[keyInput];
        rtn.ToString();
    }

    return rtn;
    
}

#endif
