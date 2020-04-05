#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>

class ConnectionSDL {

public:
	SDL_Event event;
	bool run = true;
	ConnectionSDL() {};
	~ConnectionSDL() {};

protected:
	bool createWindow(SDL_Window*& window, const char* name, int x, int y, int w, int h);
	bool createRenderer(SDL_Window*& window, SDL_Renderer*& renderer);
};
