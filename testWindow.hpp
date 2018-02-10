#ifndef TESTWINDOW_HPP
#define TESTWINDOW_HPP

#include "SDL.h"

class testWindow
{
    public:
        testWindow();
        virtual ~testWindow();
        void initWindow();
        void loadMedia();
        void close();

    private:
        SDL_Window * window;
        SDL_Surface * surface;
        SDL_Surface * helloWorld;

        bool createdWindow;
        const int SCREEN_WIDTH;
        const int SCREEN_HEIGHT;
};

#endif