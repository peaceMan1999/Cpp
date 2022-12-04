/*
来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/group-anagrams
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
