// Entry.cpp : Defines the entry point for the DLL application.
#include <windows.h>
#include <string.h>

#include "../Tools/Utilitys/Utility.h"
#include "../SDK/IBaseClientDLL/IBaseClientDLL.h"
#include "../SDK/IVEngineClient/IVEngineClient.h"

DWORD WINAPI CheatEntry(LPVOID lpThreadParameter)
{
	Tools::SetupConsole();
	IVEngineClient *EngineClient = (IVEngineClient*)Tools::CaptureInterface("engine.dll", "VEngineClient014");
	IBaseClientDLL *BaseClientDLL = (IBaseClientDLL*)(Tools::CaptureInterface("client_panorama.dll", "VClient018"));

}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		CreateThread(NULL, NULL, CheatEntry, NULL, NULL, NULL);
        break;

	case DLL_PROCESS_DETACH:
		break;
    }
    return TRUE;
}

