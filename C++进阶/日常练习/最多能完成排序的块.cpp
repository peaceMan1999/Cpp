/*
给定一个长度为 n 的整数数组 arr ，它表示在 [0, n - 1] 范围内的整数的排列。

我们将 arr 分割成若干 块 (即分区)，并对每个块单独排序。将它们连接起来后，使得连接的结果和按升序排序后的原数组相同。

返回数组能分成的最多块数量。

 

示例 1:

输入: arr = [4,3,2,1,0]
输出: 1
解释:
将数组分成2块或者更多块，都无法得到所需的结果。
例如，分成 [4, 3], [2, 1, 0] 的结果是 [3, 4, 0, 1, 2]，这不是有序的数组。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/max-chunks-to-make-sorted
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> stk;
        for (auto e : arr)
        {
            if (stk.empty() || e >= stk.top()) {
                stk.push(e);
            }
            else {
                int mx = stk.top();
                stk.pop();
                while (!stk.empty() && stk.top() > e) {
                    stk.pop();
                }
                stk.push(mx);
            }
        }
        return stk.size();
    }
};