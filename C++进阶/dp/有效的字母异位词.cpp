/*
来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/valid-anagram
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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

