/*
https://leetcode.cn/problems/jump-game-ii/
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int start = 0, end = 1, ans = 0;
        while (end < nums.size())
        {
            // 超出就说明满足
            int maxjump = 0;
            for (int i = start; i < end; ++i)
            {
                // 遍历下标＋最大步数为最远距离
                maxjump = max(maxjump, i + nums[i]);
            }

            start = end;
            end = maxjump + 1;
            ans++;
        }
        return ans;
    }
};