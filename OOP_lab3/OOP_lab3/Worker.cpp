#include "stdafx.h"
#include "Person.h"
#include "Worker.h"

Worker::Worker()
{
	cout << "entering of a konsructor for worker" << endl;
}
void Worker::setname(string name)
{
	this->name = name;
}

void Worker::getYear()
{
	cout << "Worker's experience:" << this->name << endl;
}
Worker::~Worker()
{
	cout << "Entering of a destructor for worker" << endl;
}