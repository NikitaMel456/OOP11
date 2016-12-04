#pragma once
#include "stdafx.h"
#include "Worker.h"
#include <string>
class Engineer:

	public Worker
{
	string sphere;
public:

	Engineer(void);
	~Engineer(void);
	void setSphere(string);
	void getSphere();
};