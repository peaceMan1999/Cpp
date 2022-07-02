#define _CRT_SECURE_NO_WARNINGS 1

/*
��һ��m\times nm��n�����̵�ÿһ�񶼷���һ�����ÿ�����ﶼ��һ���ļ�ֵ����ֵ���� 0����
����Դ����̵����Ͻǿ�ʼ�ø�����������ÿ�����һ��������ƶ�һ��ֱ���������̵����½ǡ�
����һ�����̼������������ļ�ֵ���������������õ����ټ�ֵ�����
������������һ����ά���飬
[
[1,3,1],
[1,5,1],
[4,2,1]
]
��ô·�� 1��3��5��2��1 �����õ�����ֵ�������ֵΪ12
*/

class Solution {
public:

    int maxValue(vector<vector<int> >& grid) {
        int y = grid[0].size();
        int x = grid.size();
        vector<vector<int>> dp(x, vector<int>(y, 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < x; i++)
        {
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        }
        for (int j = 1; j < y; j++)
        {
            dp[0][j] = grid[0][j] + dp[0][j - 1];
        }

        for (int i = 1; i < x; i++)
        {
            for (int j = 1; j < y; j++)
            {
                dp[i][j] = max(dp[i - 1][j] + grid[i][j], dp[i][j - 1] + grid[i][j]);
            }
        }
        return dp[x - 1][y - 1];
    }
};