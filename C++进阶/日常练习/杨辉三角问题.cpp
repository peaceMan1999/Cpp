#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

/*

���������ε����󣬵�һ��ֻ��һ����1������ÿ�е�ÿ��������ǡ������������������Ͻ��������Ͻǵ�����3����֮�ͣ����������ĳ��������Ϊ��������0����

���n�е�һ��ż�����ֵ�λ�á����û��ż���������-1����������3,�����2������4�����3������2�����-1��

*/

int main()
{
    int index[] = { 3, 2, 4, 2 };
    int n;
    while (cin >> n)
    {
        if (n < 3)
            cout << -1 << endl;
        else
        {
            int ret = index[n % 4];
            cout << ret << endl;
        }
    }
    return 0;
}