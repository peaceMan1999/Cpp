#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

void test1()
{
	string s1;
	string s2("hello world");
	cout << s2 << endl;

	//3�ֱ���
	//1,�±�,���Ա���Ҳ���Ը�

	for (size_t i = 0; i < s2.size(); i++)
	{
		cout << s2[i] << " ";
	}
	cout << endl;

	//2,������
	string::iterator it = s2.begin();

	while (it != s2.end())
	{
		cout << *it++ << " ";
		//it++;
	}
	cout << endl;

	//3,for��Χ
	for (auto e : s2)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test2()
{
	string s1;
	s1.push_back('h');
	s1.push_back('e');
	s1.push_back('l');
	s1.push_back('l');
	s1.push_back('o');
	//cout << s1 << endl;

	s1.append(" ");
	s1.append("yyds");
	cout << s1 << endl;
	
	string s2("!!!");
	s1.append(s2);
	cout << s1 << endl;

	s1 += "new day";
	cout << s1 << endl;

	s1.insert(0, "x");
	cout << s1 << endl;

	s1.insert(3, "xxx");
	cout << s1 << endl;

	s1.erase(0, 1);
	cout << s1 << endl;

	s1.erase(3, 2);
	cout << s1 << endl;

	//���
	//s1.erase();
	//s1.erase(3, 100);
	s1.erase(3);
	cout << s1 << endl;


}

int main()
{
	//test1();
	test2();

	return 0;
}