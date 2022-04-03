#define _CRT_SECURE_NO_WARNINGS 1

/*

标题：最近公共祖先 | 时间限制：3秒 | 内存限制：32768K | 语言限制： [Python, C++, C#, Java]
【最近公共祖先】
将一棵无穷大满二叉树的结点按根结点一层一层地从左往右编号，根结点编号为1。现给定a，b为两个结点。设计一个算法，返回a、b最近的公共祖先的编号。注意
其祖先也可能是结点本身。

*/

class LCA {
public:
	int getLCA(int a, int b) {
		int p1, p2, c1, c2;//parent,child
		if (a > b) //确保b > a
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
标题：求最大连续bit数 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【求最大连续bit数】
求一个int类型数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1
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
