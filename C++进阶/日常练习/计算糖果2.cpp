#define _CRT_SECURE_NO_WARNINGS 1

/*

A,B,C�������Ǻ�����,ÿ�������ﶼ��һЩ�ǹ�,���ǲ�֪������ÿ�������Ͼ����ж��ٸ��ǹ�,��������֪�����µ���Ϣ��
A - B, B - C, A + B, B + C. ���ĸ���ֵ.ÿ����ĸ����ÿ������ӵ�е��ǹ���.
������Ҫͨ�����ĸ���ֵ�����ÿ���������ж��ٸ��ǹ�,��A,B,C�����ﱣ֤���ֻ��һ������A,B,C������������������

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

