#include <iostream>

#include <SDL.h>
#include <SDL_ttf.h>

#include "Connection.h"
#include "Interface.h"

int main(int argc, char** args)
{
	Interface* interface = new Interface;
	Interface* interface1 = new Interface;
	
	interface->displayMain();
	interface1->displayMenu();

	delete interface;
	return 0;
}