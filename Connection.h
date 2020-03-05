#pragma once

#include <SDL.h>
#include <SDL_ttf.h>

class ConnectionSDL {

public:

	ConnectionSDL() {};
	~ConnectionSDL() {};
	SDL_Event event;
	bool run = true;
	int createWindow(SDL_Window* &window, const char* name, int x, int y, int w, int h);
	int createRenderer(SDL_Window* &window, SDL_Renderer* &renderer);
	void eventProcessing(SDL_Window* &window);
	ConnectionSDL* connect;
	//void eventProcessing(SDL_Window* window, ConnectionSDL* connect);

protected:
	
};
