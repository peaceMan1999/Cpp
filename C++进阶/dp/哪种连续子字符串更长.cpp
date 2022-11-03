/*
来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-pivot-index
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sz = nums.size();
        vector<int> order(sz, 0);
        order[0] = nums[0];
        for (int i = 1; i < sz; ++i)
        {
            order[i] = nums[i] + order[i - 1];
            cout << order[i] << " ";
        }
        // 预防为0的情况
        if (order[sz - 1] - order[0] == 0)
            return 0;
        for (int i = 1; i < sz; ++i)
        {
            if (order[i - 1] == order[sz - 1] - order[i])
                return i;
        }
        return -1;
    }
};
