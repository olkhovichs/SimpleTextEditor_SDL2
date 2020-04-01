#include "Connection.h"

bool ConnectionSDL::createWindow(SDL_Window* &window, const char* name, int x, int y, int w, int h) {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return false;
	}

	window = SDL_CreateWindow(name, x, y, w, h, SDL_WINDOW_SHOWN);

	if (window == nullptr) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return 2;
	}
}

bool ConnectionSDL::createRenderer(SDL_Window*& window, SDL_Renderer* &renderer) {
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (renderer == nullptr) {
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return false;
	}
}

bool ConnectionSDL::outText(SDL_Renderer*& renderer, const char* message, const char* styleText,
	int size, SDL_Color color, int x, int y, int width, int height) {
	SDL_Rect dest;
	if (TTF_Init() == -1) {
		std::cout << "SDL_TTF_Init Error: " << TTF_GetError() << std::endl;
		return false;
	}
	font = TTF_OpenFont(styleText, size);
	surfaceMessage = TTF_RenderUTF8_Solid(font, message, color);
	textureText = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
	
	for (int i = 0; i < strlen(message); i++) {
		dest.x = x;
		dest.y = y;
		dest.w = width + (i* 32);
		dest.h = height;
	}
	SDL_RenderCopy(renderer, textureText, NULL, &dest);
}

bool ConnectionSDL::inputText(SDL_Renderer*& renderer, const char* styleText, SDL_Color color) {
	if (TTF_Init() == -1) {
		std::cout << "SDL_TTF_Init Error: " << TTF_GetError() << std::endl;
		return false;
	}
	std::string m;
	bool quit = false;
	SDL_Event e;
	TTF_Font* font1 = TTF_OpenFont(styleText, 30);
	SDL_Surface* surface1 = TTF_RenderUTF8_Solid(font1, m.c_str(), color);
	SDL_Texture* texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
	while (!quit) {
		bool renderText = false;
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_KEYDOWN) {
				if (e.key.keysym.sym == SDLK_BACKSPACE && m.length() > 0) {
					m.pop_back();
					renderText = true;
				}
				else if (e.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL) {
					SDL_SetClipboardText(m.c_str());
				}
				else if (e.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL) {
					m = SDL_GetClipboardText();
					renderText = true;
				}
			}
			if (e.type == SDL_TEXTINPUT) {
				if (!(SDL_GetModState() & KMOD_CTRL && (e.text.text[0] == 'c' || e.text.text[0] == 'C' || e.text.text[0] == 'v' || e.text.text[0] == 'V'))) {
					m += e.text.text;
					renderText = true;
				}
			}
		}
		if (renderText) {
			if (m != "") {
				surface1 = TTF_RenderUTF8_Solid(font1, m.c_str(), color);
				texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
			}
			else {
				m = " ";
				surface1 = TTF_RenderUTF8_Solid(font1, m.c_str(), color);
				texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
			}
		}
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture1, NULL, &rect); // переписать 
		SDL_RenderPresent(renderer);
	}
}

void ConnectionSDL::processingEvent() {
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
