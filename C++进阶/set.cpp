#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

void test1()
{
	//set<int> s;
	//s.insert(2);
	//s.insert(5);
	//s.insert(4);
	//s.insert(7);
	//s.insert(6);
	//s.insert(3);
	//s.insert(3);


	//set<int>::reverse_iterator it = s.rbegin();
	//while (it != s.rend())
	//{
	//	cout << *it << " ";
	//	it++;
	//}
	//cout << endl;
	//
	//for (auto e : s)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	//set<int>::iterator pos = s.find(7);
	//cout << *pos << endl;
	//s.erase(pos);
	//for (auto e : s)
	//{
	//	cout << e << " ";
	//}

	//multiset<int> s;
	//s.insert(2);
	//s.insert(5);
	//s.insert(4);
	//s.insert(7);
	//s.insert(6);
	//s.insert(3);
	//s.insert(3);
	//s.insert(3);

	////s.erase(s.find(3));

	//multiset<int>::reverse_iterator it = s.rbegin();
	//while (it != s.rend())
	//{
	//	cout << *it << " ";
	//	it++;
	//}
	//cout << endl;

	set<string> s;
	s.insert("first");
	s.insert("second");
	s.insert("third");

	s.erase(s.find("second"));

	set<string>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

}

void test2()
{
	map<int, double> m;
	m.insert(pair<int, double>(1, 1.1));
	m.insert(make_pair(2, 2.2));
	m.insert(make_pair(3, 3.3));
	m.insert(make_pair(3, 3.3));
	m.insert(make_pair(3, 3.3));
	m.insert(make_pair(4, 4.4));
	m.insert(make_pair(5, 5.5));

	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << ' ' << it->second << endl;
		it++;
	}

}

int main()
{
	//test1();
	test2();

	return 0;
}

