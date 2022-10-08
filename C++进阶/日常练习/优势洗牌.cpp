/*

给定两个大小相等的数组 nums1 和 nums2，nums1 相对于 nums2 的优势可以用满足 nums1[i] > nums2[i] 的索引 i 的数目来描述。

返回 nums1 的任意排列，使其相对于 nums2 的优势最大化。

 

示例 1：

输入：nums1 = [2,7,11,15], nums2 = [1,10,4,11]
输出：[2,11,7,15]

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/advantage-shuffle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<pair<int, int>> vv;
        for (int i = 0; i < n; ++i)
        {
            vv.push_back({ nums2[i], i });
        }
        vector<int> ans(n, 0);
        sort(vv.begin(), vv.end());
        sort(nums1.begin(), nums1.end());
        int i = 0, j = n - 1;
        for (auto e : nums1)
        {
            // 0 1  2 3
            // 1 10 9 11
            // 0 2  1 3
            // 1 9 10 11
            // 2 7 11 15
            // 2 11  15  7
            if (e > vv[i].first)
                ans[vv[i++].second] = e;
            else
                ans[vv[j--].second] = e;
        }
        return ans;
    }
};

