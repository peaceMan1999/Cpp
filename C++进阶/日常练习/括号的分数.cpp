/*
给定一个平衡括号字符串 S，按下述规则计算该字符串的分数：

() 得 1 分。
AB 得 A + B 分，其中 A 和 B 是平衡括号字符串。
(A) 得 2 * A 分，其中 A 是平衡括号字符串。
 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/score-of-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for (auto e : s)
        {
            if (e == '(') {
                st.push(0);
            }
            else {
                int v = st.top();
                st.pop();
                st.top() += max(v * 2, 1);

            }
        }
        return st.top();
    }
};

