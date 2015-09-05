#include "game.h"
#include "Router.h"
#include <tchar.h>
#include <sstream>

int main(int argc, TCHAR *argv[])
{
	srand(time(NULL));

	Game *game = new Game();
	CLIPSCPPEnv theEnv;
	myCLIPSRouter theRouter;

	theEnv.AddRouter("myRouter", 100, &theRouter);
	theEnv.Load("template.clp");
	theEnv.Load("facts.clp");
	theEnv.Reset();
	theEnv.Run(-1);
	
	game->UpdateUnitsInClips(theEnv);
	game->play(theRouter, theEnv);

	delete game;

	return 0;
}