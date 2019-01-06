#include "WinDow.h"

#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include<iostream>
#include<string>

void WinDow::CreateWindow() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("Unable to initialize SDL %s\n", SDL_GetError());
		return ;
	}
 
	
	if (TTF_Init() < 0)
	{
		SDL_Log("%s", TTF_GetError());
		return ;
	}
 
	
	window = SDL_CreateWindow("What's your name", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		printf("Could not create window %s", SDL_GetError());
		return ;
	}
}

/*SDL_Renderer* WinDow::CreateRen() {
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr)
	{
		printf("Could not create render %s", SDL_GetError());
		return ;
	}

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    return renderer;
}*/

void WinDow::Quit() {
    SDL_DestroyWindow(window);
	
	SDL_DestroyRenderer(renderer);
}