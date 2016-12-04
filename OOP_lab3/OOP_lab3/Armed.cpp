#include "stdafx.h"
#include "Armed.h"

Armed::Armed()
{
	cout << "entering of a konsructor for armed" << endl;
}
void Armed::setRank(string rank)
{
	this->rank = rank;
}

void Armed::getRank()
{
	cout << "Armed's rank:" << this->rank << endl;
}
Armed::~Armed()
{
	cout << "Entering of a destructor for armed" << endl;
}