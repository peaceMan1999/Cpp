/*
来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/gaM7Ch
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int MInt = amount + 1;
        vector<int> dp(amount + 1, MInt);
        // 开始循环
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i >= coins[j]) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] >= amount + 1 ? -1 : dp[amount];
    }
};
