// Explicit.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <Windows.h>
typedef void(*MAC)();

int main()
{
	HMODULE hm = LoadLibrary(L"OOP_DLL_13.dll");
	MAC mac = (MAC)::GetProcAddress(hm, "getmac");
	(*mac)();
	FreeLibrary(hm);
	system("pause");
	return 0;
}