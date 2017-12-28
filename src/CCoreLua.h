#define MAX_SCRIPTS 25

struct stScript
{
	char szScriptName[MAX_SCRIPTS][32];
	lua_State *pScriptState[MAX_SCRIPTS];
};

class CCoreLua
{
private:
	char szWorkingDirectory[MAX_PATH];
	int iScriptsRunning;

	stScript Scripts;

public:
	CCoreLua();

	void GetCurrentDir();

	BOOL LoadScript(const char *szScriptName, bool bFirstLoad);
	BOOL LoadScripts();
};