#pragma once

#include <SDL.h>
#include <SDL_ttf.h>

class ConnectionSDL {

public:
	ConnectionSDL() {};
	~ConnectionSDL() {};
	void quitSDL(SDL_Window*& window);

protected:
	TTF_Font* font;
	SDL_Surface* surfaceMessage;
	SDL_Texture* textureText;

	int createWindow(SDL_Window*& window, const char* name, int x, int y, int w, int h);
	int createRenderer(SDL_Window*& window, SDL_Renderer*& renderer);
	int outText(SDL_Renderer*& renderer, const char* message, const char* styleText,
		int size, SDL_Color color, SDL_Rect rect);
};
