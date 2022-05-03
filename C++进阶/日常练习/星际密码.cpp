#define _CRT_SECURE_NO_WARNINGS 1

/*
牛客网的题大多都是小作文，这道题后我终于忍不住了;
虽然可能是因为我基础不好，但是这不妨碍我认为牛客网就是个大 X X！！

[编程题]星际密码

链接：https://www.nowcoder.com/questionTerminal/34f17d5f2a8240bea661a23ec095a062
来源：牛客网

星际战争开展了100年之后，NowCoder终于破译了外星人的密码！他们的密码是一串整数，通过一张表里的信息映射成最终4位密码。表的规则是：n对应的值是矩阵X的n次方的左上角，如果这个数不足4位则用0填充，如果大于4位的则只输出最后4位。
|1 1|^n => |Xn ..|
|1 0|      |.. ..|
例如n=2时，
|1 1|^2 => |1 1| * |1 1| => |2 1|
|1 0|      |1 0|   |1 0|    |1 1|
即2对应的数是“0002”。

*/

// write your code here cpp
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int main()
{
    vector<int> vv(10000, 0);
    vv[1] = 1, vv[2] = 2;
    //其实左上角的值是一个斐波那契数列
    for (int i = 3; i < 10001; i++)
    {
        vv[i] = vv[i - 1] + vv[i - 2];
        //题目要求大于10000取小4位
        vv[i] %= 10000;
    }

    //开始输入
    int n;
    //输入几次
    while (cin >> n)
    {
        //接着输入第几位
        int k;
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            printf("%04d", vv[k]);
        }
        cout << endl;
    }

    return 0;
}