#include <iostream>

#include <SDL.h>
#include <SDL_ttf.h>

#include "Connection.h"
#include "Interface.h"



int main(int argc, char** args)
{
	ConnectionSDL* connect = new ConnectionSDL;
	Interface* interface = new Interface;
	
	interface->displayMain();

	delete connect;

	return 0;
}