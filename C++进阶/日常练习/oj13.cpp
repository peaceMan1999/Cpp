#define _CRT_SECURE_NO_WARNINGS 1

/*
����һ����ά���� N* M ���� 5 �� 5 ��������ʾ��


int maze[5][5] = {
0, 1, 0, 0, 0,
0, 1, 1, 1, 0,
0, 0, 0, 0, 0,
0, 1, 1, 1, 0,
0, 0, 0, 1, 0,
};


����ʾһ���Թ������е�1��ʾǽ�ڣ�0��ʾ�����ߵ�·��ֻ�ܺ����߻������ߣ�
����б���ߣ�Ҫ�������ҳ������Ͻǵ����½ǵ�·�ߡ���ڵ�Ϊ[0, 0], �ȵ�һ���ǿ����ߵ�·��
*/

#include <iostream>
#include <vector>
using namespace std;

int col, row;
vector<vector<int>> maps;//��ͼ
vector<vector<int>> best_maps;//��Ѳ���
vector<vector<int>> work;//��ʱ�ߵĲ�

void WorkMaps(int ROW, int COL)
{
    maps[ROW][COL] = 1;
    work.push_back({ ROW, COL });

    //���յ�
    if (ROW == row - 1 && COL == col - 1)
    {
        if (best_maps.empty() || work.size() < best_maps.size())
            best_maps = work;
    }

    //������
    if (ROW + 1 < row && maps[ROW + 1][COL] != 1)
        WorkMaps(ROW + 1, COL);
    //������
    if (COL + 1 < col && maps[ROW][COL + 1] != 1)
        WorkMaps(ROW, COL + 1);
    //������
    if (ROW - 1 >= 0 && maps[ROW - 1][COL] != 1)
        WorkMaps(ROW - 1, COL);
    //������
    if (COL - 1 >= 0 && maps[ROW][COL - 1] != 1)
        WorkMaps(ROW, COL - 1);

    maps[ROW][COL] = 0;//�ָ�·��
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
С�����ڹ�˾Ҫ�����ս�����С��ǡ�û������߸�������Ҫ�ڹ�˾����ϲ���һ���齱��Ϸ����Ϸ��һ��6*6�������Ͻ��У��������36����ֵ���ȵ����ÿ��С���������������һ���������Ҫ�����Ͻǿ�ʼ��Ϸ��ÿ��ֻ�����»��������ƶ�һ�����������½�ֹͣ��һ·�ϵĸ����������С�������õ��������һ���㷨ʹС���õ���ֵ��ߵ����

����һ��6*6�ľ���board������ÿ��Ԫ��Ϊ��Ӧ���ӵ������ֵ,���Ͻ�Ϊ[0,0],�뷵���ܻ�õ�����ֵ����֤ÿ�������ֵ����100С��1000��
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
                if (i == 0)//��һ�о�ֻ��������
                    vv[i][j] = vv[i][j - 1] + board[i][j];
                else if (j == 0)//��һ�о�������
                    vv[i][j] = vv[i - 1][j] + board[i][j];
                else
                    vv[i][j] = max(vv[i - 1][j], vv[i][j - 1]) + board[i][j];
            }
        }
        return vv[row - 1][col - 1];
    }
};