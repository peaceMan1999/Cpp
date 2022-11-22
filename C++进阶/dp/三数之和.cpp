/*
来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
            // 去重
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
                    // 找到
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