#define _CRT_SECURE_NO_WARNINGS 1

/*
����һ���ַ���A���䳤��n���뷵��һ��boolֵ�������Ƿ�Ϊһ���Ϸ������Ŵ���ֻ����������ɣ���

����������
"(()())",6
���أ�true
����������
"()a()()",7
���أ�false
����������
"()(()()",7
���أ�false
*/

class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        stack<char> st;

        for (auto e : A)
        {
            switch (e)
            {
            case '(':
                st.push(e);
                break;
            case ')':
                if (st.empty())
                    return false;
                st.pop();
                break;
            default:
                return false;
            }
        }
        if (!st.empty())
            return false;
        return true;
    }
};


/*

����С����һ��W*H��������ӣ�������б��Ϊ0~H-1��������б��Ϊ0~W-1��ÿ������������Է�һ�鵰�⣬�������鵰���ŷ����þ��벻�ܵ���2��
����������������(x1,y1),(x2,y2)��ŷ����þ���Ϊ:
( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) ) ������ƽ����
С����֪�������ԷŶ��ٿ鵰������������

*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int w, h;
    cin >> w >> h;
    vector<vector<int>> vv;
    vv.resize(w);
    //����ά�����ʼ��Ϊ1��
    for (auto& e : vv)
    {
        e.resize(h, 1);
    }
    //�ж�ŷ�����
    int count = 0;
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            if (vv[i][j] == 1)
            {
                count++;
                if (i + 2 < w)
                    vv[i + 2][j] = 0;
                if (j + 2 < h)
                    vv[i][j + 2] = 0;
            }
        }
    }
    cout << count << endl;

    return 0;
}