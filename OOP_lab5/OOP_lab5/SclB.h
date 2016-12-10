#pragma once
#include "Library.h"
class Sclb:public library
{
public:
	Sclb();
	Sclb(string name, int price);
	void Show(void);
	void Input(void);
	
};