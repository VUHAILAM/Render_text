#ifndef WINDOW_H
#define WINDOW_H


#include <SDL2/SDL_events.h>
#include<string>
class SDL_Window;
class SDL_Renderer;
class SDL_Texture;

class WinDow {
    public:
        //RenText();
        //virtual ~RenText();
        void CreateWindow();
        SDL_Renderer* CreateRen();
        void Quit();
    private:
        SDL_Window* window = nullptr;
	    SDL_Renderer* renderer = nullptr;
        SDL_Surface* surface = nullptr;
	    SDL_Texture* texture = nullptr;
        SDL_Event mainEvent;
};
#endif