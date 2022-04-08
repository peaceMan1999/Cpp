#define _CRT_SECURE_NO_WARNINGS 1

/*  1

【查找组成一个偶数最接近的两个素数】
任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，本题目要求输出组成指定偶数的两个素数差值最小的素数对。
输入:
	20
输出:
	7
	13
*/

#include <iostream>
using namespace std;
bool is_want(int x)
{
	if (x == 1 || x == 2)
		return true;
	for (int i = x - 1; i > 1; i--)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int val;
	cin >> val;
	int a = val / 2, b = a;
	while (!is_want(a) || !is_want(b))
	{
		a--, b++;
	}
	cout << a << endl;
	cout << b << endl;
	return 0;
}

/*   2

最小公倍数：求两个数的最小公倍数，两个数的最小公倍数为：能被这两个数同时整除的最小的数。

*/

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	int c;
	while ((c = a % b))
	{
		a = b;
		b = c;
	}
	return b;
}

int main()
{
	int a, b;
	cin >> a >> b;
	//最大公约数 = a*b / 最小公倍数
	//最小公倍数就是b
	cout << a / gcd(a, b) * b << endl;

	return 0;
}