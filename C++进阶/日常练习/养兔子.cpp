#define _CRT_SECURE_NO_WARNINGS 1

/*
һֻ���������ÿ���ܲ���һ̥���ӡ�ÿֻС���ӵĳ�������һ�졣 ĳ��������һֻС���ӣ����ʵ�N���Ժ�������õ�����ֻ���ӡ�

��������:
�������ݰ������飬ÿ��һ�У�Ϊ����n(1��n��90)��
*/

// write your code here cpp
#include <iostream>
using namespace std;

int main()
{
    long long index[91] = { 0 };
    index[1] = 1, index[2] = 2;
    for (int i = 3; i <= 91; i++)
    {
        index[i] = index[i - 1] + index[i - 2];
    }

    int n;
    while (cin >> n)
    {
        cout << index[n] << endl;
    }

    return 0;
}