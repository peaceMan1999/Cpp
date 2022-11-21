/*
来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/target-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        // 负数的和 -- neg
        // 正 = sum - neg
        // target = 正 - 负数 = sum - neg - neg = sum - 2 * neg;
        int diff = sum - target;
        if (diff < 0 || diff & 1) {
            return 0;
        }
        int neg = (sum - target) / 2, n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(neg + 1, 0));
        // 初始化
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j <= neg; ++j)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i - 1]) {
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][neg];
    }
};
