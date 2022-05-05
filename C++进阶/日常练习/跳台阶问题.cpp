#define _CRT_SECURE_NO_WARNINGS 1

/*
【跳台阶扩展问题】
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶(n为正整数)总共有多少种跳法。
数据范围：

1 <= n <= 20;
*/

#include <iostream>
using namespace std;

int GetCount(int n)
{
    if (n == 1)
        return 1;
    else
        return GetCount(n - 1) * 2;
}

int main()
{
    //一个台阶有1种，两个台阶2种，3个4种，4个8种，由此可得，f(n) = f(n-1)*2
    int n;
    while (cin >> n)
    {
        cout << GetCount(n) << endl;
    }

    return 0;
}


