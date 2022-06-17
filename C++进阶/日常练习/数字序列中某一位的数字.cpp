#define _CRT_SECURE_NO_WARNINGS 1

/*
����
������ 0123456789101112131415... �ĸ�ʽ��Ϊһ���ַ����У�
����������е� 2 λ�����±� 0 ��ʼ���㣩�� 2 ���� 10 λ�� 1 ���� 13 λ�� 1 ��
�Դ����⣬��������� n λ��Ӧ�����֡�

*/

// ���ַ���

// 1��
class Solution {
public:

    int findNthDigit(int n) {
        // ����λ��
        long long sum = 9;
        // λ��
        int x = 1;
        // ��¼������ʼλ
        long long start = 1;

        while (n > sum) {
            n -= sum;
            x++;
            start *= 10;
            sum = 9 * x * start;
        }
        // ���n���ĸ�������
        int num = start + (n - 1) / x;
        int index = (n - 1) % x;
        return to_string(num)[index] - '0';
    }
};

// 2����0��
class Solution {
public:
    int findNthDigit(int n) {
        int i = 1;
        while (i * pow(10, i) < n)
        {
            n += pow(10, i);
            i++;
        }
        // ȫ������
        int num = n / i;
        int index = n % i;
        return to_string(num)[index] - '0';
    }
};