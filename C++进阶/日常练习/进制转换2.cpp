#define _CRT_SECURE_NO_WARNINGS 1

/*
����һ��ʮ������M���Լ���Ҫת���Ľ�����N����ʮ������Mת��ΪN������
*/

#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    int M, N;
    std::cin >> M >> N;
    std::string table = "0123456789ABCDEF";
    std::string str; // ���յ�λ��
    // ���ж�����
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

