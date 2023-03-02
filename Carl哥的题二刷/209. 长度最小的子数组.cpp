/*
���û������ڴﵽʱ�临�Ӷ�
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // ��������
        int sz = nums.size();
        int j = 0, sum = 0, ans = 10000000010;
        bool flag = false;
        for (int i = 0; i < sz; ++i) {
            sum += nums[i];
            while (sum >= target) {
                flag = true;
                ans = min(ans, i - j + 1);
                sum -= nums[j++];
            }
        }
        return flag ? ans : 0;
    }
};