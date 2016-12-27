// Ep3.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "List.h"
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>

using namespace std;

bool Func(List i, List j) { return (i.getparm() < j.getparm()); }

std::ostream &operator<<(std::ostream &stream, vector<List>& obj)
{
	for (int i = 0; i < obj.size(); i++)
		stream << obj[i].getparm() << endl;
	return stream;
}

void One(map<int, List> myMap)
{
	map<int, List>::const_iterator it;

	cout << "Sorting (straight): " << endl;
	for (auto& elem : myMap)
		cout << (elem).first << " : " << (elem).second.getparm() << endl;

	cout << endl << "Sorting (reverse) " << endl;
	it = myMap.cend();
	while (it != myMap.cbegin())
	{
		it--;
		cout << endl << (*it).first << " : " << (*it).second.getparm();
	}
}

void Two(map<int, List> myMap)
{
	cout << endl << "Using [find]: " << endl;
	cout << endl << myMap.find(2)->second.getparm() << endl;

	auto low = myMap.lower_bound(3),
		up = myMap.upper_bound(4);
	myMap.erase(low, up);

	cout << endl << "Using [lower_bund] and [upper_bound]: " << endl;
	for (auto elem : myMap)
		cout << elem.first << " : " << elem.second.getparm() << endl;
}

void Three(map<int, List> myMap, set<List>& mySet)
{
	for (auto itMyMap = myMap.cbegin(); itMyMap != myMap.cend(); ++itMyMap)
		mySet.insert(itMyMap->second);

	cout << endl << "Show set: " << endl;
	set<List>::const_iterator itSet = mySet.cend();
	while (itSet != mySet.cbegin())
	{
		itSet--;
		cout << itSet->getparm() << endl;
	}
}

void Four(map<int, List> myMap, set<List> mySet)
{
	cout << endl << "Map: " << endl;
	for (auto& elem : myMap)
		cout << elem.first << " : " << elem.second.getparm() << endl;

	cout << endl << "Set: " << endl;
	for (auto& elem : mySet)
		cout << elem.getparm() << endl;
}

void Five(map<int, List> myMap, set<List> mySet, vector<List>& myVector)
{
	for (auto& elem : myMap)
		myVector.push_back(elem.second);

	for (auto& elem : mySet)
		myVector.push_back(elem);

	cout << endl << "Vector: ";
	cout << endl << myVector;
	nth_element(myVector.begin(), myVector.begin() + 2, myVector.end(), Func);
	cout << endl << myVector;
}

void Six(vector<List> myVector)
{
	set<int> myTestSet{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, myTestSet2;
	string nameV = "B";
	int countElements = 0;

	for (auto& elem : myVector)
		if (elem.getparm() == nameV)
			countElements++;
	cout << endl << "Number elements with name " << nameV << " = " << countElements << endl;

	if (find(myVector.begin(), myVector.end(), "B") != myVector.end())
		cout << endl << "Succes,element " << nameV << " found:)" << endl;
	else cout << endl << "Error,element " << nameV << " not found:(" << endl;
	for_each(myTestSet.begin(), myTestSet.end(), [](int _n)
	{
		cout << _n * _n << " ";
	});
	int count = 0;
	set<int>::iterator TestIt;


	cout << endl << "Amount of elements myTestSet: " << count << ".\nAlso myTestSet2 : " << endl;
	for (auto elem : myTestSet2)
		cout << elem++ << " ";
	cout << endl;
}

void Seven()
{
	string s1("N");
	cout << endl << "s1: " << s1;
	string s2;
	string s3(s1);
	string s4(move(s1));
	cout << endl << "s2: " << s2 << " s3: " << s3 << " s4: " << s4
		<< " after move s1: " << s1 << endl;

	s2 = "T R A N S L A T O R";
	s3 = s2.substr(1, 6);
	int pos = s2.find(" O");
	s3 += s2.substr(pos);
	cout << endl << "New s3: " << s3 << endl;
}

void Eight()
{
	int A[] = { 3, 2, 5 };
	set<int> myTestSet{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, myTestSet2;

	cout << endl << "Amount of elements more than number 2 : " <<
		count_if(A, A + 3, bind2nd(greater<int>(), 2));
	cout << endl << "Amount of elements less than number 2 : " <<
		count_if(A, A + 3, not1(bind2nd(greater<int>(), 2)));
	cout << endl;
	struct Aa
	{
		bool operator()(int number)
		{
			return (number % 7) == 0;
		}
	};
	auto it = find_if(myTestSet.begin(), myTestSet.end(), Aa());
	cout << "The first odd value is " << *it << endl;
	for (auto elem : myTestSet2)
		cout << elem++ << " ";
	cout << endl;
}

int main()
{
	List obj1("L");
	List obj2("B");
	List obj3("o");
	List obj4("J");
	List obj5("K");
	List obj6("S");

	map<int, List> myMap = { { 1, obj1 },{ 2, obj2 },{ 3, obj3 },{ 4, obj4 },{ 5, obj5 },{ 6, obj6 } };
	set<List> mySet;
	vector<List> myVector;

	One(myMap);
	Two(myMap);
	Three(myMap, mySet);
	Four(myMap, mySet);
	Five(myMap, mySet, myVector);
	Six(myVector);
	Seven();
	Eight();
	system("pause");
	return 0;
}
