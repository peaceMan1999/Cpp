/*
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/valid-anagram
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
    int hash1[30];
    int hash2[30];
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        for (int i = 0; i < s.size(); ++i)
        {
            hash1[s[i] - 'a']++;
            hash2[t[i] - 'a']++;
        }
        for (int i = 0; i < 30; ++i)
        {
            if (hash1[i] != hash2[i])
                return false;
        }

        return true;
    }
};

