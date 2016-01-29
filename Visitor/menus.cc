// menus.cc
// Menus class

#ifndef __MENUS_CC_INCLUDED__
#define __MENUS_CC_INCLUDED__


#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

class Menus {
    private:

    public:
        // Empty constructor
        Menus () {
        }

        int WelcomeInput();


};  // End Menus


int Menus::WelcomeInput() {
    cout << "How can I Retrieve the SDL input here?" << endl;
}

#endif
