#define _CRT_SECURE_NO_WARNINGS 1

/*
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

 

示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vv(2, 0);
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (nums[i] + nums[j] == target)
                {
                    vv[0] = i;
                    vv[1] = j;
                    break;
                }
            }
        }
        return vv;
    }
};

// 2.一遍哈希
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        vector<int> vv(2, 0);
        for (int i = 0; i < nums.size(); ++i)
        {
            if (mp.count(target - nums[i]) > 0) {
                vv[0] = mp[target - nums[i]];
                vv[1] = i;
                break;
            }
            else {
                mp[nums[i]] = i;
            }
        }
        return vv;
    }
};
