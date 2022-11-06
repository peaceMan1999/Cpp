/*
来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/JEj789
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
    int dp[110][3];
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        for (int i = 0; i < 3; ++i)
            dp[0][i] = costs[0][i];
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                dp[i][j] = 1000000007;
                for (int k = 0; k < 3; ++k)
                {
                    if (k != j) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + costs[i][j]);
                    }
                }
            }
        }
        return min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
    }
};
