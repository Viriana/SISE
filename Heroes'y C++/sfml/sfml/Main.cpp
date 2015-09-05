#include "game.h"
//#include <tchar.h>
//#include "C:\Users\Ania\Documents\Visual Studio 2013\Projects\AplikacjaZClipsem\AplikacjaZClipsem\Projects\Source\Integration\clipscpp.h"
//#pragma comment(lib, "C:\\Users\\Ania\\Documents\\Visual Studio 2013\\Projects\\AplikacjaZClipsem\\AplikacjaZClipsem\\Projects\\Libraries\\Microsoft\\CLIPSCPP.lib")

//int main(int argc, TCHAR *argv[])
int main()
{
	//CLIPS::CLIPSCPPEnv theEnv;

	//// For load to work, the CLIPS file must be in the
	//// the same directory as the executable, otherwise
	//// the full path should be specified.
	//// theEnv.Load("hello.clp");

	//theEnv.Build("(defrule hello"
	//	"   =>"
	//	"  (printout t \"Hello World.\" crlf)"
	//	"  (printout t \"Hit return to end.\" crlf)"
	//	"  )");
	//theEnv.Reset();
	//theEnv.Run(-1);
	Game *game = new Game();
	game->play();

	delete game;

    return 0;
}