#include <iostream>

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
	outText(rendererMenu, "Insert", "sans.ttf", 100, { 240, 255, 255 }, { 50, 10, 260, 100 });
	outText(rendererMenu, "Copy", "sans.ttf", 100, { 240, 255, 255 }, { 50, 146, 260, 100 });
	outText(rendererMenu, "Cut", "sans.ttf", 100, { 240, 255, 255 }, { 50, 282, 260, 100 });
	outText(rendererMenu, "Save", "sans.ttf", 100, { 240, 255, 255 }, { 50, 418, 260, 100 });
	outText(rendererMenu, "Exit", "sans.ttf", 100, { 240, 255, 255 }, { 50, 554, 260, 100 });
	outText(rendererMenu, "About", "sans.ttf", 100, { 240, 255, 255 }, { 50, 690, 260, 100 });
	SDL_RenderPresent(rendererMenu);
}

void Interface::displayPreview() {
	createWindow(windowPreview, "Preview", 470, 285, 500, 250);
	createRenderer(windowPreview, rendererPreview);
	SDL_SetRenderDrawColor(rendererPreview, 255, 182, 193, 255); // фон
	SDL_RenderClear(rendererPreview);
	outText(rendererPreview, "The simple text editor. olhovich", "preview.ttf", 80, { 0, 0, 255 }, { 0, 0, 500, 80 }); 
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

int Interface::outText(SDL_Renderer*& renderer, const char* message, const char* styleText,
	int size, SDL_Color color, SDL_Rect rect) {
	if (TTF_Init() == -1) {
		std::cout << "SDL_TTF_Init Error: " << TTF_GetError() << std::endl;
		return 4;
	}

	font = TTF_OpenFont(styleText, size);
	surfaceMessage = TTF_RenderUTF8_Solid(font, message, color);
	textureText = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	SDL_RenderCopy(renderer, textureText, NULL, &rect); // перепискать с blitsurface
}