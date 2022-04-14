#define _CRT_SECURE_NO_WARNINGS 1

/*

���������ڵ�����ת����
������������ڣ���������һ��ĵڼ��졣
��֤���Ϊ4λ�������ںϷ���
���ף�ʱ�临�Ӷȣ� ���ռ临�Ӷȣ�

ʾ��1��
����
2012 12 31
���
366

����һ�У�ÿ�пո�ָ�ֱ����꣬�£���
�������һ��ĵڼ���

*/

#include <iostream>
using namespace std;

int all_day[13] = { 0, 31, 28, 31, 30 ,31, 30 ,31, 31, 30 ,31, 30 ,31 };

bool DayReally(int year, int month, int day)
{
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))//�ж�����
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
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))//�ж�����
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