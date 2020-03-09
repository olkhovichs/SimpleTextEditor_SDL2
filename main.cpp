#include <iostream>

#include <SDL.h>
//#include <SDL_ttf.h>

#include "Connection.h"
#include "Interface.h"

void startApplication() {
	Interface* start = new Interface;
	start->displayMenu();
	start->displayMain();
	start->displayPreview();
	start->processingEvent();
	delete start;
}

int main(int argc, char** args)
{
	startApplication();
	return 0;
}