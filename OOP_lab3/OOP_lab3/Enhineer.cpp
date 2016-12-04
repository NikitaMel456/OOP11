#include "stdafx.h"
#include "Engineer.h"
#include "Worker.h"

Engineer::Engineer()
{
	cout << "entering of a konsructor for Engineer" << endl;
}
void Engineer::setSphere(string sphere)
{
	this->sphere = sphere;
}

void Engineer::getSphere()
{
	cout << "Engineer's sphere:" << this->sphere << endl;
}
Engineer::~Engineer()
{
	cout << "Entering of a destructor for Engineer" << endl;
}
