#define _CRT_SECURE_NO_WARNINGS 1

/*

给定两个int A和B。编写一个函数返回A+B的值，但不得使用+或其他算数运算符。

测试样例：
1,2
返回：3

*/


class UnusualAdd {
public:
    int addAB(int A, int B) {
        int a = A ^ B;
        int b = (A & B) << 1;
        if (a == 0)
            return b;
        if (b == 0)
            return a;
        return addAB(a, b);
    }
};
