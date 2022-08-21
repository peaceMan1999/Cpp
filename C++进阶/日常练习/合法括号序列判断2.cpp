#define _CRT_SECURE_NO_WARNINGS 1

/*

给定一个字符串A和其长度n，请返回一个bool值代表它是否为一个合法的括号串（只能由括号组成）。

测试样例：
"(()())",6
返回：true

*/

class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        stack<char> st;
        for (int i = 0; i < A.size(); i++)
        {
            switch (A[i])
            {
            case '(':
                st.push(A[i]);
                break;
            case ')':
                if (st.empty())
                    return false;
                else
                    st.pop();
                break;
            defult:
                return false;
                break;
            }
        }
        if (st.empty())
            return true;
        return false;
    }
};






