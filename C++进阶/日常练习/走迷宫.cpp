#define _CRT_SECURE_NO_WARNINGS 1

/*
���ӣ�https://www.nowcoder.com/questionTerminal/6276dbbda7094978b0e9ebb183ba37b9
��Դ��ţ����

NowCoder��ϲ�����ֳ����Թ���Ϸ������С����Ǳ���˭���߳��Թ���
���ڰ��Թ��ĵ�ͼ���㣬���ܰ����������߳��Թ���Ҫ���ٲ���

��������:
��������������ݡ�

ÿ�����ݰ���һ��10*10���ɡ�#���͡�.����ɵ��Թ������С�#������ǽ����.������ͨ·��

����ڵ�һ�еڶ��У����������һ�еھ��С�

������һ����.���㶼��һ���ߵ����������ĸ�����ġ�.���㡣
*/


// ������ȱ���������

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
    int count; // ����
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
