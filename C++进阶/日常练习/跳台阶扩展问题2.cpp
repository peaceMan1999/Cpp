/*

链接：https://www.nowcoder.com/questionTerminal/953b74ca5c4d44bb91f39ac4ddea0fee
来源：牛客网

一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶(n为正整数)总共有多少种跳法。

数据范围：1 \le n \le 201≤n≤20
进阶：空间复杂度 O(1)O(1) ， 时间复杂度 O(1)O(1)

输入描述:
本题输入仅一行，即一个整数 n


输出描述:
输出跳上 n 级台阶的跳法

*/

#include <iostream>

using namespace std;

int main()
{
    int floor[21] = { 0 };
    floor[1] = 1;
    for (int i = 2; i <= 20; i++)
        floor[i] = 2 * floor[i - 1];

    int n;
    while (cin >> n)
    {
        cout << floor[n] << endl;
    }

    return 0;
}


