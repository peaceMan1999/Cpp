/*
来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/jump-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) return false;
            // 找到每一次的最大跳跃值
            k = max(k, i + nums[i]);
        }
        return true;
    }
};
