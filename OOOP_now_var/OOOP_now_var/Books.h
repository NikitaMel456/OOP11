#pragma once
#include <string>
#include <iostream>
using namespace std;
class Book
{
	string name;
	string author;
	string publish;
	int year;
	int nump;
	string type;
	const int minyear = 1800;
	const int maxyear = 2016;
	static int Objects;

public:
	Book() :name(""), author(""), publish(""), year(0), nump(0), type("") {};
	Book(const string &, const string &, const string &,int, int, const string &);
	Book(const Book &A);
	~Book();
	void setName();
	void setAuthor();
	void setPublish();
	void setYear();
	void setNump();
	void setType();
	void getName();
	void getAuthor();
	void getPublish();
	void getYear();
	void getNump();
	void getType();
	void check();
	void BOA(string);
	static void ShowObjects();
	void Publ(string);
};