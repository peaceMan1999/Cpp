/*
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    int findLeft(vector<int>& nums, int l, int r, int target) {
        int left_size = -2;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) {
                r = mid - 1;
                left_size = r;
            }
            else {
                l = mid + 1;
            }
        }
        return left_size;
    }

    int findRight(vector<int>& nums, int l, int r, int target) {
        int right_size = -2;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (nums[mid] > target) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
                right_size = l;
            }
        }
        return right_size;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        if (nums.size() == 0) {
            return ans;
        }
        int l = 0, r = nums.size() - 1;
        int left_size = findLeft(nums, l, r, target);
        int right_size = findRight(nums, l, r, target);
        if (left_size == -2 || right_size == -2) {
            return ans;
        }
        if (right_size - left_size > 1) {
            ans[0] = left_size + 1, ans[1] = right_size - 1;
        }
        return ans;
    }
};
