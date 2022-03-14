#define _CRT_SECURE_NO_WARNINGS 1

#include "Date.h"

inline int GetMonthDay(int year, int month)
{
	static int DayArray[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((month == 2) && ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)))
	{
		DayArray[2] = 29;
	}
	return DayArray[month];
}

Date::Date(int year, int month, int day)
{
	//检查天数
	if (year >= 0
		&& month > 0 && month < 13
		&& day > 0 && day <= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		_year = 0;
		_month = 1;
		_day = 1;
		cout << "非法日期" << endl;
	}
}

void Date::print()
{
	cout << _year << "年" << _month << "月" << _day << "日" << endl;
}

Date& Date::operator+=(int day)
{
	if (day < 0)
		return *this -= (-day);
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month > 12)
		{
			_month = 1;
			_year++;
		}		
	}
	return *this;
}

Date Date::operator+(int day)
{
	Date ret(*this);
	ret += day; 
	//复用
	return ret;
}

Date& Date::operator-=(int day)
{
	if (day < 0)
		return *this += (-day);
	_day -= day;
	while (_day <= 0)
	{
		_month--;
		if (_month == 0)
		{
			_month = 12;
			_year--;
		}
		_day += GetMonthDay(_year, _month);

	}
	return *this;
}

Date Date::operator-(int day)
{
	Date ret(*this);
	ret -= day;
	//复用
	return ret;
}

// d1 > d2 -> d1.operator>(&d1, d2)
bool Date::operator>(const Date& d)const
{
	if (_year > d._year)
		return true;
	else if (_year == d._year)
	{
		if (_month > d._month)
			return true;
		else if (_month == d._month)
		{
			if (_day > d._day)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

//d1 == d2 -> d1.operator==(&d1, d2)
bool Date::operator==(const Date& d)const
{
	if (_year == d._year && _month == d._month && _day == d._day)
		return true;
	else
		return false;
}

//d1 < d2 -> d1.operator<(&d1, d2)
bool Date::operator<(const Date& d)const
{
	return !(*this == d || *this > d);
}

//d1 < d2 -> d1.operator>=(&d1, d2)
bool Date::operator>=(const Date& d)const
{
	return !(*this < d);
}
//
//d1 < d2 -> d1.operator<=(&d1, d2)
bool Date::operator<=(const Date& d)const
{
	return !(*this > d);
}

//d1 < d2 -> d1.operator!=(&d1, d2)
bool Date::operator!=(const Date& d)const
{
	return !(*this == d);
}

Date& Date::operator++()
{
	return *this += 1;
}

Date Date::operator++(int)
{
	Date tmp = *this;
	tmp += 1;
	return tmp;
}

//d1 - d2
int Date::operator-(const Date& d)
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	
	if (max < min)
	{
		min = *this;
		max = d;
		flag = -1;
	}
	int count = 0;
	while (max != min)
	{
		++min;
		++count;
	}

	return count * flag;
}

