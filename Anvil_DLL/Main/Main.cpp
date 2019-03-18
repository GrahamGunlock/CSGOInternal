#include <windows.h>

#include "Init/Init.h"

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		CreateThread(NULL, NULL, Init::Init, NULL, NULL, NULL);
        break;

	case DLL_PROCESS_DETACH:
		break;
    }
    return TRUE;
}

