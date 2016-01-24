// game_manager.cc
// GameManager class

#ifndef __GAME_MANAGER_CC_INCLUDED__
#define __GAME_MANAGER_CC_INCLUDED__


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

class GameManager {
    private:
        SaveFile fileManager;           // Manage players saved file state

    public:
        // Empty constructor
        GameManager () {
        }

        // Initialize the game.  Here, just presents a welcome menu.  Options
        // are simply "New Character" or "Load a Saved Game"
        void Init() {
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








            cout << "Welcome" << endl;
            cout << "Press 1 for a new game" << endl;
            cout << "Press 2 to load a saved game" << endl;
            cout << "Press any other key to exit" << endl;
            // TODO:  Add more options? -> Development tools?
        }

        // If a new game, create character and return it as a Player objects.
        // Otherwise, present the user with existing character options read in
        // from file.
        Player SelectPlayer () {
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

        // Close out the game, save state and return appropriate exit code.
        int Exit (Player loadedPlayer) {
            // Save player before exiting.
            fileManager.SavePlayer(loadedPlayer);

            cout << "Exit, you shall!" << endl;

            return 0;
        }

        //  Handling combat.  Allowing a specific back and forth attack.
        //  Probably eventually want a combat-specific class, while allowing
        //  GameManager to focus on more fundamental gameplay management needs.
        void ResolveAttack(Player &loadedPlayer, Monster badGuy) {
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

};

#endif
