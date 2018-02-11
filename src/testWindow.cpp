#include "testWindow.hpp"

testWindow::testWindow()
{
    gwindow = NULL;
    gsurface = NULL;
    ghelloWorld = NULL;
    createdWindow = true;
    SCREEN_WIDTH = 640;
    SCREEN_HEIGHT = 480;
}

testWindow::~testWindow()
{
    close();
}

bool testWindow::initWindow()
{
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
        gwindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gwindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            gsurface = SDL_GetWindowSurface( gwindow );
        }
    }

    return success;
}

bool testWindow::loadMedia()
{
        //Loading success flag
    bool success = true;

    //Load splash image
    ghelloWorld = SDL_LoadBMP( "flower.bmp" );
    if( ghelloWorld == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "flower.bmp", SDL_GetError() );
        success = false;
    }

    return success;
}

void testWindow::close()
{
        //Deallocate surface
    SDL_FreeSurface( ghelloWorld );
    ghelloWorld = NULL;

    //Destroy window
    SDL_DestroyWindow( gwindow );
    gwindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}

void testWindow::start()
{
    
    if( !initWindow() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
            bool quit = false;
            while(!quit){
                while( SDL_PollEvent( &e ) != 0 ){
					//User requests quit
					if( e.type == SDL_QUIT ){
						quit = true;
					}
				}
                //Apply the image
                SDL_BlitSurface( ghelloWorld, NULL, gsurface, NULL );
                //Update the surface
                SDL_UpdateWindowSurface( gwindow );
            }
        }
    }
}