// OOP_lab8.cpp: определяет точку входа для консольного приложения.
//



#include "stdafx.h"
#include <iostream>
//#define NDEBUG
#include <assert.h>
using namespace std;
class Exeption {};


class Nullptrr :public Exeption {};
class Non :public Exeption {};
class EmptLst :public Exeption {};
class List:public Exeption
{
public:
	int x1;
	List();
	void SetParm();
	~List();
	void Test(int);
};


List::List()
{
	cout << "Konstructor of List" << endl;
}
List::~List()
{
	cout << "Destructor of List" << endl;
}

void List::SetParm()
{
	cout << "Enter PRICE" << endl;
	cin >> x1;
	cout << endl;
}

ostream &operator << (ostream &out, List &obj)
{
	cout << obj.x1 << endl;

	return out;
}

template <typename lt>
class Plist :public Exeption
{
public:
	lt value;
	int size;
	Plist *head, *next;
	Plist();
	operator bool();
	void add(lt x);
	void out();
	lt pop();
	void show(Plist<lt>, lt);
	~Plist();

	template <typename lt>
	lt operator +(lt y)
	{
		Plist *newElement = new Plist;
		newElement->value = y;
		if (y < 0)throw Non();
		newElement->next = head;
		head = newElement;
		size++;
		return 0;
	}

};

template <typename lt>
void Plist<lt>::add(lt x)
{
	Plist  *newElement = new Plist;
	newElement->value = x;
	newElement->next = head;
	head = newElement;
	size++;
}

template <typename lt>
Plist<lt>::Plist()
{
	size = 0;
	head = NULL;
}

template <typename lt>
Plist<lt>::~Plist()
{
}

template <typename lt>
lt Plist<lt>::pop() {
	if (!head) {
		
		return -1;
	}

	lt topValue = head->value;
	head = head->next;
	size--;
	
	cout << "Poped element:" << head->value << endl;
	return topValue;
}

template <typename lt>
Plist<lt>::operator bool()
{
	Plist *temp = head;
	if (temp != 0)
		return true;
	else
		return false;
}

template <typename lt>
void Plist<lt>::out()
{
	Plist *temp = head;
	if (temp == nullptr)throw EmptLst();
	while (temp != NULL)
	{
		cout << temp->value << endl;
		temp = temp->next;
	}
	delete temp;
}

template<typename lt>
void Plist<lt>::show(Plist<lt> A, lt x)
{

	Plist<lt> *temp = A.head;
	while (head->next != nullptr)
	{

		lt topValue = head->value;
		cout << "Poped element:" << head->value << endl;
		for (int i = 0; i < x + 1; i++)
		{
			head = head->next;
			if (head->next == nullptr) {throw Nullptrr(); }
		}
		
	}
}
void List::Test(int x1)
{
	
	assert(x1 > 0);
	cout << "Tsting assert" << endl;
}


int main()
{


	setlocale(LC_ALL, "Russian");
	cout << "Cтек А (int)" << endl;
	try
	{
		Plist <int> A;
		A + 13;
		A + 1;
		A + 2;
		A + 7;
		A + 9;
		A + 55;
		A + 99;
		A + 4;
		A + 63;
		A + 57;
		A + 85;
		A.out();

		cout << "Стек Б (double)" << endl;
		Plist <double> B;

		B.add(1.25);
		B.add(2.25);
		B.add(1.7);
		B.add(6.5);
		B.out();
		A.show(A, 3);
	}

	catch (Nullptrr)
	{
		cout << "head->next==nullptr" << endl;
		for (;;)
			break;
	}
	catch (Non)
	{
		cout << "Parameter less than 0" << endl;
	}
	catch (EmptLst)
	{
		cout << "List is empty" << endl;
	}
	
	int x;
	cout << "Enter testing number" << endl;
	cin >> x;
	List *Y = new List();
	Y->Test(x);

	return 0;
}



