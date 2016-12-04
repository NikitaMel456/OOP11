#pragma once
#include "Person.h"
#include <string>
class Worker:
	public Person
{
	string name;
public:

	Worker(void);
	~Worker(void);
	void setname(string);
	void getYear();
};