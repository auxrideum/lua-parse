#include "main.h"

int CXmlHandler::LoadConfig()
{
	if (!xmlSettings.LoadFile("config.xml"))
	{
		char szTitleStr[32];
		sprintf_s(szTitleStr, sizeof(szTitleStr), "Error Id: %d", xmlSettings.ErrorId());

		MessageBox(NULL, xmlSettings.ErrorDesc(), szTitleStr, MB_ICONERROR);
	}

	return xmlSettings.ErrorId();
}