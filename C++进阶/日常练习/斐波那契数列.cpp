#define _CRT_SECURE_NO_WARNINGS 1

/*
��Ҷ�֪��쳲��������У�����Ҫ������һ�������� n ���������쳲��������еĵ� n �
쳲�����������һ������  ������
���ݷ�Χ��
Ҫ�󣺿ռ临�Ӷ�O(1) ��ʱ�临�Ӷ�O(n)
*/

class Solution {
public:
    int Fibonacci(int n) {
        int x = 0, y = 1, z = 0;
        for (int i = 1; i < n; i++)
        {
            z = x + y;
            x = y;
            y = z;
        }
        return z;
    }
};
