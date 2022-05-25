#define _CRT_SECURE_NO_WARNINGS 1

/*
链接：https://www.nowcoder.com/questionTerminal/ed9bc679ea1248f9a3d86d0a55c0be10
来源：牛客网

现在有两个好友A和B，住在一片长有蘑菇的由n＊m个方格组成的草地，A在(1,1),B在(n,m)。
现在A想要拜访B，由于她只想去B的家，所以每次她只会走(i,j+1)或(i+1,j)这样的路线，
在草地上有k个蘑菇种在格子里(多个蘑菇可能在同一方格),问：A如果每一步随机选择的话(若她在边界上，则只有一种选择)，
那么她不碰到蘑菇走到B的家的概率是多少？
*/

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

double odds(vector<vector<double>>& step, int n, int m, vector<vector<bool>>& mushroom)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // 上面的几率 * 能来方向的几率 + 左边的几率 * 能来方向的几率
            // 边界就只有 1 种方法
            if (i == 1 && j == 1)
                step[i][j] = 1;
            else
            {
                step[i][j] = step[i - 1][j] * (j == m ? 1 : 0.5) + step[i][j - 1] * (i == n ? 1 : 0.5);
                if (mushroom[i][j] == true)
                    step[i][j] = 0;
            }
        }
    }
    return step[n][m];
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        // 创建向量，多留一个最外层是0
        vector<vector<double>> step(n + 1, vector<double>(m + 1, 0));
        // 创建一个记录蘑菇的向量
        vector<vector<bool>> mushroom(n + 1, vector<bool>(m + 1, false));
        int k;
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            mushroom[x][y] = true;
        }

        double dp = odds(step, n, m, mushroom);
        printf("%.2f\n", dp);
    }
}