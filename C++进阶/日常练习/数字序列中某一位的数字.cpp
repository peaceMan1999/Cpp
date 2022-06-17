#define _CRT_SECURE_NO_WARNINGS 1

/*
描述
数字以 0123456789101112131415... 的格式作为一个字符序列，
在这个序列中第 2 位（从下标 0 开始计算）是 2 ，第 10 位是 1 ，第 13 位是 1 ，
以此类题，请你输出第 n 位对应的数字。

*/

// 两种方法

// 1、
class Solution {
public:

    int findNthDigit(int n) {
        // 多少位数
        long long sum = 9;
        // 位数
        int x = 1;
        // 记录区域起始位
        long long start = 1;

        while (n > sum) {
            n -= sum;
            x++;
            start *= 10;
            sum = 9 * x * start;
        }
        // 求出n在哪个区间内
        int num = start + (n - 1) / x;
        int index = (n - 1) % x;
        return to_string(num)[index] - '0';
    }
};

// 2、补0法
class Solution {
public:
    int findNthDigit(int n) {
        int i = 1;
        while (i * pow(10, i) < n)
        {
            n += pow(10, i);
            i++;
        }
        // 全部补齐
        int num = n / i;
        int index = n % i;
        return to_string(num)[index] - '0';
    }
};