/*
����һ���������� arr�����㽫������ָ�Ϊ�������Ϊ k ��һЩ�������������顣�ָ���ɺ�ÿ����������е�����ֵ�����Ϊ���������е����ֵ��

���ؽ�����ָ��任���ܹ��õ���Ԫ�����͡�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/partition-array-for-maximum-sum
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int sz = arr.size();
        vector<int> dp(sz + 1);

        for (int i = 0; i <= sz; ++i)
        {
            int maxf = 0;
            for (int j = i - 1; j >= 0 && (i - j) <= k; --j)
            {
                maxf = max(maxf, arr[j]);
                dp[i] = max(dp[i], dp[j] + (i - j) * maxf);
            }
        }
        return dp[sz];
    }
};