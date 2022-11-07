/* 
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/longest-increasing-subsequence
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};