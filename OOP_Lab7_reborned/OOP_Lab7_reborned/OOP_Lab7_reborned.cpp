// OOP_Lab7_reborned.cpp: определяет точку входа для консольного приложения.
//


#include "stdafx.h"
#include <iostream>
using namespace std;
class List
{
public:
	int x1;
	List();
	void SetParm();
	~List();
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
	out << obj.x1 << endl;

	return out;
}

template <typename lt>
class Plist
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
		newElement->next = head;
		head = newElement;
		size++;
		return 0;
	}

	lt operator --() {
		if (!head)
		{
			std::cout << "List is empty" << std::endl;
			return -1;
		}
		cout << "Poped element: " << head->value << endl;
		return 0;
	}

	friend lt operator >(Plist &A, Plist &B)
	{
		B = A;
		return B;
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
		std::cout << "List is empty." << std::endl;
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
			for (int i = 0; i < x+1; i++)
			{
				head = head->next;
				if (head->next == nullptr)break;
			}
			
			
		
	}
}

int main()
{


	setlocale(LC_ALL, "Russian");
	cout << "Cтек А (int)" << endl;

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

	system("pause");
	return 0;
}



