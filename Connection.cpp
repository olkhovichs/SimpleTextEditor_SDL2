#include <iostream>

#include "Connection.h"

int ConnectionSDL::createWindow(SDL_Window* &window, const char* name, int x, int y, int w, int h) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	window = SDL_CreateWindow(name, x, y, w, h, SDL_WINDOW_SHOWN);

	if (window == nullptr) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return 2;
	}
}

int ConnectionSDL::createRenderer(SDL_Window*& window, SDL_Renderer* &renderer) {
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (renderer == nullptr) {
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return 3;
	}
}

/*void ConnectionSDL::quitSDL(SDL_Window*& window) {
	SDL_DestroyWindow(window);
	SDL_Quit();
}*/