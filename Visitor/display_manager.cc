// display_manager.cc
// DisplayManager class

#ifndef __DISPLAY_MANAGER_CC_INCLUDED__
#define __DISPLAY_MANAGER_CC_INCLUDED__


#include <iostream>
#include <sstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "player.cc"
#include "monster.cc"

using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

class DisplayManager {
    private:
        SDL_Window* gWindow = NULL;         // The window we'll be rendering to
        SDL_Surface* gScreenSurface = NULL; // The surface contained by the window
        SDL_Surface* gBlankSurface = NULL;  // Maintain a blank surface to clear the screen
        TTF_Font *font;                     // Load font for text output
        TTF_Font *titleFont;                // Load font for title text
        SDL_Color bg_color;                 // Window's background color

    public:
        // Empty constructor
        DisplayManager () {
        }

        void Init();

        void DisplayWelcome();
        void DisplayPlayers(Player savedPlayers[], int numSavedProfiles);

        void DisplayCharacter(Player loadedPlayer);
        void DisplayText(string text, SDL_Color color, SDL_Rect location, TTF_Font *useFont); 

        void DisplayWipe();

        int Exit ();

};  // End DisplayManager

void DisplayManager::Init() {
    // TODO:  Some day may be worth extra credit to allow option to adjust
    bg_color.r = 0;
    bg_color.b = 0;
    bg_color.g = 0;
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        cout << "SDL could not initialize! SDL_Error: " <<  SDL_GetError() << endl;
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
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


    font = TTF_OpenFont("FreeSans.ttf", 18);
    titleFont = TTF_OpenFont("FreeSans.ttf", 24);
    
    if (font == NULL || titleFont == NULL)
    {
        cerr << "TTF_OpenFont() Failed: " << TTF_GetError() << endl;
        TTF_Quit();
        SDL_Quit();
        exit(1);
    }

}


void DisplayManager::DisplayWelcome() {
    SDL_Color text_color = {255, 255, 255};
    SDL_Rect text_location = {(SCREEN_WIDTH/2) - 50, 10, 0, 0};
    DisplayText("Welcome, Visitor", text_color, text_location, titleFont);
    SDL_UpdateWindowSurface ( gWindow );

    SDL_Rect new_char_location = {(SCREEN_WIDTH/2) - 50, 150, 0, 0};
    DisplayText("Press 1 to start a new character", text_color, new_char_location, titleFont);
    SDL_UpdateWindowSurface ( gWindow );

    SDL_Rect load_char_location = {(SCREEN_WIDTH/2) - 50, 190, 0, 0};
    DisplayText("Press 2 to load an existing character", text_color, load_char_location, titleFont);
    SDL_UpdateWindowSurface ( gWindow );

}

void DisplayManager::DisplayPlayers(Player savedPlayers[], int numSavedProfiles) {
    SDL_Color text_color = {255, 255, 255};
    SDL_Rect text_location = {(SCREEN_WIDTH/2) - 50, 10, 0, 0};
    DisplayText("Select a Saved Game", text_color, text_location, titleFont);
    SDL_UpdateWindowSurface ( gWindow );

    for (int i = 0; i < numSavedProfiles; i++) {
        int playerNum = i+1;
        std::stringstream ss;
        ss << playerNum;
        string displayPlayerNum = ss.str();

        SDL_Rect number_location = {10, 100*(i+1)-5, 0, 0};
        DisplayText(displayPlayerNum, text_color, number_location, titleFont);
        SDL_UpdateWindowSurface( gWindow );
   
        SDL_Rect player_location = {35, 100*(i+1), 0, 0};
        DisplayText(savedPlayers[i].GetName(), text_color, player_location, font);
        SDL_UpdateWindowSurface( gWindow );
   
        SDL_Rect hp_location = {150, 100*(i+1), 0, 0};
        DisplayText(savedPlayers[i].GetCurrHP(), text_color, hp_location, font);
        SDL_UpdateWindowSurface( gWindow );
    }
}

void DisplayManager::DisplayCharacter(Player player) {
    // Write text to surface
    SDL_Surface *text;
    SDL_Color text_color = {255, 255, 255};
    SDL_Rect text_location = {(SCREEN_WIDTH - 150), 10, 0, 0};
    string characterName = player.GetName();
    string characterHP = player.GetCurrHP();

    DisplayText(characterName, text_color, text_location, font); 

    SDL_Rect text_location2 = {(SCREEN_WIDTH - 150), 40, 0, 0};

    DisplayText(characterHP, text_color, text_location2, font);

    SDL_UpdateWindowSurface ( gWindow );

}

void DisplayManager::DisplayText(string displayStr, SDL_Color color, SDL_Rect location, TTF_Font *useFont) {
    SDL_Surface *text;
    
    // Note:  c_str to support char * casting necessary in SDL call
    text = TTF_RenderText_Shaded(useFont, displayStr.c_str(), color, bg_color);

    if (text == NULL)
    {
        cerr << "TTF_RenderText_Solid() Failed: " << TTF_GetError() << endl;
        TTF_Quit();
        SDL_Quit();
        exit(1);
    }

    if (SDL_BlitSurface(text, NULL, gScreenSurface, &location) != 0)
    {
        cerr << "SDL_BlitSurface() Failed: " << SDL_GetError() << endl;
    }

}

void DisplayManager::DisplayWipe() {
    // TODO:  Set up a function to convert SDL_Color to Unit32 color for this
    SDL_FillRect(gScreenSurface, NULL, 0x000000); 
    SDL_UpdateWindowSurface ( gWindow );
}

int DisplayManager::Exit() {

    SDL_Delay(1000);

    //Deallocate surface
    SDL_FreeSurface( gScreenSurface );
    gScreenSurface = NULL;

    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    // Release font
    TTF_CloseFont(font);
    font = NULL;
    TTF_CloseFont(titleFont);
    titleFont = NULL;

    //Quit SDL subsystems
    TTF_Quit();
    SDL_Quit();

}

#endif
