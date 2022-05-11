#define _CRT_SECURE_NO_WARNINGS 1
/*
链接：https://www.nowcoder.com/questionTerminal/e8fb8f89f5d147ec92fd8ecfefe89b0d
来源：牛客网

一个正整数可以分解成一个或多个数组的积。例如36=2*2*3*3，即包含2和3两个因子。
NowCoder最近在研究因子个数的分布规律，现在给出一系列正整数，他希望你开发一个程序输出每个正整数的因子个数
*/

// write your code here cpp
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        //数太大，用平方根
        int count = 0;
        for (int i = 2; i <= sqrt(n); i++)
        {
            //能够被除开
            if (n % i == 0)
            {
                //直到出现不同的因子，
                //比如，36 % 2 = 18 % 2 = 9 9 % 2 != 0 结束本次循环
                while (n % i == 0)
                {
                    n /= i;
                }
                count++;
            }
        }
        //比如7，除了自身能除就没了
        if (n != 1)
        {
            count++;
        }
        cout << count << endl;
    }
    return 0;
}