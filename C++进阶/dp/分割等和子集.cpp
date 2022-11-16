/*
����һ���ǿյ����������� nums �����ж��ܷ���Щ���ֳַ�Ԫ�غ���ȵ������֡�
https://leetcode.cn/problems/NUPfPr/
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return false;
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxf = *max_element(nums.begin(), nums.end());

        if (sum & 1) {
            return false;
        }
        int tagert = sum / 2;

        if (maxf > tagert) {
            return false;
        }
        vector<vector<bool>> dp(n, vector<bool>(tagert + 1, false));
        for (int i = 0; i < n; ++i)
        {
            dp[i][0] = true; // ������
        }
        // ��ʼ����
        dp[0][nums[0]] = true; // ��һ�������ȷ�
        for (int i = 1; i < n; ++i) {
            int num = nums[i];
            for (int j = 1; j <= tagert; ++j) {
                if (num < j) {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][tagert];
    }
};
