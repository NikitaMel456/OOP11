#include "stdafx.h"
#include "Magazine.h"

Mag::Mag()
{
	
}

Mag::Mag(string name, int price) :library(name, price)
{
	
}

void Mag::Show(void)
{
	cout << "Name: " << name << endl;
	cout << "Price: " << price << endl;
	
}

void Mag::Input(void)
{
	cout << "Name: ";
	cin >> name;
	cout << "Price: ";
	cin >> price;
}