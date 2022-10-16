/*
将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：

P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
 

示例 1：

输入：s = "PAYPALISHIRING", numRows = 3
输出："PAHNAPLSIIGYIR"
示例 2：
输入：s = "PAYPALISHIRING", numRows = 4
输出："PINALSIGYAHRPI"
解释：
P     I    N
A   L S  I G
Y A   H R
P     I

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/zigzag-conversion
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    string convert(string s, int numRows) {
        int sz = s.size();
        if (numRows == 1 || sz <= numRows) {
            return s;
        }
        // 周期
        string ans;
        int t = 2 * numRows - 2;
        for (int i = 0; i < numRows; ++i)
        {
            for (int j = 0; j + i < sz; j += t)
            {
                ans += s[i + j];
                // 第二周期
                if (i > 0 && i < numRows - 1 && j + t - i < sz) {
                    ans += s[j + t - i];
                }
            }
        }
        return ans;
    }
};
