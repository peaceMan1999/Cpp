#define _CRT_SECURE_NO_WARNINGS 1

/*

A,B,C三个人是好朋友,每个人手里都有一些糖果,我们不知道他们每个人手上具体有多少个糖果,但是我们知道以下的信息：
A - B, B - C, A + B, B + C. 这四个数值.每个字母代表每个人所拥有的糖果数.
现在需要通过这四个数值计算出每个人手里有多少个糖果,即A,B,C。这里保证最多只有一组整数A,B,C满足所有题设条件。

*/

#include <iostream>

int main()
{
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    // a = A - B
    // b = B - C
    // c = A + B
    // d = B + C
    int A = (a + c) / 2;
    int B1 = (b + d) / 2;
    int C = (d - b) / 2;
    int B2 = (c - a) / 2;

    if (B1 != B2) {
        std::cout << "No" << std::endl;
    }
    else {
        std::cout << A << " " << B1 << " " << C << std::endl;
    }

    return 0;
}

