#define _CRT_SECURE_NO_WARNINGS 1


/*

给定三条边，请你判断一下能不能组成一个三角形。
输入包含多组数据，每组数据包含三个正整数a、b、c（1≤a, b, c≤10^100）。
对应每一组数据，如果它们能组成一个三角形，则输出“Yes”；否则，输出“No”。

*/

#include <iostream>
using namespace std;
#define ADD(X, Y) ((X) + (Y))
#define CMP(X, Y) ((X) > (Y))
int main()
{
    //因为double范围更广
    double a, b, c;
    while (cin >> a >> b >> c)
    {
        if (CMP(ADD(a, b), c) && CMP(ADD(b, c), a) && CMP(ADD(a, c), b))
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }
    return 0;
}