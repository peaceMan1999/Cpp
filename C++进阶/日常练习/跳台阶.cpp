#define _CRT_SECURE_NO_WARNINGS 1

/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个 n 级的台阶总共有多少种跳法（先后次序不同算不同的结果）。

数据范围：1≤n≤40
要求：时间复杂度：O(n) ，空间复杂度： O(1)
*/

class Solution {
public:
    // 斐波那契数列
    int jumpFloor(int number) {
        int a = 0, b = 1, c = 1;
        for (int i = 0; i < number; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }

    // 动态规划+递归
    /*void jumpCount(vector<int>& floor, int n, int at)
    {
        if (at >= n)
            return;
        while(floor[at] > 0)
        {
            floor[at]--;
            floor[at+1]++;
            floor[at+2]++;
        }
        return jumpCount(floor, n, at+1);
    }

    int jumpFloor(int number) {
        vector<int> floor(41, 0);
        floor[0] = 1;
        int at = 0;
        jumpCount(floor, number, at);
        return floor[number];
    }*/
};