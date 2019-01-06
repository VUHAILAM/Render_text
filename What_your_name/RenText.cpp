#include "RenText.h"

#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include<iostream>
#include<string>


void RenText::CreateWindow() {
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

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr)
	{
		printf("Could not create render %s", SDL_GetError());
		return ;
	}

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}

void RenText::RenderText(std::string text,int x, int y) {
	
	TTF_Font* font = TTF_OpenFont("arial.ttf", 30);
 
	SDL_Color fg = { 0, 0, 0 };
	surface = TTF_RenderText_Solid(font, text.c_str(), fg);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
 
	SDL_Rect srcRest;
	SDL_Rect desRect;
	TTF_SizeText(font, text.c_str(), &srcRest.w, &srcRest.h);
	
	srcRest.x = 0;
	srcRest.y =  0;
 
	desRect.x = x;
	desRect.y = y;
 
	desRect.w = srcRest.w;
	desRect.h = srcRest.h;
	
	SDL_RenderClear(renderer);
	
	SDL_RenderCopy(renderer, texture, &srcRest, &desRect);
		
	SDL_RenderPresent(renderer);
}

void RenText::Quit() {
	
	SDL_DestroyWindow(window);
	
	SDL_DestroyRenderer(renderer);
	
	TTF_Quit();
	
	
}

