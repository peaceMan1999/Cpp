/*
二分查找,时间复杂度为log(n),细节在于遇到相等的值怎么操作
*/

class Solution {
public:
    int GetLeft(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        bool flag = false;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] < target) {
                l = mid + 1;
            }
            else if (nums[mid] > target) {
                r = mid - 1;
            }
            else {
                r = mid - 1;
                flag = true;
            }
        }
        return flag ? r + 1 : -1;
    }

    int GetRight(int left, vector<int>& nums, int target) {
        int l = left, r = nums.size() - 1;
        bool flag = false;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] < target) {
                l = mid + 1;
            }
            else if (nums[mid] > target) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
                flag = true;
            }
        }
        return flag ? l - 1 : -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int left = -1, right = -1;
        left = GetLeft(nums, target);
        if (left != -1) {
            right = GetRight(left, nums, target);
        }
        ans[0] = left, ans[1] = right;
        return ans;
    }
};