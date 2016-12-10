#include "stdafx.h"
#include "SclB.h"
Sclb::Sclb()
{

}

Sclb::Sclb(string name, int price) :library(name, price)
{

}

void Sclb::Show(void)
{
	cout << "Name: " << name << endl;
	cout << "Price: " << price << endl;

}

void Sclb::Input(void)
{
	cout << "Name: ";
	cin >> name;
	cout << "Price: ";
	cin >> price;
}