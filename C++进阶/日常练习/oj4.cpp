#define _CRT_SECURE_NO_WARNINGS 1

/*

【查找输入整数二进制中1的个数】
输入一个正整数，计算它在二进制下的1的个数。
注意多组输入输出！！！！！！
数据范围：
输入描述：
输出描述：
示例1：

输入
5
输出
2
计算整数二进制中1的个数

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