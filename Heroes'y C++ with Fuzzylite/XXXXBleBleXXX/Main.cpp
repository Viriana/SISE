#include "game.h"
#include "Router.h"
#include <tchar.h>
#include <sstream>

int main(int argc, TCHAR *argv[])
{
	Game *game = new Game();
	CLIPSCPPEnv theEnv;
	myCLIPSRouter theRouter;

	theEnv.AddRouter("myRouter", 100, &theRouter);
	theEnv.Load("adam.clp");

	game->setDecisionInfo(theRouter.str);
	game->play(theRouter, theEnv);

	delete game;

	system("pause");

	return 0;
}