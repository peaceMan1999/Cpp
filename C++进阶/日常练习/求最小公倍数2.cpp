#define _CRT_SECURE_NO_WARNINGS 1

/*

������ a �������� b ����С����������ָ�ܱ� a �� b ��������С����������
������ a �� b ����С��������
��������5��7��5��7����С��������35������Ҫ����35��

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

