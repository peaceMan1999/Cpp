#define _CRT_SECURE_NO_WARNINGS 1

/*
链接：https://www.nowcoder.com/questionTerminal/6276dbbda7094978b0e9ebb183ba37b9
来源：牛客网

NowCoder最喜欢游乐场的迷宫游戏，他和小伙伴们比赛谁先走出迷宫。
现在把迷宫的地图给你，你能帮他算出最快走出迷宫需要多少步吗？

输入描述:
输入包含多组数据。

每组数据包含一个10*10，由“#”和“.”组成的迷宫。其中“#”代表墙；“.”代表通路。

入口在第一行第二列；出口在最后一行第九列。

从任意一个“.”点都能一步走到上下左右四个方向的“.”点。
*/


// 广度优先遍历！！！

// write your code here cpp
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct attribute
{
    int x;
    int y;
    int count; // 次数
};

int walk[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int ShortCut(vector<string>& map, int m, int n)
{
    vector<vector<bool>> passed(10, vector<bool>(10, false));
    attribute start = { 0, 1, 0 };
    attribute end = { 9, 8, 0 };
    queue<attribute> que;
    que.push(start);
    while (!que.empty())
    {
        attribute tmp = que.front();
        que.pop();

        passed[tmp.x][tmp.y] = true;

        if (tmp.x == end.x && tmp.y == end.y)
            return tmp.count;

        for (int i = 0; i < 4; i++)
        {
            int nx = tmp.x + walk[i][0];
            int ny = tmp.y + walk[i][1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && passed[nx][ny] != true && map[nx][ny] == '.')
            {
                int ncount = tmp.count + 1;
                attribute ret = { nx, ny, ncount };
                que.push(ret);
            }
        }
    }
    return 0;
}

int main()
{
    vector<string> map(10);
    int i = 0;
    while (cin >> map[i])
    {
        i++;
        if (i == 10)
        {
            cout << ShortCut(map, 10, 10) << endl;
            i = 0;
        }
    }

    return 0;
}
