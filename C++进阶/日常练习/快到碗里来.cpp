#define _CRT_SECURE_NO_WARNINGS 1

/*
�쵽������ | ʱ�����ƣ�1�� | �ڴ����ƣ�32768K | �������ƣ� ����
���쵽��������С���Ǻ�ϲ�����Լ�װ��������ģ������룩������Ҫ������ܳ������������̣����Ǿͽ���ȥ�ˡ�
���ڸ��������ǵ���������İ뾶�����ж�һ���ܷ�����ȥ��

�����ж������ݡ�
ÿ�����ݰ�����������n (1��n��2^128) ��r (1��r��2^128)���ֱ��������������İ뾶��
Բ����ʹ��3.14��
��Ӧÿһ�����ݣ��������װ������������Yes�������������No����
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