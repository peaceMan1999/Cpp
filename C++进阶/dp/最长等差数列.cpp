/*
给你一个整数数组 nums，返回 nums 中最长等差子序列的长度。

回想一下，nums 的子序列是一个列表 nums[i1], nums[i2], ..., nums[ik] ，且 0 <= i1 < i2 < ... < ik <= nums.length - 1。并且如果 seq[i+1] - seq[i]( 0 <= i < seq.length - 1) 的值都相同，那么序列 seq 是等差的。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/longest-arithmetic-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int dp[1010][1010];
        memset(dp, 0, sizeof(dp));
        int n = nums.size();
        int maxf = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                int d = nums[i] - nums[j] + 500;
                dp[i][d] = dp[j][d] + 1;
                maxf = max(maxf, dp[i][d]);
            }
        }
        return maxf + 1;
    }
};

