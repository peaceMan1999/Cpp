/*
给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/contains-duplicate-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
    unordered_map<int, int> f;
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); ++i)
        {
            if (f.find(nums[i]) == f.end()) {
                f[nums[i]] = i;
            }
            else {
                if (i - f[nums[i]] <= k) {
                    return true;
                }
                else {
                    f[nums[i]] = i;
                }
            }
        }
        return false;
    }
};


