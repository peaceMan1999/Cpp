#define _CRT_SECURE_NO_WARNINGS 1

/*

����һ���ַ���A���䳤��n���뷵��һ��boolֵ�������Ƿ�Ϊһ���Ϸ������Ŵ���ֻ����������ɣ���

����������
"(()())",6
���أ�true

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






