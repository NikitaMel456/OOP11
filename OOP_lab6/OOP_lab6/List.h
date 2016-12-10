#pragma once




class List 
{
public:
	int x; 
	List *Next; 
	List *Head; 
	List *temp;
	bool rc = true;
	List() { Head = NULL; }
	~List(); 
	void Add(int x); 
	void Show();
	List operator () (const int);
	List operator()(int, int);
	List operator != (int x);
};

