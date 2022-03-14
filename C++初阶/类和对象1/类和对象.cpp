#define _CRT_SECURE_NO_WARNINGS 1

#include "Date.h"

void test1()
{
	Date d1;
	d1.print();

	Date d2(2021, 2, 16);
	d2.print();

	Date d3(2020, 2, 29);
	d3.print();
}

void test2()
{
	Date d1(2021, 2, 16);
	Date d3(d1);
	d1 += 100;
	d1.print();

	Date& d2(d1);
	d2 += 365;
	d2.print();


	Date d4 = d3 + 100;
	d3.print();
	d4.print();

	cout << endl;
	Date d5(d1);
	d5.print();
	//d5 -= 27;
	//d5.print();

	Date d6 = d5 - 27;
	d6.print();
}

int main()
{

	//test1();
	test2();

	return 0;
}