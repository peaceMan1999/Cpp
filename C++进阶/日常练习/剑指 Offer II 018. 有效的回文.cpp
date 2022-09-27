/*

给定一个字符串 s ，验证 s 是否是 回文串 ，只考虑字母和数字字符，可以忽略字母的大小写。

本题中，将空字符串定义为有效的 回文串 。

 

示例 1:

输入: s = "A man, a plan, a canal: Panama"
输出: true
解释："amanaplanacanalpanama" 是回文串

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/XltzEq
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] = s[i] - 'A' + 'a';
        }
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (!(s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9')) {
                i++;
                continue;
            }
            if (!(s[j] >= 'a' && s[j] <= 'z' || s[j] >= '0' && s[j] <= '9')) {
                j--;
                continue;
            }
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};

