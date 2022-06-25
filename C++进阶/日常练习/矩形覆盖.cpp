#define _CRT_SECURE_NO_WARNINGS 1

/*
可以用2∗12*12∗1的小矩形横着或者竖着去覆盖更大的矩形
若用n个2∗12*12∗1的小矩形无重叠地覆盖一个 2*n 的大矩形，从同一个方向看总共有多少种不同的方法
注意：约定 n == 0 时，输出 0

首先如果n=0，则只有0种；

如果n=1，也只有1种；

如果n=2，有横竖2种情况：
如果n=3，有3种情况：
而如果n=4，有5种情况：
*/

class Solution {
public:
    int rectCover(int number) {
        if (number <= 2) {
            return number;
        }
        int a = 1, b = 2, c = 0;
        for (int i = 3; i <= number; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};