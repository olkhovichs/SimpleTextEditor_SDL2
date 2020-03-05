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

int ConnectionSDL::createRenderer(SDL_Window* &window, SDL_Renderer* &renderer) {
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (renderer == nullptr) {
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return 3;
	}


	/*SDL_SetRenderDrawColor(renderer, 173, 216, 230, 255);
	SDL_RenderClear(rendererMain);
	SDL_SetRenderDrawColor(rendererMain, 255, 255, 255, 255);
	rectMain = { 240, 0, 600, 820 };
	SDL_RenderFillRect(rendererMain, &rectMain);
	SDL_RenderPresent(rendererMain);

	SDL_SetRenderDrawColor(rendererMenu, 173, 216, 230, 255);
	SDL_RenderClear(rendererMenu);
	/*SDL_SetRenderDrawColor(rendererMain, 255, 255, 255, 255);
	rectMain = { 240, 0, 600, 820 };
	SDL_RenderFillRect(rendererMain, &rectMain);
	SDL_RenderPresent(rendererMenu);*/
}

void ConnectionSDL::eventProcessing(SDL_Window*& window) {
	while (run) {
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				run = false;
			}
			if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					SDL_DestroyWindow(window);
				}
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					SDL_DestroyWindow(window);
				}
			}
		}
	}
}