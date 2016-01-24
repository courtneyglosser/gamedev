
//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "player.cc"
#include "game_manager.cc"
#include "monster.cc"

using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char* args[] )
{
    Player loadedPlayer;  // Our hero
    GameManager game;     // Our game

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
    font = TTF_OpenFont("FreeSans.ttf", 24);
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
    text = TTF_RenderText_Solid(font, "A journey of a thousand miles begins with a single step.", text_color);

    if (text == NULL)
    {
        cerr << "TTF_RenderText_Solid() Failed: " << TTF_GetError() << endl;
        TTF_Quit();
        SDL_Quit();
        exit(1);
    }

    if (SDL_BlitSurface(text, NULL, gScreenSurface, NULL) != 0)
    {
        cerr << "SDL_BlitSurface() Failed: " << SDL_GetError() << endl;
    }

    SDL_UpdateWindowSurface ( gWindow );


    SDL_Delay(1000);

    //Deallocate surface
    SDL_FreeSurface( gScreenSurface );
    gScreenSurface = NULL;

    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();












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

    // Save the player and close out gracefully
    return game.Exit(loadedPlayer);
}

