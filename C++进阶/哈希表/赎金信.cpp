/*
来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/ransom-note
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
