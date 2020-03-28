#pragma once

#include <iostream>
#include <vector>
#include <string>

#include <SDL.h>
#include <SDL_ttf.h>

#include "Connection.h"
#include "Interface.h"

class Edit : public Interface {

public:

	//std::vector<std::string> mainBuffer;
	//std::vector<std::string> tempBuffer;

	int inputText(SDL_Renderer*& renderer, const char* message, const char* styleText, 
		int size, SDL_Color color, SDL_Rect rect);
};