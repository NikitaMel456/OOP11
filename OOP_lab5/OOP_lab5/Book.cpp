#include "stdafx.h"
#include "Book.h"

Book::Book(string name, int price, int year):library(name,price)
{
	this->year=year;
}
void Book::Show(void)
{
	cout << "Name " << name << endl;
	cout << "Price " << price << endl;
	cout << "Year " << year << endl;
}
void Book::Input(void)
{
	cout << "Name: ";
	cin >> name;
	cout << "Price: ";
	cin >> price;
	cout << "Year: ";
	cin >> year;
}
int Book::Getyear()
{
	return year;
}