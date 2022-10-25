/*
给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。

如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。

假设环境不允许存储 64 位整数（有符号或无符号）。
 

示例 1：

输入：x = 123
输出：321

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/reverse-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
    stack<int> stk;
public:
    int reverse(int x) {
        int flag = 1;
        long long l = -((long long)1 << 31);
        long long r = ((long long)1 << 31) - 1;
        if (x == 0)
            return 0;
        if (x == l)
            return 0;
        if (x < 0)
        {
            x = -x;
            flag = -flag;
        }
        while (x)
        {
            stk.push(x % 10);
            x /= 10;
        }
        long long sum = 0;
        long long digit = 1;
        while (!stk.empty())
        {
            sum += stk.top() * digit;
            digit *= 10;
            stk.pop();
        }

        if (sum > r || sum < l)
            sum = 0;
        return flag * sum;
    }
};