#define _CRT_SECURE_NO_WARNINGS 1

/*  1

���������һ��ż����ӽ�������������
����һ��ż��������2����������2��������ɣ����ż����2�������кܶ������������ĿҪ��������ָ��ż��������������ֵ��С�������ԡ�
����:
	20
���:
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

��С��������������������С������������������С������Ϊ���ܱ���������ͬʱ��������С������

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
	//���Լ�� = a*b / ��С������
	//��С����������b
	cout << a / gcd(a, b) * b << endl;

	return 0;
}