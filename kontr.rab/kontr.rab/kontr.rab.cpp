// kontr.rab.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "classk.h"
#include <iostream>
int main()
{
	Koord lst = { 3, 7, 1 };
	Koord ls = { 3, 1, 1 };
	Koord C;
	Koord X;
	C = lst + ls;
	X = ls - lst;
	std::cout << "C={" << C.x << "," << C.y << "," << C.z << "}" <<std:: endl;
	std::cout << "X={" << X.x << "," << X.y << "," << X.z << "}" << std::endl;
	if (lst == ls) {std:: cout << "lst==ls" << std::endl; }
	if (lst != ls) { std::cout << "lst!=ls" << std::endl; }
    return 0;
}

