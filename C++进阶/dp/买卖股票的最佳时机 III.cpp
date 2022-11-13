/*
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n][3][2];
        for (int i = 0; i <= 2; ++i)
        {
            dp[0][i][0] = 0;
            dp[0][i][1] = -prices[0];
        }
        for (int i = 1; i < n; ++i)
        {
            dp[i][0][0] = 0;
            dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][0][0] - prices[i]);
            for (int k = 1; k <= 2; ++k)
            {
                dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k - 1][1] + prices[i]);
                dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k][0] - prices[i]);
            }
        }

        return dp[n - 1][2][0];
    }
};

