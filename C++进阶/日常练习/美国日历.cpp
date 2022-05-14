#define _CRT_SECURE_NO_WARNINGS 1

/*
链接：https://www.nowcoder.com/questionTerminal/d95d98a2f96e49078cd7df84ba0c9d79
来源：牛客网

和中国的节日不同，美国的节假日通常是选择某个月的第几个星期几这种形式，因此每一年的放假日期都不相同。具体规则如下：
* 1月1日：元旦
* 1月的第三个星期一：马丁·路德·金纪念日
* 2月的第三个星期一：总统节
* 5月的最后一个星期一：阵亡将士纪念日
* 7月4日：美国国庆
* 9月的第一个星期一：劳动节
* 11月的第四个星期四：感恩节
* 12月25日：圣诞节
现在给出一个年份，请你帮忙生成当年节日的日期。
*/

// write your code here cpp
#include <iostream>
#include <stdio.h>
using namespace std;

int date[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

bool diff(int y)
{
    return (y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0));
}

int Day(int y, int m, int e)
{
    int sum = 1;
    for (int i = 0; i < m - 1; i++)
    {
        sum += date[i];
    }
    if (m > 2 && diff(y))
        sum += 1;
    return sum;
}

int Week(int y, int m, int e)
{
    int day = (y - 1) + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400 + Day(y, m, 1);
    int week = day % 7; // 求出星期几
    return (week == 0 ? 7 : week);
}
//第几个星期几
int GetDay(int y, int m, int n, int e)
{
    int week = Week(y, m, 1);
    int day = 1 + 7 * (n - 1) + (7 - week + e) % 7;
    return day;
}

int GetDay2(int y, int m, int e)
{
    int week = Week(y, m, 1);//求出6月1号是星期几
    int d = (week == 1 ? 7 : week - 1);
    return 32 - d;
}

int main()
{
    int y;
    while (cin >> y)
    {
        //1月1日：元旦
        printf("%d-01-01\n", y);
        //1月的第三个星期一：马丁·路德·金纪念日
        int day = GetDay(y, 1, 3, 1);
        printf("%d-01-%02d\n", y, day);
        //月的第三个星期一：总统节
        day = GetDay(y, 2, 3, 1);
        printf("%d-02-%02d\n", y, day);
        //5月的最后一个星期一：阵亡将士纪念日
        day = GetDay2(y, 6, 1);
        printf("%d-05-%d\n", y, day);
        //7月4日：美国国庆
        printf("%d-07-04\n", y);
        //9月的第一个星期一：劳动节
        day = GetDay(y, 9, 1, 1);
        printf("%d-09-%02d\n", y, day);
        //11月的第四个星期四：感恩节
        day = GetDay(y, 11, 4, 4);
        printf("%d-11-%02d\n", y, day);
        //12月25日：圣诞节
        printf("%d-12-25\n", y);
        cout << endl;
    }

    return 0;
}