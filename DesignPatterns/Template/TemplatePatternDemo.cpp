#include "Game.h"
#include "Cricket.h"
#include "Football.h"

int main(int argc, char **argv)
{
	Game *game = new Cricket();
	game->play();
	delete game;

	game = new Football();
	game->play();
	delete game;

	return 0;
}