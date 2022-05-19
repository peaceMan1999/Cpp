/*
链接：https://www.nowcoder.com/questionTerminal/610e6c0387a0401fb96675f58cda8559
来源：牛客网

今年公司年会的奖品特别给力，但获奖的规矩却很奇葩：
1. 首先，所有人员都将一张写有自己名字的字条放入抽奖箱中；
2. 待所有字条加入完毕，每人从箱中取一个字条；
3. 如果抽到的字条上写的就是自己的名字，那么“恭喜你，中奖了！”
现在告诉你参加晚会的人数，请你计算有多少概率会出现无人获奖？

输入描述:
输入包含多组数据，每组数据包含一个正整数n（2≤n≤20）。
*/
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    //错排问题
    long long index[21] = { 0, 0, 1 };
    long long all[21] = { 1, 1, 2 };
    for (int i = 3; i <= 20; i++)
    {
        index[i] = (i - 1) * (index[i - 1] + index[i - 2]);
        all[i] = all[i - 1] * i;
    }
    int n;
    while (cin >> n)
    {
        printf("%.2f%%\n", 100.0 * index[n] / all[n]);
    }
    return 0;
}