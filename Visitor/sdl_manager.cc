// sdl_manager.cc
// SDLManager class

#ifndef __SDL_MANAGER_CC_INCLUDED__
#define __SDL_MANAGER_CC_INCLUDED__


#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "player.cc"
#include "save_file.cc"
#include "monster.cc"

using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class SDLManager {
    private:

    public:
        // Empty constructor
        SDLManager () {
        }

        void Init();
 
        int Exit ();

};  // End SDLManager



void SDLManager::Init() {
    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;
        
    //The surface contained by the window
    SDL_Surface* gScreenSurface = NULL;

    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }


    // Initialize SDL_ttf library
    if (TTF_Init() != 0)
    {
        cerr << "TTF_Init() Failed: " << TTF_GetError() << endl;
        SDL_Quit();
        exit(1);
    }


    // Load a font
    TTF_Font *font;
    font = TTF_OpenFont("FreeSans.ttf", 18);
    if (font == NULL)
    {
        cerr << "TTF_OpenFont() Failed: " << TTF_GetError() << endl;
        TTF_Quit();
        SDL_Quit();
        exit(1);
    }

    // Write text to surface
    SDL_Surface *text;
    SDL_Color text_color = {255, 255, 255};
    SDL_Color bg_color = {0, 0, 0};
    SDL_Rect text_location = {(SCREEN_WIDTH - 150), 10, 0, 0};
//    text = TTF_RenderText_Solid(font, "A journey of a thousand miles begins with a single step.  More text!!", text_color);
    
    text = TTF_RenderText_Shaded(font, "Character name", text_color, bg_color);

    if (text == NULL)
    {
        cerr << "TTF_RenderText_Solid() Failed: " << TTF_GetError() << endl;
        TTF_Quit();
        SDL_Quit();
        exit(1);
    }

    if (SDL_BlitSurface(text, NULL, gScreenSurface, &text_location) != 0)
    {
        cerr << "SDL_BlitSurface() Failed: " << SDL_GetError() << endl;
    }

    SDL_Rect text_location2 = {(SCREEN_WIDTH - 150), 40, 0, 0};
    text = TTF_RenderText_Shaded(font, "Character HP", text_color, bg_color);
    if (SDL_BlitSurface(text, NULL, gScreenSurface, &text_location2) != 0)
    {
        cerr << "SDL_BlitSurface() Failed: " << SDL_GetError() << endl;
    }

    SDL_UpdateWindowSurface ( gWindow );


    SDL_Delay(5000);

    //Deallocate surface
    SDL_FreeSurface( gScreenSurface );
    gScreenSurface = NULL;

    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    // Release font
    TTF_CloseFont(font);
    font = NULL;

    //Quit SDL subsystems
    TTF_Quit();
    SDL_Quit();

}

int SDLManager::Exit() {}


#endif
