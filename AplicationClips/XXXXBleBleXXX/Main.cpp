#include "game.h"
#include <tchar.h>
#include <sstream>
#include "..\Clipse\Projects\Source\Integration\clipscpp.h"
#pragma comment(lib, "..\\..\\Clipse\\Projects\\Libraries\\Microsoft\\CLIPSCPP.lib")

using namespace CLIPS;

static char *m_lName = "decision";

class myCLIPSRouter : public CLIPSCPPRouter
{
public:
	virtual int Query(CLIPSCPPEnv *, const char *);
	virtual int Print(CLIPSCPPEnv *, const char *, const char *);
	string str = "";
};

int MyQueryFunction(void* env, char* logicalname)
{
	if (strcmp(logicalname, "output1") == 0)
		return 1;
	return 0;
}

int main(int argc, TCHAR *argv[])
{
	Game *game = new Game();
	CLIPSCPPEnv theEnv;
	myCLIPSRouter theRouter;
	
	cout << "Nacisnij enter, aby kontynuowac." << endl;

	theEnv.AddRouter("myRouter", 100, &theRouter);
	theEnv.Load("adam.clp");
	theEnv.Reset();
	theEnv.Run(-1);

	game->setDecisionInfo(theRouter.str);
	game->play();

	delete game;

	return 0;
}

int myCLIPSRouter::Query(CLIPSCPPEnv *cEnv, const char *logicalName)
{
	int n = strcmp(logicalName, m_lName);
	if (strcmp(logicalName, m_lName) == 0)
		return 1;
	else
		return 0;
}

int myCLIPSRouter::Print(CLIPSCPPEnv *cEnv, const char *logicalName, const char *output)
{
	str = output;
	return 1;
}