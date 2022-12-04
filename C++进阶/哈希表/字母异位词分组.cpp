/*
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/group-anagrams
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (auto& str : strs) {
            string diff = str;
            sort(diff.begin(), diff.end());
            mp[diff].push_back(str);
        }
        int sz = mp.size();
        vector<vector<string>> ans;
        for (auto& str : mp) {
            ans.push_back(str.second);
        }
        return ans;
    }
};
