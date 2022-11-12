/*
来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2)  return 0;
        int dp[n][2];
        dp[0][0] = 0;   // 无股
        dp[0][1] = -prices[0];  // 买入--有股
        for (int i = 1; i < n; ++i)
        {
            // 上一个无股大还是有股卖了大
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            // 上一个有股大，还是买入大
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            cout << dp[i][0] << " " << dp[i][1] << endl;
        }
        return dp[n - 1][0]; // 肯定卖出了
    }
};
