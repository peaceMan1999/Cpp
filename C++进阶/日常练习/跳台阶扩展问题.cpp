#define _CRT_SECURE_NO_WARNINGS 1

/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
求该青蛙跳上一个n级的台阶(n为正整数)总共有多少种跳法。

数据范围：1≤n≤20
进阶：空间复杂度 O(1) ， 时间复杂度 O(1)
*/

class Solution {
public:
    int jumpFloorII(int number) {
        // 可以求得下一个是上一个的2倍
        vector<int> dp(number + 1, 0);
        dp[0] = 0, dp[1] = 1;
        for (int i = 2; i <= number; i++)
        {
            dp[i] = 2 * dp[i - 1];
        }
        return dp[number];
    }
};