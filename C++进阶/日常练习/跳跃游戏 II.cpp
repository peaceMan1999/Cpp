/*
https://leetcode.cn/problems/jump-game-ii/
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int start = 0, end = 1, ans = 0;
        while (end < nums.size())
        {
            // ������˵������
            int maxjump = 0;
            for (int i = start; i < end; ++i)
            {
                // �����±꣫�����Ϊ��Զ����
                maxjump = max(maxjump, i + nums[i]);
            }

            start = end;
            end = maxjump + 1;
            ans++;
        }
        return ans;
    }
};