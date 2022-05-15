#define _CRT_SECURE_NO_WARNINGS 1

/*
一只成熟的兔子每天能产下一胎兔子。每只小兔子的成熟期是一天。 某人领养了一只小兔子，请问第N天以后，他将会得到多少只兔子。

输入描述:
测试数据包括多组，每组一行，为整数n(1≤n≤90)。
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