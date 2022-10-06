/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

 

示例 1:

输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)
            return 0;
        int hash[255] = { 0 };
        int left = 0, right = 0, maxcount = 0;;
        while (s[right]) {
            if (hash[s[right]] == 0) {
                hash[s[right]] = right + 1;
            }
            else {
                if (hash[s[right]] > left) {
                    left = hash[s[right]];
                }
                hash[s[right]] = right + 1;
            }
            maxcount = max(maxcount, right - left + 1);
            right++;
        }
        return maxcount;
    }
};