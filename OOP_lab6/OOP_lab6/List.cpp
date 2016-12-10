#include "stdafx.h"
#include "List.h"

List::~List()
{
	while (Head != NULL)  
	{
		List *temp = Head->Next; 
		delete Head; 
		Head = temp; 
	}
}


void List::Add(int x)
{
	List *temp = new List(); 
	temp->x = x;
	temp->Next = Head; 
	Head = temp; 
}

void List::Show() 
{
	List *temp = Head;


	while (temp != NULL) 
	{
		cout << temp->x << " "; 
		temp = temp->Next; 
	}
}
List List::operator () (const int z)
{
	List *tmp;
	List *temp = Head;
	for (int i = 1; i < z; i++)
	temp = temp->Next; 
	tmp = temp->Next;
	temp->Next = temp->Next->Next;
	delete tmp;
	return *temp;
}
List List::operator()(int z,int x)
{
	List *lst = new List();
	List *temp=Head, *p;
	for (int i = 1; i < z; i++)
		temp = temp->Next; 
	p = temp->Next;
	temp->Next = lst;
	lst->x = x;
	lst->Next = p;
	
	return *lst;
}
List List::operator !=(int x)
{
	
	List *b=new List();
	List *a=new List();
	if (b->x = a->x)
	{
		
		return *b;
	}
	else
	{
		
		return *a;
	}
}
