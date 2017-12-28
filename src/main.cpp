#include "main.h"

BOOL bExitSignal = false;
BOOL bIsEntryPointInitialized = false;

const char *szConsoleTitle = "LuaParse v0.01"; // Yeah, we are not gonna change it.

int main(int argc, char *argv[])
{
	CCoreLua *pCoreLua;
	pCoreLua = new CCoreLua();

	CXmlHandler *pXmlHandler;
	pXmlHandler = new CXmlHandler();

	if (!bIsEntryPointInitialized)
	{
		// Initialing code goes here..

		SetConsoleTitle(szConsoleTitle);

		pCoreLua->GetCurrentDir();

		if (pXmlHandler->LoadConfig() == 2) 
			ExitProcess(0);


		pCoreLua->LoadScript("script", true);

		bIsEntryPointInitialized = true;
	}

	while (!bExitSignal)
	{
		Sleep(25);
	}

	return EXIT_SUCCESS;
}