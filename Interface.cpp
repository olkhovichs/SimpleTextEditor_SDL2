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
	inputText("preview.ttf");
	//saveText();
	std::cout << main;
}

void Interface::displayMenu() {
	createWindow(windowMenu, "Menu", 0, 35, 360, 820);
	createRenderer(windowMenu, rendererMenu);
	SDL_SetRenderDrawColor(rendererMenu, 173, 216, 230, 255); // фон
	SDL_RenderClear(rendererMenu);
	for (int i = 0; i < 600; i += 272) {
		SDL_SetRenderDrawColor(rendererMenu, 135, 206, 235, 255);
		rectMenu = { 0, i, 360, 136 };
		SDL_RenderFillRect(rendererMenu, &rectMenu);
		
	}
	outText(rendererMenu, "Insert", "sans.ttf", 100, color->azure, 50, 10);
	outText(rendererMenu, "Copy", "sans.ttf", 100, color->azure, 50, 150);
	outText(rendererMenu, "Cut", "sans.ttf", 100, color->azure, 50, 290);
	outText(rendererMenu, "Save", "sans.ttf", 100, color->azure, 50, 440);
	outText(rendererMenu, "Exit", "sans.ttf", 100, color->azure, 50, 580);
	outText(rendererMenu, "About", "sans.ttf", 100, color->azure, 50, 680);
	SDL_RenderPresent(rendererMenu);
}

void Interface::displayPreview() {
	createWindow(windowPreview, "Preview", 470, 285, 500, 250);
	createRenderer(windowPreview, rendererPreview);
	SDL_SetRenderDrawColor(rendererPreview, 255, 182, 193, 255); // фон
	SDL_RenderClear(rendererPreview);
	outText(rendererPreview, "The simple text editor. olhovich", "preview.ttf", 80, color->blue, 0, 0); 
	SDL_RenderPresent(rendererPreview);
}

void Interface::processingEvent() {
	SDL_StartTextInput();
	while (run) {
		runText = false;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					run = false;
				}
				if (event.key.keysym.sym == SDLK_BACKSPACE && mainBuffer.length() > 0) { // проверка на пустоту
					mainBuffer.pop_back();
					runText = true;
				}
				else if (event.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL) {
					SDL_SetClipboardText(mainBuffer.c_str());
				}
				else if (event.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL) {
					mainBuffer = SDL_GetClipboardText();
					runText = true;
				}
			}
			if (event.type == SDL_TEXTINPUT) {
				if (!(SDL_GetModState() & KMOD_CTRL && (event.text.text[0] == 'c' || event.text.text[0] == 'C' || event.text.text[0] == 'v' || event.text.text[0] == 'V'))) {
					mainBuffer += event.text.text;
					runText = true;
				}
			}
		}
		if (runText) {
			if (mainBuffer != "") {
				surfaceInputText = TTF_RenderUTF8_Blended(fontInput, mainBuffer.c_str(), color->black);
				textureInputText = SDL_CreateTextureFromSurface(rendererMain, surfaceInputText);
			}
			else { // ???
				mainBuffer = " ";
				surfaceInputText = TTF_RenderUTF8_Blended(fontInput, mainBuffer.c_str(), color->black);
				textureInputText = SDL_CreateTextureFromSurface(rendererMain, surfaceInputText);
			}
		}
		for (int i = 0; i < strlen(mainBuffer.c_str()); i++) {
			int y = 50;
			destInputText.x = 50;
			destInputText.y = y;
			destInputText.w = 25 + (i * 32);
			destInputText.h = 25;
		}
		SDL_SetRenderDrawColor(rendererMain, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(rendererMain);
		SDL_RenderCopy(rendererMain, textureInputText, NULL, &destInputText);
		SDL_RenderPresent(rendererMain);
	}
	SDL_StopTextInput();
}