#include "stdafx.h"
#include "Person.h"
Person::Person()
{
	cout << "entering of a konsructor for person." << endl;
}
void Person::setname(string name)
{
	this->name = name;
}

void Person::getname()
{
	cout << "Person's name:" << this->name << endl;
}
Person::~Person()
{
	cout << "Entering of a destructor for person" << endl;
}