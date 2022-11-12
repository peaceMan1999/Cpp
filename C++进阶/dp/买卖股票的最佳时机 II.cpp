/*
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2)  return 0;
        int dp[n][2];
        dp[0][0] = 0;   // �޹�
        dp[0][1] = -prices[0];  // ����--�й�
        for (int i = 1; i < n; ++i)
        {
            // ��һ���޹ɴ����й����˴�
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            // ��һ���йɴ󣬻��������
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            cout << dp[i][0] << " " << dp[i][1] << endl;
        }
        return dp[n - 1][0]; // �϶�������
    }
};
