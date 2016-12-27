// OOP_Lab9_STL_Part2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "List.h"
#include <iostream>
#include <memory>
#include <algorithm>
#include <queue>
#include <deque>
#include <vector>
#include <locale>
#include <iterator>

using namespace std;


ostream &operator<<(ostream &stream, vector<unique_ptr<List>>& obj)
{
	for (int i = 0; i < obj.size(); i++)
		stream <<obj[i]->getm();
	return stream;
}


typedef vector<unique_ptr<List>> Qptr;
typedef deque<shared_ptr<List>> Nptr;
int main()
{
	cout << "--------------------------------The first---------------------------" << endl;
	Qptr mvec;
	for (int i = 0; i < 5; i++)
	{
		mvec.push_back(make_unique<List>(rand() % 26 + 'A'));
	}
	cout << "Vector ";
	cout << mvec;

	cout << endl;
	cout << "--------------------------------The second---------------------------" << endl;
	int i = 0;
	cout << "Chaned Vector ";
	for (int i = 0; i < 5; i++)
	{
		mvec.pop_back();
	}
	for (int i = 0; i < 5; i++)
	{
		mvec.push_back(make_unique<List>(rand() % 26 + 'A'));
	}
	cout << mvec;
	cout << endl;
	cout << "--------------------------------The third---------------------------" << endl;
	Qptr::const_iterator rtt;
	cout << "Using const iterrator" << endl;
	for (rtt = mvec.cbegin(); rtt != mvec.cend(); rtt++)
		cout << **rtt << " ";
	cout << endl;
	Qptr::reverse_iterator rt;
	cout << "Using reverse_iterator ";
	for (rt = mvec.rbegin(); rt != mvec.rend(); rt++)
		cout << **rt<<" ";
	cout << endl;
	cout << "--------------------------------The forth---------------------------" << endl;
	Nptr mque;
	cout << "Deque ";
	for (int i = 0; i < 5; i++)
		mque.push_back(make_shared<List>(rand() % 26 + 'A'));
	cout << endl;
	Nptr::iterator poi;
	for (poi = mque.begin(); poi != mque.end(); poi++)
	{
		cout << **poi << " ";
	}
	cout << endl;
	cout << "--------------------------------The fifth---------------------------" << endl;
	int n;
	cout << "n must be less than 5" << endl;
	cin >> n;
	cout << "Vector+deque= ";
	for (int i = 0; i < n; i++)
	{
		mvec.pop_back();
	}
	for (rtt = mvec.cbegin(); rtt != mvec.cend(); rtt++)
		cout << **rtt << " ";
	for (poi = mque.begin(); poi != mque.end(); poi++)
	{
		cout << **poi << " ";
	}
	system("pause");
	return 0;
}
