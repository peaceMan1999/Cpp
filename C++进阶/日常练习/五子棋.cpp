#define _CRT_SECURE_NO_WARNINGS 1

/*
链接：https://www.nowcoder.com/questionTerminal/a811535fed784ea492b63622c28c75c5
来源：牛客网

NowCoder最近爱上了五子棋，现在给你一个棋局，请你帮忙判断其中有没有五子连珠（超过五颗也算）。

输入描述:
输入有多组数据，每组数据为一张20x20的棋盘。

其中黑子用“*”表示，白子用“+”表示，空白位置用“.”表示。


输出描述:
如果棋盘上存在五子连珠（无论哪种颜色的棋子），输入“Yes”，否则输出“No”。
*/


// write your code here cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define N 20

int get(vector<string>& map, int x, int y, char ch)
{
    int walk[4][2][2] = {
    {{-1, 0}, {1, 0}}, // 上下
    {{0, -1}, {0, 1}}, // 左右
    {{-1, -1}, {1, 1}}, // 左上、右下
    {{1, -1}, {-1, 1}}  // 左下、右上
    };

    int index = 0;
    for (int i = 0; i < 4; i++)
    {
        int count = 0;
        for (int j = 0; j < 2; j++)
        {
            int nx = x, ny = y;
            while (nx >= 0 && ny >= 0 && nx < N && ny < N && map[nx][ny] == ch)
            {
                count++;
                nx = nx + walk[i][j][0];
                ny = ny + walk[i][j][1];
            }
        }
        index = max(count, index);
    }
    return index - 1;
}

// 判断横、竖、左上、右上
bool result(vector<string>& map)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == '+' || map[i][j] == '*')
            {
                // 大于5直接结束
                if (get(map, i, j, map[i][j]) >= 5)
                    return true;
            }
        }
    }

    return false;
}

int main()
{
    string str;
    // 先接收第一列
    while (cin >> str)
    {
        vector<string> map(20);
        map[0] = str;
        for (int i = 1; i < N; i++)
        {
            cin >> map[i];
        }

        cout << (result(map) ? "Yes" : "No") << endl;
    }

    return 0;
}