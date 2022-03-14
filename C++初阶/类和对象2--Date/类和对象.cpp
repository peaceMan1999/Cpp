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

void test3()
{
	Date d1(2021, 1, 2);
	d1.print();
	//d1 -= 3;
	//d1.print();
	//Date d2(2021, 10, 22);
	//cout << (d1 > d2) << endl;

	d1 -= -30;
	d1.print();
}

void test4()
{
	//d1 > d2
	Date d1(2022, 2, 18);
	Date d2(2022, 2, 17);
	//d3 == d4
	Date d3(2022, 1, 1);
	Date d4(2022, 1, 1);
	//d5 < d6
	Date d5(2022, 2, 17);
	Date d6(2022, 2, 18);


	cout << (d1 > d2) << endl;
	cout << (d3 == d4) << endl;
	cout << (d5 < d6) << endl;

}

void test5()
{
	Date d1(2020, 2, 29);
	//++d1;
	//d1.print();
	
	//d1++;
	//d1.print();
	
	Date d2(2020, 2, 15);
	cout << (d1 - d2) << endl;
}

int main()
{

	//test1();
	//test2();
	//test3();
	//test4();
	test5();

	return 0;
}