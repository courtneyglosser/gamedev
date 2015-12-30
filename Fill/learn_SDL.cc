/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include "game_manager.cc"


// Main
int main( int argc, char* args[] )
{
    GameManager* myGame = new GameManager();
    
    if (!myGame->init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        if (!myGame->loadMedia())
        {
            printf("Failed to load media!\n");
        }
        else
        {
            //Main loop flag
            bool quit = false;

            //Event handler
            SDL_Event e;

            //Set default current surface
            myGame->gCurrentSurface = myGame->gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
            SDL_BlitSurface( myGame->gCurrentSurface, NULL, myGame->gScreenSurface, NULL);
            SDL_UpdateWindowSurface ( myGame->gWindow );

            //While application is running
            while( !quit ) {

                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    printf("Received Input \n ");
                    //User requests quit
                    if( e.type == SDL_QUIT )
                    {
                        quit = true;
                    }
                    else if (e.type == SDL_KEYDOWN)
                    {

                        switch(e.key.keysym.sym)
                        {

                            case SDLK_UP:
                                myGame->gCurrentSurface = myGame->gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ];
                                break;

                            case SDLK_DOWN:
                                myGame->gCurrentSurface = myGame->gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ];
                                break;

                            case SDLK_LEFT:
                                myGame->gCurrentSurface = myGame->gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ];
                                break;

                            case SDLK_RIGHT:
                                myGame->gCurrentSurface = myGame->gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ];
                                break;

                            case SDLK_q:
                            case SDLK_ESCAPE:
                                quit = true;
                                break;

                            default:
                                myGame->gCurrentSurface = myGame->gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ];
                                break;

                        }
                        SDL_BlitSurface( myGame->gCurrentSurface, NULL, myGame->gScreenSurface, NULL);

                        SDL_UpdateWindowSurface ( myGame->gWindow );
                    }
                }
            }
        }
    }

    myGame->close();

	return 0;
}

