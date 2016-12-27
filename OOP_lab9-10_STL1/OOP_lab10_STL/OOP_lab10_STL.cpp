#include "stdafx.h"
#include <iostream>
#include <queue>  
#include <locale>
#include <iterator>
#include <vector>
#include <list>
using namespace std;


void printQ(priority_queue<char> myQueue)
{
	priority_queue<char> qq = myQueue;
	while (!qq.empty())
	{
		std::cout << qq.top() << " ";
		qq.pop();
	}
}

void printV(vector<char> myvec)
{
	vector<char> qq = myvec;
	while (!qq.empty())
	{
		std::cout << qq.back() << " ";
		qq.pop_back();
	}
}

class Init
{
public:
	Init(initializer_list<char> om) { for (auto itm : om) { prqq.push(itm); } };
	void getInit() { while (!prqq.empty()) { cout << prqq.top() << " "; prqq.pop(); } };
priority_queue<char> prqq;
};


int main()
{
	setlocale(LC_ALL, "rus");
	cout << "--------------The First-------------------------"<< endl;
	priority_queue<char> myQueue;
	for (int i = 0; i < 5; i++)
		myQueue.push(rand() % 26 + 'A');
	std::cout << "Prioreted queue: ";
	printQ(myQueue);

	cout << endl << "-------------------Initializer_lst---------------" << endl;
	priority_queue<char> prqq;
	Init prq = {'A','B','c','D'};
	prq.getInit();

	cout << endl << "----------------The Second-------------------" << endl;
	std::cout<<endl << "Delete queue and change:";
	priority_queue<char> qq;
	while (qq.size()!=5)
	{
		myQueue.pop();
		qq.push(rand() % 26 + 'A');
	}
	printQ(qq);
	cout << endl;

	cout<<endl << "-------------The Third------------------" << endl;
	cout << "Использовал контейнер вектор т.к для приорететной очереди не определены реверсные и константные итераторы" << endl;
	vector<int> vv;
	for (int i = 0; i < 5; i++)
	{
		vv.push_back(rand() % 99);
	}
	vector <int>::iterator rtt;
	cout << "Vector ";
	for (rtt = vv.begin(); rtt != vv.end(); rtt++)
		cout << *rtt << " ";
	cout << endl;
	cout << "Reverse_iterator vector ";
	vector <int>::reverse_iterator rt;
	for (rt = vv.rbegin(); rt != vv.rend(); rt++)
		cout << *rt << " ";
	
	cout <<endl<< "Const_iterator ";
	vector<int>::const_iterator crt;
	for (crt = vv.cbegin(); crt != vv.cend(); crt++)
		cout << *crt<<" ";


	cout<<endl << "--------------------The Fourth-----------------" << endl;
	cout << endl<<"Vector ";
	vector<char> vect;
	for (int i = 0; i < 5; i++)
		vect.push_back(rand() % 26+'A' );
	//printV(vect);
	vector<char>::iterator poi;
	for (poi = vect.begin(); poi != vect.end(); poi++)
	{
		cout << *poi << " ";
	}
	cout << endl << "--------------------The Fifth-----------------" << endl;
	int n;
	cout << "n must be less than 5" << endl;
	cin >> n;
	cout << "PRIORITY_queue + vector= ";
	for (int i = 0; i < n; i++)
		qq.pop();
	for (int j = 0; j < 5; j++)
	{
		
		qq.push(vect[j]);
	}
	printQ(qq);



	system("pause");	
	return 0;
}