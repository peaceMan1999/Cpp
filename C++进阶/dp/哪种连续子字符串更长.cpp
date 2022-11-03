/*
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/find-pivot-index
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sz = nums.size();
        vector<int> order(sz, 0);
        order[0] = nums[0];
        for (int i = 1; i < sz; ++i)
        {
            order[i] = nums[i] + order[i - 1];
            cout << order[i] << " ";
        }
        // Ԥ��Ϊ0�����
        if (order[sz - 1] - order[0] == 0)
            return 0;
        for (int i = 1; i < sz; ++i)
        {
            if (order[i - 1] == order[sz - 1] - order[i])
                return i;
        }
        return -1;
    }
};
