#define _CRT_SECURE_NO_WARNINGS 1

/*
定义一个二维数组 N* M ，如 5 × 5 数组下所示：


int maze[5][5] = {
0, 1, 0, 0, 0,
0, 1, 1, 1, 0,
0, 0, 0, 0, 0,
0, 1, 1, 1, 0,
0, 0, 0, 1, 0,
};


它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，
不能斜着走，要求编程序找出从左上角到右下角的路线。入口点为[0, 0], 既第一格是可以走的路。
*/

#include <iostream>
#include <vector>
using namespace std;

int col, row;
vector<vector<int>> maps;//地图
vector<vector<int>> best_maps;//最佳步数
vector<vector<int>> work;//临时走的步

void WorkMaps(int ROW, int COL)
{
    maps[ROW][COL] = 1;
    work.push_back({ ROW, COL });

    //到终点
    if (ROW == row - 1 && COL == col - 1)
    {
        if (best_maps.empty() || work.size() < best_maps.size())
            best_maps = work;
    }

    //向下走
    if (ROW + 1 < row && maps[ROW + 1][COL] != 1)
        WorkMaps(ROW + 1, COL);
    //向右走
    if (COL + 1 < col && maps[ROW][COL + 1] != 1)
        WorkMaps(ROW, COL + 1);
    //向上走
    if (ROW - 1 >= 0 && maps[ROW - 1][COL] != 1)
        WorkMaps(ROW - 1, COL);
    //向左走
    if (COL - 1 >= 0 && maps[ROW][COL - 1] != 1)
        WorkMaps(ROW, COL - 1);

    maps[ROW][COL] = 0;//恢复路径
    work.pop_back();
}

int main()
{
    while (cin >> row >> col)
    {
        best_maps.clear();
        work.clear();
        maps = vector<vector<int>>(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
                cin >> maps[i][j];
        }

        WorkMaps(0, 0);

        for (int i = 0; i < best_maps.size(); i++)
        {
            cout << '(' << best_maps[i][0] << ',' << best_maps[i][1] << ')' << endl;
        }
    }

    return 0;
}

/*
小东所在公司要发年终奖，而小东恰好获得了最高福利，他要在公司年会上参与一个抽奖游戏，游戏在一个6*6的棋盘上进行，上面放着36个价值不等的礼物，每个小的棋盘上面放置着一个礼物，他需要从左上角开始游戏，每次只能向下或者向右移动一步，到达右下角停止，一路上的格子里的礼物小东都能拿到，请设计一个算法使小东拿到价值最高的礼物。

给定一个6*6的矩阵board，其中每个元素为对应格子的礼物价值,左上角为[0,0],请返回能获得的最大价值，保证每个礼物价值大于100小于1000。
*/

class Bonus {
public:
    int getMost(vector<vector<int> > board) {
        // write code here
        int col = board[0].size();
        int row = board.size();
        vector<vector<int>> vv(col, vector<int>(row, 0));
        vv[0][0] = board[0][0];

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                if (i == 0)//第一行就只能往右走
                    vv[i][j] = vv[i][j - 1] + board[i][j];
                else if (j == 0)//第一列就往下走
                    vv[i][j] = vv[i - 1][j] + board[i][j];
                else
                    vv[i][j] = max(vv[i - 1][j], vv[i][j - 1]) + board[i][j];
            }
        }
        return vv[row - 1][col - 1];
    }
};