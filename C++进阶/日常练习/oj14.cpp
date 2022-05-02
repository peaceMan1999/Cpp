#define _CRT_SECURE_NO_WARNINGS 1

/*
标题：统计每个月兔子的总数 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【统计每个月兔子的总数】
有一种兔子，从出生后第3个月起每个月都生一只兔子，小兔子长到第三个月后每个月又生一只兔子。
例子：假设一只兔子第3个月出生，那么它第5个月开始会每个月生一只兔子。
一月的时候有一只兔子，假如兔子都不死，问第n个月的兔子总数为多少？
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
		vv[1] = 1;//第一个月是1只
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
