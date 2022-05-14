#define _CRT_SECURE_NO_WARNINGS 1

/*
���ӣ�https://www.nowcoder.com/questionTerminal/d95d98a2f96e49078cd7df84ba0c9d79
��Դ��ţ����

���й��Ľ��ղ�ͬ�������Ľڼ���ͨ����ѡ��ĳ���µĵڼ������ڼ�������ʽ�����ÿһ��ķż����ڶ�����ͬ������������£�
* 1��1�գ�Ԫ��
* 1�µĵ���������һ������·�¡��������
* 2�µĵ���������һ����ͳ��
* 5�µ����һ������һ��������ʿ������
* 7��4�գ���������
* 9�µĵ�һ������һ���Ͷ���
* 11�µĵ��ĸ������ģ��ж���
* 12��25�գ�ʥ����
���ڸ���һ����ݣ������æ���ɵ�����յ����ڡ�
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
    int week = day % 7; // ������ڼ�
    return (week == 0 ? 7 : week);
}
//�ڼ������ڼ�
int GetDay(int y, int m, int n, int e)
{
    int week = Week(y, m, 1);
    int day = 1 + 7 * (n - 1) + (7 - week + e) % 7;
    return day;
}

int GetDay2(int y, int m, int e)
{
    int week = Week(y, m, 1);//���6��1�������ڼ�
    int d = (week == 1 ? 7 : week - 1);
    return 32 - d;
}

int main()
{
    int y;
    while (cin >> y)
    {
        //1��1�գ�Ԫ��
        printf("%d-01-01\n", y);
        //1�µĵ���������һ������·�¡��������
        int day = GetDay(y, 1, 3, 1);
        printf("%d-01-%02d\n", y, day);
        //�µĵ���������һ����ͳ��
        day = GetDay(y, 2, 3, 1);
        printf("%d-02-%02d\n", y, day);
        //5�µ����һ������һ��������ʿ������
        day = GetDay2(y, 6, 1);
        printf("%d-05-%d\n", y, day);
        //7��4�գ���������
        printf("%d-07-04\n", y);
        //9�µĵ�һ������һ���Ͷ���
        day = GetDay(y, 9, 1, 1);
        printf("%d-09-%02d\n", y, day);
        //11�µĵ��ĸ������ģ��ж���
        day = GetDay(y, 11, 4, 4);
        printf("%d-11-%02d\n", y, day);
        //12��25�գ�ʥ����
        printf("%d-12-25\n", y);
        cout << endl;
    }

    return 0;
}