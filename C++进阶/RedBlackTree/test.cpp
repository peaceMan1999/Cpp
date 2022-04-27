#define _CRT_SECURE_NO_WARNINGS 1
#include "RBTreeÄ£°å.h"
#include "Map.h"
#include "Set.h"

int main()
{
	yz::map<int, int> m;
	m.Insert(make_pair(1, 1));
	m.Insert(make_pair(2, 2));
	m.Insert(make_pair(2, 2));
	m.Insert(make_pair(3, 3));

	yz::map<int, int>::reverse_iterator rmit = m.rbegin();
	while (rmit != m.rend())
	{
		cout << rmit->first << ':' << rmit->second << endl;
		++rmit;
	}
	cout << endl;

	//yz::map<int, int>::iterator mit = m.begin();
	//while (mit != m.end())
	//{
	//	cout << (*mit).first << ':' << (*mit).second << " ";
	//	++mit;
	//}
	//cout << endl;

	yz::set<int> s;
	s.Insert(1);
	s.Insert(2);
	s.Insert(2);
	s.Insert(7);
	s.Insert(5);
	s.Insert(3);
	s.Insert(4);

	yz::set<int>::reverse_iterator rsit = s.rbegin();
	while (rsit != s.rend())
	{
		cout << *rsit << " ";
		++rsit;
	}
	cout << endl;

	//yz::set<int>::iterator sit = s.begin();
	//while (sit != s.end())
	//{
	//	cout << *sit << " ";
	//	++sit;
	//}
	//cout << endl;

	yz::map<string, string> dict;
	dict["×ó±ß"];
	dict["ÓÒ±ß"] = "right";

	for (auto& e : dict)
	{
		cout << e.first << ':' << e.second << endl;
	}

	dict["×ó±ß"] = "left";
	dict["ÓÒ±ß"] = "no";

	for (auto& e : dict)
	{
		cout << e.first << ':' << e.second << endl;
	}

	return 0;
}