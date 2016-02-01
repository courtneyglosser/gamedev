// input_manager.cc
// InputManager class

#ifndef __INPUT_MANAGER_CC_INCLUDED__
#define __INPUT_MANAGER_CC_INCLUDED__


#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

class InputManager {
    private:

    public:
        // Empty constructor
        InputManager () {
        }

        char WelcomeMenuInput();


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

#endif
