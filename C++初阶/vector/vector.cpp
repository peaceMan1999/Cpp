#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void f1()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	//1.
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	//2.
	vector<int>::iterator it = v1.begin();
	while (it != v1.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	//3.
	for (auto it : v1)
	{
		cout << it << " ";
	}
	cout << endl;

}

//template <class T>
//void PrintVector(const vector<T>& v)
//{
//	//用const修饰需要加const_iterator
//	vector<int>::const_iterator it = v.begin();
//	while (it != v.end())
//	{
//		//*it += 1;
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//}

//template <class T>
//void PrintVector(const vector<T>& v)
//{
//	//用const修饰需要加const_iterator
//	vector<T>::const_iterator it1 = v.begin();
//	while (it1 != v.end())
//	{
//		//*it += 1;
//		cout << *it1 << " ";
//		it1++;
//	}
//	cout << endl;
//}


void f2()
{
//	vector<int> v1;
//	vector<int> v2(10, 1);
//	vector<int> v3(v2.begin(), v2.end());
//
//	string s1("hello");
//	vector<char> v4(s1.begin(), s1.end());
//	//PrintVector(v2);

	vector<string> v5;
	string s1("hello");
	v5.push_back(s1);
	//PrintVector(v5);

	v5.push_back("erase");
	//PrintVector(v5);

	vector<string> copy(v5);


	auto it = v5.begin();
	while (it != v5.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

int main()
{
	//f1();
	f2();
	return 0;
}

