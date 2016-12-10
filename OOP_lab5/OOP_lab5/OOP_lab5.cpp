// OOP_lab5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Book.h"
#include "Controller.h"
#include "Library.h"
#include "Magazine.h"
#include "SclB.h"
#include "Cheker.h"
#include "locale"

Cheker *Cheker::head = nullptr;

int main()
{
	setlocale(LC_ALL, "rus");
	Book sl1("The big boom", 40,1999);
	Sclb st1("Mathematics", 25);
	Mag in1("For women", 45);
	Book sl2("Wolverine", 35, 2006);
	Sclb st2("Literature", 20);
	Mag in2("For men", 40);
	Controller::Add(&sl1);
	Controller::Add(&sl2);
	Controller::Add(&st1);
	Controller::Add(&st2);
	Controller::Add(&in1);
	Controller::Add(&in2);
	cout << "Show list:" << endl;
	Controller::Show();
	cout << "Enter year of Book: ";
	int year1;
	cin >> year1;
	cout << "Show Book =< year1: " << endl;
	Controller::SearchNames(year1);
	cout << "Show ";
	Controller::KolStud();
	Controller::cost();
	
    return 0;
}

