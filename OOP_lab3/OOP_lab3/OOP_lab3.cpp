// OOP_lab3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Person.h"
#include "Turner.h"
#include "Armed.h"
#include "Engineer.h"
#include "Worker.h"

int main()
{
	setlocale(LC_CTYPE, "rus");
	setlocale(LC_ALL, "rus");
	Person a; 
	a.setname("Max Perner"); 
	a.getname();
	cout << endl;
	Armed b;
	b.setname("Mark Avreliy");
	a.getname();
	b.setRank("General"); 
	b.getRank();
	cout << endl;
	Worker c; 
	c.setname("Alexis Sanches"); 
	c.getname(); 
	c.setname("qwe"); 
	c.getYear();
	cout << endl;
	Engineer d; 
	d.setname("Emil Fabiano"); 
	d.getname(); 
	d.setSphere("Machines");  
	d.getSphere();
	cout << endl;
	Turner e;
	e.setname("Marko Reus");
	e.getname();
	e.setSphere("Machines");
	e.getSphere();
	e.setQualification("Main turner");
	e.getQualification();
	cout << endl;
    return 0;
}

