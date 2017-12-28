#include "main.h"

CCoreLua::CCoreLua()
{
	iScriptsRunning = 0;
}

BOOL CCoreLua::LoadScript(const char *szScriptName, bool bFirstLoad)
{
	char szTemp[256];
	sprintf_s(szTemp, sizeof(szTemp), "%s\\scripts\\%s.lua", szWorkingDirectory, szScriptName);

	for (int i = 0; i < MAX_SCRIPTS; i++)
	{
		if (strcmp(Scripts.szScriptName[i], szScriptName) == 0)
		{
			printf("  %s.lua... FAIL (already loaded)\n", szScriptName);
			return false;
		}
	}

	FILE *fExists = fopen(szTemp, "rb");
	if (!fExists)
	{
		printf("  %s.lua... FAIL (does not exist)\n", szScriptName);
		return false;
	}

	strcpy_s(Scripts.szScriptName[iScriptsRunning], 32, szScriptName);
	Scripts.pScriptState[iScriptsRunning] = lua_open();

	if (Scripts.pScriptState[iScriptsRunning] == NULL)
	{
		printf("  %s.lua... FAIL (LUA virtual machine)\n", szScriptName);
		return false;
	}

	luaL_openlibs(Scripts.pScriptState[iScriptsRunning]);

	int iCurrentScriptStatus = luaL_loadfile(Scripts.pScriptState[iScriptsRunning], szTemp);

	if (bFirstLoad) 
		printf("    %s.lua... %s\n", szScriptName, iCurrentScriptStatus ? "FAIL" : "OK");
	
	if (iCurrentScriptStatus == 0)
	{
		iCurrentScriptStatus = lua_pcall(Scripts.pScriptState[iScriptsRunning], 0, LUA_MULTRET, 0);

		if (iCurrentScriptStatus == 0)
		{
			if (!bFirstLoad)
				printf(" Not the first load.\n");
		}

		if (!bFirstLoad)
			printf("  Script %s was succesfully loaded.\n", Scripts.szScriptName[iScriptsRunning]);
		

		iScriptsRunning++;
	}
	else
	{
		printf("  %s\n", lua_tostring(Scripts.pScriptState[iScriptsRunning], -1));
		return false;
	}

	return true;
}

BOOL CCoreLua::LoadScripts()
{
//	if (iLoadedScripts)
//		iLoadedScripts = 0;



	return TRUE;
}

void CCoreLua::GetCurrentDir()
{
	if (GetModuleFileName(NULL, szWorkingDirectory, sizeof(szWorkingDirectory) - 32) != 0)
	{
		if (strrchr(szWorkingDirectory, '\\') != NULL) *strrchr(szWorkingDirectory, '\\') = 0;
		else strcpy_s(szWorkingDirectory, 1, ".");
	}
	else strcpy_s(szWorkingDirectory, 1, ".");
}