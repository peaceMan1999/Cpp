#define _CRT_SECURE_NO_WARNINGS 1

/*
快到碗里来 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【快到碗里来】小喵们很喜欢把自己装进容器里的（例如碗），但是要是碗的周长比喵的身长还短，它们就进不去了。
现在告诉你它们的身长，和碗的半径，请判断一下能否到碗里去。

输入有多组数据。
每组数据包含两个整数n (1≤n≤2^128) 和r (1≤r≤2^128)，分别代表喵的身长和碗的半径。
圆周率使用3.14。
对应每一组数据，如果喵能装进碗里就输出“Yes”；否则输出“No”。
*/

#include <iostream>
using namespace std;
bool CanIn(double cat, double boalNum)
{
	return cat <= boalNum;
}
int main()
{
	double cat, boal;
	while (cin >> cat >> boal)
	{
		double boalNum = 2 * (3.14) * boal;
		bool right = CanIn(cat, boalNum);
		if (right == true)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}