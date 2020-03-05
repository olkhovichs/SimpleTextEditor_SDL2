#pragma once

#include <SDL.h>
#include <SDL_ttf.h>

#include "Connection.h"

struct Color {
	SDL_Color black = { 0, 0, 0 };
	SDL_Color white = { 255, 255, 255 };
	SDL_Color red = { 255, 0, 0 };
	SDL_Color blue = { 0, 0, 255 };
	SDL_Color green = { 0, 128, 0 };
	SDL_Color yellow = { 255, 255, 0 };
	SDL_Color lightBlue = { 173, 216, 230 };
};

class Interface : public ConnectionSDL {

public:
	
	SDL_Event event;
	bool run = true;

	void displayMain();
	void displayMenu();
	void displayPreview();
	void processingEvent();

private:
	SDL_Window* windowMenu = nullptr;
	SDL_Window* windowMain = nullptr;
	SDL_Window* windowPreview = nullptr;
	SDL_Renderer* rendererMenu = nullptr;
	SDL_Renderer* rendererMain = nullptr;
	SDL_Renderer* rendererPreview = nullptr;
	SDL_Rect rectMain;
	SDL_Rect rectMenu;
};