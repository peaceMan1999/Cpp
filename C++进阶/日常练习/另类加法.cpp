#define _CRT_SECURE_NO_WARNINGS 1

/*

不用加减乘除做加法
链接：https://www.nowcoder.com/questionTerminal/59ac416b4b944300b617d4f7f111b215
来源：牛客网

写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。

数据范围：两个数都满足 -10 \le n \le 1000−10≤n≤1000

*/

class Solution {
public:
    int Add(int num1, int num2) {
        //进位数
        int up = (num1 & num2) << 1;
        int at = num1 ^ num2;
        return at + up;
    }
};