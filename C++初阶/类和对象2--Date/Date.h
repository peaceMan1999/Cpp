#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include <iostream>

using std::cout;
using std::endl;

class Date
{
public:
	Date(int year = 0, int month = 1, int day = 1);

	void print();

	Date& operator+=(int day);
	Date operator+(int day);

	Date& operator-=(int day);
	Date operator-(int day);

	bool operator>(const Date& d)const;
	bool operator<(const Date& d)const;
	bool operator>=(const Date& d)const;
	bool operator<=(const Date& d)const;
	bool operator==(const Date& d)const;
	bool operator!=(const Date& d)const;

	Date& operator++();
	Date operator++(int);

	int operator-(const Date& d);

private:
	int _year;
	int _month;
	int _day;

};