#define _CRT_SECURE_NO_WARNINGS 1
/*
����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݡ�ÿ�䷿�ڶ�����һ�����ֽ�Ӱ����͵�Ե�Ψһ��Լ���ؾ������ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�������

����һ������ÿ�����ݴ�Ž��ķǸ��������飬������ ����������װ�õ������ ��һҹ֮���ܹ�͵�Ե�����߽�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/house-robber
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
    int f[110];
public:
    int rob(vector<int>& nums) {
        int mx = 0;
        int n = nums.size();
        f[0] = nums[0];
        for (int i = 1; i < n; ++i)
        {
            if (i == 1) {
                f[i] = max(nums[0], nums[1]);
            }
            else {
                f[i] = max(f[i - 1], f[i - 2] + nums[i]);
            }
        }
        return f[n - 1];
    }
};
