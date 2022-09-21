/*
给你两个正整数 n 和 k 。

如果正整数 i 满足 n % i == 0 ，那么我们就说正整数 i 是整数 n 的因子。

考虑整数 n 的所有因子，将它们 升序排列 。请你返回第 k 个因子。如果 n 的因子数少于 k ，请你返回 -1 。

 

示例 1：

输入：n = 12, k = 3
输出：3
解释：因子列表包括 [1, 2, 3, 4, 6, 12]，第 3 个因子是 3 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/the-kth-factor-of-n
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> vv(n, -1);
        int s = 0;
        for (int i = 1; i <= n; ++i) {
            if (n % i == 0) {
                vv[s++] = i;
            }
        }

        return vv[k - 1];
    }
};

