#define _CRT_SECURE_NO_WARNINGS 1

/*
���⣺ͳ��ÿ�������ӵ����� | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K | �������ƣ� ����
��ͳ��ÿ�������ӵ�������
��һ�����ӣ��ӳ������3������ÿ���¶���һֻ���ӣ�С���ӳ����������º�ÿ��������һֻ���ӡ�
���ӣ�����һֻ���ӵ�3���³�������ô����5���¿�ʼ��ÿ������һֻ���ӡ�
һ�µ�ʱ����һֻ���ӣ��������Ӷ��������ʵ�n���µ���������Ϊ���٣�
*/

#include <iostream>
#include <vector>
using namespace std;
void GetCount(int i, int month, vector<int>& vv)
{
	for (int j = i + 2; j <= month; j++)
	{
		vv[j]++;
	}
}
int main()
{
	int n;
	vector<int> vv;
	while (cin >> n)
	{
		vv.resize(n + 1, 0);
		vv[1] = 1;//��һ������1ֻ
		for (int i = 1; i < vv.size(); i++)
		{
			if (vv[i] != 0)
			{
				for (int j = 0; j < vv[i]; j++)
				{
					GetCount(i, n, vv);
				}
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < vv.size(); i++)
	{
		sum += vv[i];
	}
	cout << sum << endl;
	return 0;
}
