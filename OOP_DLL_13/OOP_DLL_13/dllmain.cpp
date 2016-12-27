// dllmain.cpp: определ€ет точку входа дл€ приложени€ DLL.
#include "stdafx.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH://инициализаци€ процесса
	case DLL_THREAD_ATTACH://инициализаци€ потока
	case DLL_THREAD_DETACH://очистка структур потока
	case DLL_PROCESS_DETACH://очистка структур процесса
		break;
	}
	return TRUE;
}

