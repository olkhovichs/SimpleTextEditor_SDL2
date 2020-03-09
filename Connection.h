#pragma once

#include <SDL.h>
//#include <SDL_ttf.h>

class ConnectionSDL {

public:
	ConnectionSDL() {};
	~ConnectionSDL() {};
	void quitSDL(SDL_Window*& window);

protected:
	int createWindow(SDL_Window*& window, const char* name, int x, int y, int w, int h);
	int createRenderer(SDL_Window*& window, SDL_Renderer*& renderer);
};
