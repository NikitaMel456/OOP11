#pragma once
#include<string>
#include<iostream>

class List
{
public:
	List() : parm("") {};
	List(const std::string& param) { parm = param; }
	~List() {};
	void setName(const std::string& name) { parm = name; }
	std::string List::getparm()const { return parm; }
	bool operator < (const List & x) const
	{
		if (parm < x.parm)
			return true;
		else
			return false;
	}

	friend std::ostream &operator<<(std::ostream &stream, List& obj)
	{
		stream << obj.getparm() << std::endl;
		return stream;
	}
	bool operator ==(const std::string & str) const
	{
		return parm == str;
	}
private:
	std::string parm;
};



