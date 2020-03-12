#include <SDL.h>
#include <SDL_ttf.h>

#include "Interface.h"

void Interface::displayMain() {
	createWindow(windowMain, "Main", 360, 35, 1080, 820);
	createRenderer(windowMain, rendererMain);
	SDL_SetRenderDrawColor(rendererMain, 173, 216, 230, 255); // фон
	SDL_RenderClear(rendererMain);
	SDL_SetRenderDrawColor(rendererMain, 255, 255, 255, 255); // белый лист
	rectMain = { 240, 0, 600, 820 };
	SDL_RenderFillRect(rendererMain, &rectMain);
	SDL_RenderPresent(rendererMain);
}

void Interface::displayMenu() {
	createWindow(windowMenu, "Menu", 0, 35, 360, 820);
	createRenderer(windowMenu, rendererMenu);
	SDL_SetRenderDrawColor(rendererMenu, 173, 216, 230, 255); // фон
	SDL_RenderClear(rendererMenu);
	//SDL_RenderPresent(rendererMenu);
	for (int i = 0; i < 600; i += 272) {
		SDL_SetRenderDrawColor(rendererMenu, 135, 206, 235, 255);
		rectMenu = { 0, i, 360, 136 };
		SDL_RenderFillRect(rendererMenu, &rectMenu);
		
	}
	SDL_RenderPresent(rendererMenu);
}

void Interface::displayPreview() {
	createWindow(windowMenu, "Preview", 470, 285, 500, 250);
	createRenderer(windowMenu, rendererPreview);
	SDL_SetRenderDrawColor(rendererPreview, 255, 182, 193, 255); // фон
	SDL_RenderClear(rendererPreview);
	rectText = { 0, 0, 50, 50 };
	outText(rendererPreview, "privet", "preview.ttf", 20, { 255, 0, 0 }, rectText);
	SDL_RenderPresent(rendererPreview);
}

void Interface::processingEvent() {
	while (run) { // пока работает 
		while (SDL_PollEvent(&event)) { // если что-то произошло
			switch (event.type) { // смотрим что за событие
			case SDL_QUIT:
				run = false;
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
				case SDLK_ESCAPE:
					run = false;
					//SDL_DestroyWindow(windowPreview);
					break;
				default:
					break;
				}
				break;
			}
		}
	}
}