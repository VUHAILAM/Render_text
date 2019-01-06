#include"RenText.h"
//#include "WinDow.h"

#include<SDL2/SDL.h>
#include<SDL2/SDL_ttf.h>
#include<iostream>
#include<string>

#define main SDL_main



int main(int argv, char** args) {
	SDL_Event mainEvent;
	std::string tex = "";
	//WinDow* win = new WinDow;
	//win->CreateWindow();
	//SDL_Renderer* renderer = win->CreateRen();
	RenText* a = new RenText;
	//RenText* b = new RenText;
	a->CreateWindow();
	bool isRunning = true;
	while (isRunning)
	{
		a->RenderText("What's your name??",200, 200);
		
		while (SDL_PollEvent(&mainEvent))
		{
			if(mainEvent.type == SDL_QUIT) {
				isRunning = false;
				break;
			} else if(mainEvent.type == SDL_TEXTINPUT || mainEvent.type == SDL_KEYDOWN) {
				
				if(mainEvent.type == SDL_TEXTINPUT) {
					tex += mainEvent.text.text;
					
				}
				else if(mainEvent.key.keysym.sym == SDLK_BACKSPACE && tex.length() > 0) {
					tex = tex.substr(0,tex.length()-1);
					
				} else if(mainEvent.key.keysym.sym == SDLK_KP_ENTER && tex.length() > 0) {
						
				}
				
			} else {
				
				break;

			}
			
			
		}
		//a->RenderText(tex,200,300);
		a->RenderText("My name is " + tex, 200, 400);
	}
	
	SDL_StopTextInput();
	a->Quit();
	
	//win->Quit();
	SDL_Quit();
    return 0;
}