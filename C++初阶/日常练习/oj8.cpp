#define _CRT_SECURE_NO_WARNINGS 1

/*
1，另类加法 

给定两个int A和B。编写一个函数返回A+B的值，但不得使用+或其他算数运算符。

测试样例：
1,2
返回：3
*/

class UnusualAdd {
public:
    int addAB(int A, int B) {
        //求出不进位的数
        int a = A ^ B;
        //求出进位的
        int b = (A & B) << 1;
        if (a == 0) return b;
        if (b == 0) return a;
        return addAB(a, b);
    }
};

/*
2,走方格的方案数

链接：https://www.nowcoder.com/questionTerminal/e2a22f0305eb4f2f9846e7d644dba09b
来源：牛客网

请计算n*m的棋盘格子（n为横向的格子数，m为竖向的格子数）从棋盘左上角出发沿着边缘线从左上角走到右下角，总共有多少种走法，要求不能走回头路，即：只能往右和往下走，不能往左和往上走。

注：沿棋盘格之间的边缘线行走

数据范围： 1 \le n,m \le 8 \1≤n,m≤8
*/
#include <iostream>
using namespace std;

int method(int n, int m)
{
    if (n == 0 || m == 0)
        return 1;
    return method(n - 1, m) + method(n, m - 1);
}

int main()
{
    int n, m;
    cin >> n >> m;

    int count = method(n, m);

    cout << count << endl;
    return 0;
}