#pragma once
#include "Book.h"
#include "Magazine.h"
#include "SclB.h"
class Cheker
{
	
public:
	static Cheker *head;
	void *adress;
	int kind;
	Cheker *next;
	Cheker() {};
	
};