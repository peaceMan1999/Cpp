#define _CRT_SECURE_NO_WARNINGS 1

/*

����������������������1�ĸ�����
����һ�����������������ڶ������µ�1�ĸ�����
ע������������������������
���ݷ�Χ��
����������
���������
ʾ��1��

����
5
���
2
����������������1�ĸ���

*/

#include <iostream>
using namespace std;
int GetNum(int n)
{
	int count = 0;
	for (int i = 0; i < 32; i++)
	{
		if (n & (1 << i))
			count++;
	}
	return count;
}
int main()
{
	int num, count;
	while (cin >> num)
	{
		count = GetNum(num);
		cout << count << endl;
	}
	return 0;
}