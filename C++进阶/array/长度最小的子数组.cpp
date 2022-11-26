/*
来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-size-subarray-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int length = 0;
        int sum = 0;
        int i = 0; // 左窗口
        for (int j = 0; j < nums.size(); ++j) {
            sum += nums[j];
            while (sum >= target) {
                length = j - i + 1;
                ans = ans < length ? ans : length;
                sum -= nums[i++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
