#define _CRT_SECURE_NO_WARNINGS 1

/*
查找两个字符串a,b中的最长公共子串。若有多个，输出在较短串中最先出现的那个。
注：子串的定义：将一个字符串删去前缀和后缀（也可以不删）形成的字符串。请和“子序列”的概念分开！
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string GetSame(string& s1, string& s2)
{
    //最小放前面
    if (s1.size() > s2.size())
        swap(s1, s2);

    int len1 = s1.size();
    int len2 = s2.size();
    //一个开始点，一个长度
    int start = 0, max_num = 0;
    vector<vector<int>> vv(len1 + 1, vector<int>(len2 + 1, 0));

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                vv[i][j] = vv[i - 1][j - 1] + 1;
            if (vv[i][j] > max_num)
            {
                max_num = vv[i][j];
                start = i - max_num;
            }
        }
    }
    return s1.substr(start, max_num);
}

int main()
{
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        string substr = GetSame(s1, s2);
        cout << substr << endl;
    }

    return 0;
}