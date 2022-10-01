#define _CRT_SECURE_NO_WARNINGS 1

/*

给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；如果数组中每个元素互不相同，返回 false 。
 

示例 1：

输入：nums = [1,2,3,1]
输出：true

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/contains-duplicate
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] == nums[i + 1])
                return true;
        }
        return false;
    }
};

