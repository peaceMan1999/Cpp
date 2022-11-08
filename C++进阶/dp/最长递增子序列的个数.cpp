/*
����һ��δ������������� nums �� ��������������еĸ��� ��

ע�� ������б����� �ϸ� �����ġ�

https://leetcode.cn/problems/number-of-longest-increasing-subsequence/
*/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0), ans(n, 0);
        int maxf = 0, count = 0;
        for (int i = 0; i < n; ++i)
        {
            dp[i] = 0;
            ans[i] = 1;
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j]) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        // ���ô���
                        ans[i] = ans[j];
                    }
                    else if (dp[i] == dp[j] + 1) {
                        ans[i] += ans[j];
                    }
                }
            }
            if (dp[i] > maxf) {
                maxf = dp[i];
                count = ans[i];
            }
            else if (dp[i] == maxf) {
                count += ans[i];
            }
        }

        return count;
    }
};
