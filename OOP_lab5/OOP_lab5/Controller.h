#pragma once
#include "Cheker.h"
class Controller :public Cheker
{
public:
	Controller() :Cheker()
	{

	};
	static void Show();
	static void Add(Book *);
	static void Add(Mag *);
	static void Add(Sclb *);
	static void SearchNames(int);
	static void KolStud();
	static void cost();
};
