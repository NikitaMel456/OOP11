#include"stdafx.h"
#include"Books.h"
#include<iostream>
using namespace std;
Book::Book(const string & Name, const string & Author, const string & Publish, int Year, int Nump, const string & Type)
{
	name = Name;
	author = Author;
	publish = Publish;
	year = Year;
	nump = Nump;
	type = Type;
}
Book::~Book() { };
Book::Book(const Book & bk)
{
	name = bk.name;
	author = bk.author;
	publish = bk.publish;
	year = bk.year;
	nump = bk.nump;
	type = bk.type;
}

void Book::check()
{
	if (year > maxyear || year < minyear) cout << "ERROR,the application can't run further";
}

void Book::setName()
{
	cout << "Enter name" << endl;
	cin >> name;
}

void Book::setAuthor()
{
	cout << "Enter author" << endl;
	cin >> author;
}

void Book::setPublish()
{
	cout << "Enter Publish" << endl;
	cin >> publish;
}

void Book::setYear()
{
	cout << "Enter Year" << endl;
	cin >> year;
}

void Book::setNump()
{
	cout << "Enter number of pages" << endl;
	cin >> nump;
}

void Book::setType()
{
	cout << "Ener type of binding" << endl;
	cin >> type;
}

void Book::getName()
{
	cout << "Name:" << name;
}

void Book::getAuthor()
{
	cout << "Author:" << author;
}

void Book::getPublish()
{
	cout << "Publish:" << publish;
}

void Book::getYear()
{
	cout << "Year:" << year;
}

void Book::getNump()
{
	cout << "Number of pages:" << nump;
}

void Book::getType()
{
	cout << "Type of binding" << type;
}

int Book::Objects = 0;

void Book::ShowObjects()
{
	cout << "Create object number :" << ++Objects << endl << endl;
}

void Book::BOA(string NoA)
{
	
	if (NoA==author)
			cout << name<<endl;
	
}

void Book::Publ(string NoP)
{
	if (NoP == publish)
			cout << name << endl;
}
