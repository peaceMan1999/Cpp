#define _CRT_SECURE_NO_WARNINGS 1

/*
给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数
*/

#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    int M, N;
    std::cin >> M >> N;
    std::string table = "0123456789ABCDEF";
    std::string str; // 接收的位数
    // 先判断正负
    int flag = 1;
    if (M < 0) {
        flag = -1;
        M = -M;
    }
    while (M > N) {
        str += table[M % N];
        M /= N;
    }
    str += table[M];
    if (flag == -1)
        str += "-";

    reverse(str.begin(), str.end());

    std::cout << str.c_str() << std::endl;

    return 0;
}

