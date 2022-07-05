#define _CRT_SECURE_NO_WARNINGS 1

/*
大家都知道斐波那契数列，现在要求输入一个正整数 n ，请你输出斐波那契数列的第 n 项。
斐波那契数列是一个满足  的数列
数据范围：
要求：空间复杂度O(1) ，时间复杂度O(n)
*/

class Solution {
public:
    int Fibonacci(int n) {
        int x = 0, y = 1, z = 0;
        for (int i = 1; i < n; i++)
        {
            z = x + y;
            x = y;
            y = z;
        }
        return z;
    }
};
