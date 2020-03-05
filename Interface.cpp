#include <SDL.h>
#include <SDL_ttf.h>

#include "Interface.h"

void Interface::displayMain() {
	createWindow(windowMain, "Main", 360, 35, 1080, 820);
	createRenderer(windowMain, rendererMain);

	SDL_SetRenderDrawColor(rendererMain, 173, 216, 230, 255);
	SDL_RenderClear(rendererMain);
	SDL_SetRenderDrawColor(rendererMain, 255, 255, 255, 255);
	rectMain = { 240, 0, 600, 820 };
	SDL_RenderFillRect(rendererMain, &rectMain);
	SDL_RenderPresent(rendererMain);
	eventProcessing(windowMain);
}

void Interface::displayMenu() {
	createWindow(windowMenu, "Menu", 0, 35, 360, 820);
	/*createRenderer(windowMenu, rendererMenu);

	SDL_SetRenderDrawColor(rendererMenu, 173, 216, 230, 255);
	SDL_RenderClear(rendererMenu);
	SDL_RenderPresent(rendererMenu);
	eventProcessing(windowMenu);*/
}