/*
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/count-items-matching-a-rule
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int idx = 0;
        if (ruleKey == "color") {
            idx = 1;
        }
        else if (ruleKey == "name") {
            idx = 2;
        }
        int count = 0;
        for (int i = 0; i < items.size(); i++)
        {
            if (items[i][idx] == ruleValue)
                count++;
        }
        return count;
    }
};