#define _CRT_SECURE_NO_WARNINGS 1

/*
���ӣ�https://www.nowcoder.com/questionTerminal/5017fd2fc5c84f78bbaed4777996213a
��Դ��ţ����

��һ�䳤���εķ��ӣ��������˺�ɫ����ɫ������ɫ�������δ�ש����վ������һ���ɫ�Ĵ�ש�ϣ�ֻ�������ڵģ����������ĸ����򣩺�ɫ��ש�ƶ�����дһ�����򣬼������ܹ��ܹ�������ٿ��ɫ�Ĵ�ש��

��������:
��������������ݡ�

ÿ�����ݵ�һ������������ m �� n��1��m, n��20���������� m �У�ÿ�а��� n ���ַ���ÿ���ַ���ʾһ���ש����ɫ���������£�

1. ��.������ɫ�Ĵ�ש��
2. ��#������ɫ�Ĵ�ש��
3. ��@������ɫ�Ĵ�ש��������վ������ש�ϡ����ַ���ÿ�����ݼ�����Ψһ����һ�Ρ�
*/

// write your code here cpp
#include <iostream>
#include <vector>
using namespace std;

// ������ȱ����㷨 dfs�㷨

int step[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

void walk(vector<vector<char>>& map, int m, int n, int x, int y, int& count)
{
    // ���ӷ���
    if (map[x][y] == '#')
        return;

    // ����������
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
        // �����ש
        vector<vector<char>> map(m, vector<char>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> map[i][j];
            }
        }
        // �ҵ����ڵ�λ��
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
        // ��ʼ������ȱ���
        int count = 0;
        walk(map, m, n, x, y, count);
        cout << count << endl;
    }
    return 0;
}