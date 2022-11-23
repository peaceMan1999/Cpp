/*
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/4sum
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp;
        int n = nums.size();

        for (int i = 0; i < n - 3; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            if ((long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                break;
            }
            if ((long)nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target) {
                continue;
            }


            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                if ((long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                    break;
                }
                if ((long)nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target) {
                    continue;
                }
                int l = j + 1, r = n - 1;
                while (l < r) {
                    long sum = (long)nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum < target) {
                        l++;
                    }
                    else if (sum > target) {
                        r--;
                    }
                    else {
                        dp.push_back({ nums[i], nums[j], nums[l], nums[r] });
                        while (l < r && nums[l] == nums[l + 1]) l++;
                        l++;
                        while (l < r && nums[r] == nums[r - 1]) r--;
                        r--;
                    }
                }
            }

        }
        return dp;
    }
};
