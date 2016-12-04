#include "stdafx.h"
#include "Turner.h"
#include "Worker.h"

Turner::Turner()
{
	cout << "entering of a konsructor for Turner" << endl;
}
void Turner::setQualification(string qual)
{
	this->qual = qual;
}

void Turner::getQualification()
{
	cout << "Turner's qualification:" << this->qual << endl;
}
Turner::~Turner()
{
	cout << "Entering of a destructor for Turner" << endl;
}