#include "Connection.h"

bool ConnectionSDL::createWindow(SDL_Window* &window, const char* name, int x, int y, int w, int h) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return false;
	}

	window = SDL_CreateWindow(name, x, y, w, h, SDL_WINDOW_SHOWN);

	if (window == nullptr) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return false;
	}
}

bool ConnectionSDL::createRenderer(SDL_Window*& window, SDL_Renderer* &renderer) {
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (renderer == nullptr) {
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return false;
	}
}
