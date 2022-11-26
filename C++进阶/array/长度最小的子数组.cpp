/*
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/minimum-size-subarray-sum
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int length = 0;
        int sum = 0;
        int i = 0; // �󴰿�
        for (int j = 0; j < nums.size(); ++j) {
            sum += nums[j];
            while (sum >= target) {
                length = j - i + 1;
                ans = ans < length ? ans : length;
                sum -= nums[i++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
