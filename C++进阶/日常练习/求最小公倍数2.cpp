#define _CRT_SECURE_NO_WARNINGS 1

/*

正整数 a 和正整数 b 的最小公倍数，是指能被 a 和 b 整除的最小的正整数。
请你求 a 和 b 的最小公倍数。
比如输入5和7，5和7的最小公倍数是35，则需要返回35。

*/


#include <iostream>

int MinNum(int a, int b)
{
    // 9  6
    int c = a % b;
    while (c != 0) {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

int main()
{
    long long a, b;
    std::cin >> a >> b;

    std::cout << (a * b / MinNum(a, b)) << std::endl;

    return 0;
}

