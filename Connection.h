#pragma once
#include<iostream>
#include <SDL.h>
#include <SDL_ttf.h>

class ConnectionSDL {

public:
	SDL_Event event;
	bool run = true;
	ConnectionSDL() {};
	~ConnectionSDL() {};
	void processingEvent();

protected:
	TTF_Font* font;
	SDL_Surface* surfaceMessage;
	SDL_Texture* textureText;
	bool createWindow(SDL_Window*& window, const char* name, int x, int y, int w, int h);
	bool createRenderer(SDL_Window*& window, SDL_Renderer*& renderer);
	bool outText(SDL_Renderer*& renderer, const char* message, const char* styleText,
		int size, SDL_Color color, int x, int y, int width, int height);
	bool inputText(SDL_Renderer*& renderer, const char* styleText, SDL_Color color);
};
