#ifndef Router_H
#define Router_H

#include "..\Clipse\Projects\Source\Integration\clipscpp.h"
#pragma comment(lib, "..\\..\\Clipse\\Projects\\Libraries\\Microsoft\\CLIPSCPP.lib")

using namespace CLIPS;
using namespace std;

class myCLIPSRouter : public CLIPSCPPRouter
{
public:
	virtual int Query(CLIPSCPPEnv *, const char *);
	virtual int Print(CLIPSCPPEnv *, const char *, const char *);
	string str = "";
	char *m_lName = "decision";
};

#endif