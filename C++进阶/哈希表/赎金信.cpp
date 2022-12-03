/*
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/ransom-note
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for (auto& ch : magazine) {
            mp[ch]++;
        }
        for (auto& ch : ransomNote) {
            if (mp[ch] == 0) {
                return false;
            }
            else if (mp[ch] != 0) {
                mp[ch]--;
            }
            else {
                return false;
            }
        }
        return true;
    }
};
