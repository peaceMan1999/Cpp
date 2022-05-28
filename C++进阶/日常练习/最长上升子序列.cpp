#define _CRT_SECURE_NO_WARNINGS 1

/*
链接：https://www.nowcoder.com/questionTerminal/d83721575bd4418eae76c916483493de
来源：牛客网

广场上站着一支队伍，她们是来自全国各地的扭秧歌代表队，现在有她们的身高数据，请你帮忙找出身高依次递增的子序列。
例如队伍的身高数据是（1、7、3、5、9、4、8），其中依次递增的子序列有（1、7），（1、3、5、9），（1、3、4、8）等，其中最长的长度为4。

输入描述:
输入包含多组数据，每组数据第一行包含一个正整数n（1≤n≤1000）。

紧接着第二行包含n个正整数m（1≤n≤10000），代表队伍中每位队员的身高。

7
1 7 3 5 9 4 8

// 感觉经典

*/

// write your code here cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> d(n);
        for (int i = 0; i < n; i++)
        {
            cin >> d[i];
        }
        // 存最多子序列
        int result = 1;
        vector<int> index(n, 1);
        // 从第二位开始，比较前面的大小
        // 7 和 1 比， 下一个循环
        // 3:1 3:7 下 5:1 5:7 5:3 ...
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (d[i] > d[j])
                    index[i] = max(index[i], index[j] + 1);
            }
            result = max(index[i], result);
        }
        cout << result << endl;
    }

    return 0;
}