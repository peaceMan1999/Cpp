/*
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/jump-game
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) return false;
            // �ҵ�ÿһ�ε������Ծֵ
            k = max(k, i + nums[i]);
        }
        return true;
    }
};
