#define _CRT_SECURE_NO_WARNINGS 1

/*
链接：https://www.nowcoder.com/questionTerminal/5017fd2fc5c84f78bbaed4777996213a
来源：牛客网

有一间长方形的房子，地上铺了红色、黑色两种颜色的正方形瓷砖。你站在其中一块黑色的瓷砖上，只能向相邻的（上下左右四个方向）黑色瓷砖移动。请写一个程序，计算你总共能够到达多少块黑色的瓷砖。

输入描述:
输入包含多组数据。

每组数据第一行是两个整数 m 和 n（1≤m, n≤20）。紧接着 m 行，每行包括 n 个字符。每个字符表示一块瓷砖的颜色，规则如下：

1. “.”：黑色的瓷砖；
2. “#”：白色的瓷砖；
3. “@”：黑色的瓷砖，并且你站在这块瓷砖上。该字符在每个数据集合中唯一出现一次。
*/

// write your code here cpp
#include <iostream>
#include <vector>
using namespace std;

// 深度优先遍历算法 dfs算法

int step[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void walk(vector<vector<char>>& map, int m, int n, int x, int y, int& count)
{
    // 白子返回
    if (map[x][y] == '#')
        return;

    // 上下左右走
    if (map[x][y] == '.' || count == 0)
    {
        count++;
        map[x][y] = '#';
        for (int i = 0; i < 4; i++)
        {
            int x1 = x + step[i][0], y1 = y + step[i][1];
            if ((x1 >= 0 && x1 < m) && (y1 >= 0 && y1 < n))
            {
                walk(map, m, n, x1, y1, count);
            }
        }
    }
}

int main()
{
    int m, n;
    while (cin >> m >> n)
    {
        // 导入瓷砖
        vector<vector<char>> map(m, vector<char>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> map[i][j];
            }
        }
        // 找到现在的位置
        int x = 0, y = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (map[i][j] == '@')
                {
                    x = i, y = j;
                    break;
                }
            }
        }
        // 开始深度优先遍历
        int count = 0;
        walk(map, m, n, x, y, count);
        cout << count << endl;
    }
    return 0;
}