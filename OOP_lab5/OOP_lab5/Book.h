#pragma once
#include "Library.h"
class Book :public library
{
public:
	Book() {};
	Book(string name,int price, int year);
	void Show(void);
	void Input(void);
	int Getyear();
	int year;
};