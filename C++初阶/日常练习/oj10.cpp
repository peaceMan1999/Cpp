#define _CRT_SECURE_NO_WARNINGS 1

/*

���⣺����������� | ʱ�����ƣ�3�� | �ڴ����ƣ�32768K | �������ƣ� [Python, C++, C#, Java]
������������ȡ�
��һ����������������Ľ�㰴�����һ��һ��ش������ұ�ţ��������Ϊ1���ָ���a��bΪ������㡣���һ���㷨������a��b����Ĺ������ȵı�š�ע��
������Ҳ�����ǽ�㱾��

*/

class LCA {
public:
	int getLCA(int a, int b) {
		int p1, p2, c1, c2;//parent,child
		if (a > b) //ȷ��b > a
		{
			int tmp = a;
			a = b;
			b = tmp;
		}
		c1 = a, c2 = b, p1 = a, p2 = b;
		while (p1 != p2)
		{
			if (p1 < p2)
			{
				if (c2 % 2 == 0)
					c2++;
				p2 = (c2 - 1) / 2;
				c2 = p2;
			}
			else
			{
				if (c1 % 2 == 0)
					c1++;
				p1 = (c1 - 1) / 2;
				c1 = p1;
			}
		}
		return p1;
	}
};

/*
���⣺���������bit�� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K | �������ƣ� ����
�����������bit����
��һ��int�������ֶ�Ӧ�Ķ�����������1�����������������3�Ķ�����Ϊ00000011���������2��1
*/

#include <iostream>
using namespace std;
int main()
{
	int num;
	cin >> num;
	int count = 0, max = 0, n = 0;
	for (int i = 0; i < 32; i++)
	{
		if ((1 << i) & num)
			count++, n = 1;
		else
			n = 0;
		if (n == 1 && count > max)
			max = count;
		else if (n == 0)
			count = 0;
	}
	cout << max << endl;
	return 0;
}
