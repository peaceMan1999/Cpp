/*

定义一个二维数组 N*M ，如 5 × 5 数组下所示：


int maze[5][5] = {
0, 1, 0, 0, 0,
0, 1, 1, 1, 0,
0, 0, 0, 0, 0,
0, 1, 1, 1, 0,
0, 0, 0, 1, 0,
};


它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，要求编程序找出从左上角到右下角的路线。入口点为[0,0],既第一格是可以走的路。


数据范围： 2 \le n,m \le 10 \2≤n,m≤10  ， 输入的内容只包含 0 \le val \le 1 \0≤val≤1

*/

#include <iostream>
#include <vector>
using namespace std;

int row, col;
vector<vector<int>> Map;
vector<vector<int>> Way;
vector<vector<int>> BestWay;

void GetBestWay(int x, int y) {
    Map[x][y] = 1;
    Way.push_back({ x, y });

    if (x == row - 1 && y == col - 1) {
        // 完成路径
        if (BestWay.empty() || BestWay.size() > Way.size()) {
            BestWay = Way;
        }
    }

    // 下
    if (x + 1 < row && Map[x + 1][y] == 0)
        GetBestWay(x + 1, y);
    // 右
    if (y + 1 < col && Map[x][y + 1] == 0)
        GetBestWay(x, y + 1);
    // 左
    if (y - 1 >= 0 && Map[x][y - 1] == 0)
        GetBestWay(x, y - 1);
    // 上走
    if (x - 1 >= 0 && Map[x - 1][y] == 0)
        GetBestWay(x - 1, y);

    // 回溯
    Map[x][y] = 0;
    Way.pop_back();
}


int main() {
    while (cin >> row >> col) {
        Map = vector<vector<int>>(row, vector<int>(col, 0));
        Way.clear();
        BestWay.clear();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> Map[i][j];
            }
        }

        GetBestWay(0, 0);

        for (int i = 0; i < BestWay.size(); i++) {
            cout << "(" << BestWay[i][0] << "," << BestWay[i][1] << ")" << endl;
        }
    }

}

