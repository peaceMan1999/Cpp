#define _CRT_SECURE_NO_WARNINGS 1

/*
һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ�� n ����̨���ܹ��ж������������Ⱥ����ͬ�㲻ͬ�Ľ������

���ݷ�Χ��1��n��40
Ҫ��ʱ�临�Ӷȣ�O(n) ���ռ临�Ӷȣ� O(1)
*/

class Solution {
public:
    // 쳲���������
    int jumpFloor(int number) {
        int a = 0, b = 1, c = 1;
        for (int i = 0; i < number; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }

    // ��̬�滮+�ݹ�
    /*void jumpCount(vector<int>& floor, int n, int at)
    {
        if (at >= n)
            return;
        while(floor[at] > 0)
        {
            floor[at]--;
            floor[at+1]++;
            floor[at+2]++;
        }
        return jumpCount(floor, n, at+1);
    }

    int jumpFloor(int number) {
        vector<int> floor(41, 0);
        floor[0] = 1;
        int at = 0;
        jumpCount(floor, number, at);
        return floor[number];
    }*/
};