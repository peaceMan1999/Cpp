/*
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/regular-expression-matching
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
    int sn;
    int pn;
    vector<vector<bool>> memo;
public:
    bool back(string s, string p, int i, int j)
    {
        // 记忆化减枝
        if (memo[i][j] == false)
            return false;
        // 出口
        if (i == sn) {
            memo[i][j] = j == pn || (j + 1 < pn && p[j + 1] == '*' && back(s, p, i, j + 2));
            return memo[i][j];
        }
        else if (j == pn) {
            memo[i][j] = false;
            return memo[i][j];
        }

        // 回溯处理
        if (s[i] == p[j] || p[j] == '.')
        {
            // 复制+复制终止+越过
            if (j + 1 < p.size() && p[j + 1] == '*') {
                memo[i][j] = back(s, p, i + 1, j) || back(s, p, i + 1, j + 2) || back(s, p, i, j + 2);
                return memo[i][j];
            }
            else {
                memo[i][j] = back(s, p, i + 1, j + 1);
                return memo[i][j];
            }
        }
        else {
            // 还有机会，p[j+1]是'*'，可能是越过
            if (j + 1 < p.size() && p[j + 1] == '*') {
                memo[i][j] = back(s, p, i, j + 2);
                return memo[i][j];
            }
            else {
                memo[i][j] = false;
                return memo[i][j];
            }
        }
    }

    bool isMatch(string s, string p) {
        sn = s.size(), pn = p.size();
        memo = vector<vector<bool>>(sn + 1, vector<bool>(pn + 1, true));
        return back(s, p, 0, 0);
    }
};