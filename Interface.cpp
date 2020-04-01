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
	//inputText(rendererMain, "sans.ttf", 30, { 0, 0, 0 }, { 0, 0, 1080, 820 });
}

/*void Interface::displayMenu() {
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
	outText(rendererMenu, "Insert", "sans.ttf", 100, { 240, 255, 255 }, 50, 10, 20, 100);
	outText(rendererMenu, "Copy", "sans.ttf", 100, { 240, 255, 255 }, 50, 10, 20, 100);
	outText(rendererMenu, "Cut", "sans.ttf", 100, { 240, 255, 255 }, 50, 10, 20, 100);
	outText(rendererMenu, "Save", "sans.ttf", 100, { 240, 255, 255 }, 50, 10, 20, 100);
	outText(rendererMenu, "Exit", "sans.ttf", 100, { 240, 255, 255 }, 50, 10, 20, 100);
	outText(rendererMenu, "About", "sans.ttf", 100, { 240, 255, 255 }, 50, 10, 20, 100);
	SDL_RenderPresent(rendererMenu);
}

void Interface::displayPreview() {
	createWindow(windowPreview, "Preview", 470, 285, 500, 250);
	createRenderer(windowPreview, rendererPreview);
	SDL_SetRenderDrawColor(rendererPreview, 255, 182, 193, 255); // фон
	SDL_RenderClear(rendererPreview);
	outText(rendererPreview, "The simple text editor. olhovich", "preview.ttf", 80, { 0, 0, 255 }, { 0, 0, 500, 80 }); 
	SDL_RenderPresent(rendererPreview);
}*/