#define _CRT_SECURE_NO_WARNINGS 1

/*
һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n����
�����������һ��n����̨��(nΪ������)�ܹ��ж�����������

���ݷ�Χ��1��n��20
���ף��ռ临�Ӷ� O(1) �� ʱ�临�Ӷ� O(1)
*/

class Solution {
public:
    int jumpFloorII(int number) {
        // ���������һ������һ����2��
        vector<int> dp(number + 1, 0);
        dp[0] = 0, dp[1] = 1;
        for (int i = 2; i <= number; i++)
        {
            dp[i] = 2 * dp[i - 1];
        }
        return dp[number];
    }
};