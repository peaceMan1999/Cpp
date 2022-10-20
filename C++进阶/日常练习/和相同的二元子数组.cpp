/*
给你一个二元数组 nums ，和一个整数 goal ，请你统计并返回有多少个和为 goal 的 非空 子数组。

子数组 是数组的一段连续部分。

 

示例 1：

输入：nums = [1,0,1,0,1], goal = 2
输出：4
解释：
有 4 个满足题目要求的子数组：[1,0,1]、[1,0,1,0]、[0,1,0,1]、[1,0,1]

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/binary-subarrays-with-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int hash[600010];
        memset(hash, 0, sizeof(hash)); 
        for (int i = 1; i < nums.size(); ++i)
        {
            nums[i] += nums[i - 1];
        }
        int ans = 0;
        hash[goal] = 1;
        for (int e : nums)
        {
            ans += hash[e];
            ++hash[e + goal];
        }
        return ans;
    }
};

