#pragma once
#include "stdafx.h"
#include <string>
#include <vector>

class library
{
	protected :
	string name;
	
public:
	library() {};
	library(string name, int price);
	int price;
	
};

