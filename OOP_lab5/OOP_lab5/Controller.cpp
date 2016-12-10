#include "stdafx.h"
#include "Controller.h"


void Controller::Show()
{
	Book *pi1 = nullptr;
	Mag *psl1 = nullptr;
	Sclb *pss1 = nullptr;
	Cheker *p = Controller::head;
	while (p)
	{
		switch (p->kind)
		{
		case 0: pi1 = (Book *)p->adress;
			pi1->Show();
			break;
		case 1: psl1 = (Mag *)p->adress;
			psl1->Show();
			break;
		case 2: pss1 = (Sclb *)p->adress;
			pss1->Show();
			break;
		}
		p = p->next;
	}
}

void Controller::Add(Book * addr)
{
	if (head == nullptr)
	{
		head = new Cheker();
		head->next = nullptr;
		head->adress = addr;
		head->kind = 0;
	}
	else
	{
		Cheker* p = head;
		while (p->next != nullptr)
		{
			p = p->next;
		}
		p->next = new Cheker();
		p->next->next = nullptr;
		p->next->adress = addr;
		p->next->kind = 0;
	}
}

void Controller::Add(Mag * addr)
{
	if (head == nullptr)
	{
		head = new Cheker();
		head->next = nullptr;
		head->adress = addr;
		head->kind = 1;
	}
	else
	{
		Cheker* p = head;
		while (p->next != nullptr)
		{
			p = p->next;
		}
		p->next = new Cheker();
		p->next->next = nullptr;
		p->next->adress = addr;
		p->next->kind = 1;
	}
}

void Controller::Add(Sclb * addr)
{
	if (head == nullptr)
	{
		head = new Cheker();
		head->next = nullptr;
		head->adress = addr;
		head->kind = 2;
	}
	else
	{
		Cheker* p = head;
		while (p->next != nullptr)
		{
			p = p->next;
		}
		p->next = new Cheker();
		p->next->next = nullptr;
		p->next->adress = addr;
		p->next->kind = 2;
	}
}

void Controller::SearchNames(int year1)
{

	Book *psl1 = nullptr;
	Cheker *p = Cheker::head;
	while (p)
	{
		psl1 = (Book*)p->adress;
		if (psl1->Getyear() >= year1)
		{
			psl1->Show();
		}
		p = p->next;
	}
}
void Controller::KolStud()
{
	int kolstud = 0;
	Cheker *p = Cheker::head;
	while (p)
	{
		
			kolstud++;
		p = p->next;
	}
	cout << "Number of publishings: " << kolstud << endl;
}
 
void Controller::cost()
{
	int sum = 0;
	Cheker *p = Cheker::head;
	Book *psl=nullptr;
	while (p)
	{
		psl = (Book*)p->adress;
		sum =sum + (psl->price);
		p = p->next;
	}
	cout << "Common cost: " << sum << endl;
}