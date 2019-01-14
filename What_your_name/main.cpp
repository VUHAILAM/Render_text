#include "RendererText.h"



int main(int argc, char** args) {
	SDL_Event mainEvent;
	std::string text = "";
	RendererText* object = new RendererText;
	object->CreateWindow();
	bool isRunning = true;
	bool check = false;
	while (isRunning) {
		object->ClearRender();
		object->RenderText("What's your name??",200, 200);
		object->RenderText(text,200,300);
		if(check)
			object->RenderText("My name is " + text, 200, 400);
		object->RenderPresent();
		while (SDL_PollEvent(&mainEvent)) {
			if(mainEvent.type == SDL_QUIT) {
				isRunning = false;
				break;
			} else if(mainEvent.type == SDL_TEXTINPUT || mainEvent.type == SDL_KEYDOWN) {
				
				if(mainEvent.type == SDL_TEXTINPUT) {
					text += mainEvent.text.text;
					
				}
				else if(mainEvent.key.keysym.sym == SDLK_BACKSPACE && text.length() > 0) {
					text = text.substr(0,text.length()-1);
					
				} else if(mainEvent.key.keysym.sym == SDLK_KP_ENTER && text.length() > 0) {
					check = true;
					SDL_StopTextInput();
				}
				
			} else {	
				break;
			}
			
			
		}
		
		
	}
	
	SDL_StopTextInput();
	object->Quit();
	
	SDL_Quit();
    return 0;
}