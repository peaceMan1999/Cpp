#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

class test
{
public:

	void add();

	int a = 10;

	char b = '2';

};

void test::add(void)
{
	printf("1");
}

int main()
{
	test st;
	st.add();
	cout << st.a << endl;
	cout << st.b << endl;

	return 0;
}