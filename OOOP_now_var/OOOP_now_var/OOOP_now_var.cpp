// OOOP_now_var.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Books.h"
#include <iostream>
using namespace std;

int main()
{
	int numOb;
	string NoP;
	cout << "Enter mumber of Entries:";
	cin >> numOb;
	Book *pop = new Book[numOb];
	for (int i = 0; i < numOb; i++)
	{
		Book::ShowObjects();
		pop[i].setName();
		pop[i].setAuthor();
		pop[i].setPublish();
		pop[i].setYear();
		pop[i].setNump();
		pop[i].setType();
	}
	string NoA;
	cout << "Ener nesecery author:";
	cin >> NoA;
	for (int i = 0; i < numOb; i++)
	{
		pop[i].BOA(NoA);
	}
	cout << "Ener nesecery Publishing:";
	cin >> NoP;
	for (int i = 0; i < numOb; i++)
	{
		pop[i].Publ(NoP);
	}
	delete[] pop;
    return 0;
}

