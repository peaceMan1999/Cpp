#define _CRT_SECURE_NO_WARNINGS 1

/*
给定一个字符串A和其长度n，请返回一个bool值代表它是否为一个合法的括号串（只能由括号组成）。

测试样例：
"(()())",6
返回：true
测试样例：
"()a()()",7
返回：false
测试样例：
"()(()()",7
返回：false
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

二货小易有一个W*H的网格盒子，网格的行编号为0~H-1，网格的列编号为0~W-1。每个格子至多可以放一块蛋糕，任意两块蛋糕的欧几里得距离不能等于2。
对于两个格子坐标(x1,y1),(x2,y2)的欧几里得距离为:
( (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2) ) 的算术平方根
小易想知道最多可以放多少块蛋糕在网格盒子里。

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
    //将二维数组初始化为1；
    for (auto& e : vv)
    {
        e.resize(h, 1);
    }
    //判断欧几里得
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