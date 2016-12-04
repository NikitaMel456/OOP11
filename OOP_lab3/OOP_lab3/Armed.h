#pragma once
#include "Person.h"
#include <string>
class Armed:
	public Person
{
	string rank;
public:

	Armed(void);
	~Armed(void);
	void setRank(string);
	void getRank();
};