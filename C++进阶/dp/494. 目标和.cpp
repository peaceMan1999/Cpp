/*
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/target-sum
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        // �����ĺ� -- neg
        // �� = sum - neg
        // target = �� - ���� = sum - neg - neg = sum - 2 * neg;
        int diff = sum - target;
        if (diff < 0 || diff & 1) {
            return 0;
        }
        int neg = (sum - target) / 2, n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(neg + 1, 0));
        // ��ʼ��
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
