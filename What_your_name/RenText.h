#ifndef RENTEXT_H
#define RENTEXT_H


#include <SDL2/SDL_events.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include<iostream>
#include<string>
class SDL_Window;
class SDL_Renderer;
class SDL_Texture;

class RenText {
    public:
        //RenText();
        //virtual ~RenText();
        void CreateWindow();
        void RenderText(std::string text, int x, int y);
        void ClearRender();
        void RenderPresent();
        void Quit();
    private:
        SDL_Window* window = nullptr;
	    SDL_Renderer* renderer = nullptr;
        SDL_Surface* surface = nullptr;
	    SDL_Texture* texture = nullptr;
        SDL_Event mainEvent;
};
#endif