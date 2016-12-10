// OOP_lab6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "List.h"

int main()
{

	
	int N=6; 
	int x; 
	List lst; 

	cout << "N = "; 
	//cin >> N; 

	for (int i = 0; i<N; i++)
	{
		cout << i + 1 << ". x = "; cin >> x; 
		lst.Add(x); 
	}
	cout << "Default list" << endl;
	lst.Show(); 
	cout <<endl<< "Delete third element" << endl;
	
	lst(3);
	lst.Show();
	
	cout << endl;
	cout << "Change element(element,new element)";
	lst(3,3);
	lst.Show();
	cout << endl;
	List *a = new List();
	List *b = new List();
	a->x = 5;
	b->x = 9;
	cout << (a != b) << endl;
	cout << endl;
    return 0;
}

