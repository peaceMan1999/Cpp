#define _CRT_SECURE_NO_WARNINGS 1

/*

��������int A��B����дһ����������A+B��ֵ��������ʹ��+�����������������

����������
1,2
���أ�3

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
