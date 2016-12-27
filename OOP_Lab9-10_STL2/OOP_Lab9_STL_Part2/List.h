#pragma once
#include <iostream>
class List
{
public:
	char charm[2];
	bool rc = true;
	List() :charm("") {};
	List(const char m) { charm[2] = m; };
	~List() {};
	char List::getm()const { return charm[2]; }
	friend std::ostream &operator << (std::ostream &output, List &obj)
	{
		output << " " << obj.getm();
		return output;
	}
};