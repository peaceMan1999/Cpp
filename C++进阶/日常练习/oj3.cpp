#define _CRT_SECURE_NO_WARNINGS 1

/*

【计算日期到天数转换】
根据输入的日期，计算是这一年的第几天。
保证年份为4位数且日期合法。
进阶：时间复杂度： ，空间复杂度：

示例1：
输入
2012 12 31
输出
366

输入一行，每行空格分割，分别是年，月，日
输出是这一年的第几天

*/

#include <iostream>
using namespace std;

int all_day[13] = { 0, 31, 28, 31, 30 ,31, 30 ,31, 31, 30 ,31, 30 ,31 };

bool DayReally(int year, int month, int day)
{
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))//判断闰年
	{
		all_day[2] = 29;
	}
	if (day < 1 || day > all_day[month])
		return false;
	return true;
}

int GetDay(int year, int month, int day)
{
	int day_size = 0;
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))//判断闰年
	{
		all_day[2] = 29;
	}
	for (int i = 1; i < month; i++)
	{
		day_size += all_day[i];
	}
	day_size += day;
	return day_size;
}

int main()
{
	int _year, _month, _day, day_size;
	while (cin >> _year >> _month >> _day)
	{
		if (_year > 9999)
			return 0;
		if (_month > 12 || _month <= 0)
			return 0;
		if (!DayReally(_year, _month, _day))
			return 0;
		day_size = GetDay(_year, _month, _day);
	}
	cout << day_size << endl;
	return 0;
}