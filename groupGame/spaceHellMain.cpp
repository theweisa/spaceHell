/*
GROUP 3 GAME
SPACE HELL
Andrew Wei, Ku Yi Sien(Ian), Kena Shi, Kaeda Hamada

Runs on Visual Studio 2017 on Windows and Xcode on Mac using SFML library
*/
#include "spaceHell.h"

//main code for the game!
int main()
{
	srand(static_cast<unsigned>(time(0)));
	SpaceHell game;
	game.run();
	return 0;
}
