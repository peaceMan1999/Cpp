#define _CRT_SECURE_NO_WARNINGS 1

/*
���ӣ�https://www.nowcoder.com/questionTerminal/ed9bc679ea1248f9a3d86d0a55c0be10
��Դ��ţ����

��������������A��B��ס��һƬ����Ģ������n��m��������ɵĲݵأ�A��(1,1),B��(n,m)��
����A��Ҫ�ݷ�B��������ֻ��ȥB�ļң�����ÿ����ֻ����(i,j+1)��(i+1,j)������·�ߣ�
�ڲݵ�����k��Ģ�����ڸ�����(���Ģ��������ͬһ����),�ʣ�A���ÿһ�����ѡ��Ļ�(�����ڱ߽��ϣ���ֻ��һ��ѡ��)��
��ô��������Ģ���ߵ�B�ļҵĸ����Ƕ��٣�
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
            // ����ļ��� * ��������ļ��� + ��ߵļ��� * ��������ļ���
            // �߽��ֻ�� 1 �ַ���
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
        // ��������������һ���������0
        vector<vector<double>> step(n + 1, vector<double>(m + 1, 0));
        // ����һ����¼Ģ��������
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