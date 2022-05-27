#define _CRT_SECURE_NO_WARNINGS 1

/*
链接：https://www.nowcoder.com/questionTerminal/95e35e7f6ad34821bc2958e37c08918b
来源：牛客网

NowCoder每天要给很多人发邮件。有一天他发现发错了邮件，把发给A的邮件发给了B，把发给B的邮件发给了A。
于是他就思考，要给n个人发邮件，在每个人仅收到1封邮件的情况下，有多少种情况是所有人都收到了错误的邮件？
即没有人收到属于自己的邮件。

输入描述:
输入包含多组数据，每组数据包含一个正整数n（2≤n≤20）。
*/

// write your code here cpp
#include <iostream>
#include <vector>
using namespace std;

// 经典错排问题

int main()
{
    int n;
    vector<long long> f(21, 0);
    f[1] = 0, f[2] = 1, f[3] = 2;
    for (int i = 4; i < 21; i++)
    {
        f[i] = (i - 1) * (f[i - 1] + f[i - 2]);
    }
    while (cin >> n)
    {
        cout << f[n] << endl;
    }

    return 0;
}