#include "Router.h"

int MyQueryFunction(void* env, char* logicalname)
{
	if (strcmp(logicalname, "output1") == 0)
		return 1;
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