#pragma once
#include "Library.h"
class Mag:public library
{
public:
	Mag();
	Mag(string name, int price);
	void Show(void);
	void Input(void);
	
};