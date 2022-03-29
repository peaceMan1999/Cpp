#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <functional>
#include "queue.h"
#include "Priority_queue.h"
using namespace std;

void test1()
{
	//yz::queue<int, vector<int>> q;
	yz::queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

void Priotity_queue_test()
{
	//priority_queue<int, vector<int>, greater<vector<int>::value_type>> pq;
	//默认是建小堆，greater
	yz::Priotity_queue<int> pq;
	//yz::Priotity_queue<int, vector<int>> pq;
	//yz::Priotity_queue<int, vector<int>, yz::less<int>> pq;
	pq.push(1);
	pq.push(5);
	pq.push(3); 
	pq.push(2);
	pq.push(9);
	pq.push(6);
	pq.push(3);
	pq.push(7);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

//仿函数
template <class T>
struct less
{
	bool operator()(const T& left, const T& right)
	{
		return left < right;
	}
};

int main()
{

	test1();
	Priotity_queue_test();

	return 0;
}