#ifndef TESTWINDOW_HPP
#define TESTWINDOW_HPP

#include "SDL.h"
#include <stdio.h>

class testWindow
{
    public:
        testWindow();
        ~testWindow(){}
        bool initWindow();
        bool loadMedia();
        void close();
        void start();

    private:
        SDL_Window * gwindow;
        SDL_Surface * gsurface;
        SDL_Surface * ghelloWorld;

        bool createdWindow;
        int SCREEN_WIDTH;
        int SCREEN_HEIGHT;
};

#endif