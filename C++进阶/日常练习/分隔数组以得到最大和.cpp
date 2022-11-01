/*
给你一个整数数组 arr，请你将该数组分隔为长度最多为 k 的一些（连续）子数组。分隔完成后，每个子数组的中的所有值都会变为该子数组中的最大值。

返回将数组分隔变换后能够得到的元素最大和。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/partition-array-for-maximum-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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