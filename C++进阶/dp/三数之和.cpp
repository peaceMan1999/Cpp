/*
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/3sum
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> dp;

        for (int i = 0; i < n; ++i)
        {
            if (nums[i] > 0) {
                return dp;
            }
            // ȥ��
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                }
                else if (nums[i] + nums[j] + nums[k] < 0) {
                    j++;
                }
                else {
                    // �ҵ�
                    dp.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    while (j < k && nums[k] == nums[k - 1]) k--;
                    while (j < k && nums[j] == nums[j + 1]) j++;
                    j++;
                    k--;
                }
            }
        }
        return dp;
    }
};