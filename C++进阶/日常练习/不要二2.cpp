#define _CRT_SECURE_NO_WARNINGS 1

/*

二货小易有一个W*H的网格盒子，网格的行编号为0~H-1，网格的列编号为0~W-1。
每个格子至多可以放一块蛋糕，任意两块蛋糕的欧几里得距离不能等于2。
对于两个格子坐标(x1,y1),(x2,y2)的欧几里得距离为:
( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) ) 的算术平方根
小易想知道最多可以放多少块蛋糕在网格盒子里。

*/

#include <iostream>
#include <vector>

int main()
{
    int W, H;
    std::cin >> H >> W;
    std::vector<std::vector<int>> vv;
    vv.resize(W);
    for (int i = 0; i < W; i++) {
        vv[i].resize(H, 1);
    }

    int count = 0;
    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < H; j++)
        {
            if (vv[i][j] == 1) {
                count++;
                if (i < W - 2) {
                    vv[i + 2][j] = 0;
                }
                if (j < H - 2) {
                    vv[i][j + 2] = 0;
                }
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}



