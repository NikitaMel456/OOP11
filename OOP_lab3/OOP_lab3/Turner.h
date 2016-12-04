#pragma once
#include "stdafx.h"
#include "Engineer.h"
#include <string>
class Turner:
	public Engineer
{
	string qual;
public:
	Turner(void);
	~Turner(void);
	void setQualification(string);
	void getQualification();
};