#define _CRT_SECURE_NO_WARNINGS 1

/*
输入一个长度为 n 字符串，打印出该字符串中字符的所有排列，你可以以任意顺序返回这个字符串数组。
例如输入字符串ABC,则输出由字符A,B,C所能排列出来的所有字符串ABC,ACB,BAC,BCA,CBA和CAB。

数据范围：n < 10n<10
要求：空间复杂度 O(n!)O(n!)，时间复杂度 O(n!)O(n!)
输入描述：
输入一个字符串,长度不超过10,字符只包括大小写字母。
*/

// 递归、回溯！！

class Solution {
public:
    void _Permutation(map<char, int>& ch, vector<string>& permut, string ret, int len)
    {
        if (ret.size() == len)
        {
            permut.push_back(ret);
        }

        for (auto& e : ch)
        {
            if (e.second > 0)
            {
                e.second--;
                string tmp = ret;
                ret += e.first;
                //cout << e.first << " " << ret << " ";
                _Permutation(ch, permut, ret, len);
                //回溯
                ret = tmp;
                e.second++;
            }
        }
    }

    vector<string> Permutation(string str) {
        map<char, int> ch;
        for (auto& e : str)
        {
            ch[e]++;
        }
        int len = str.size();
        vector<string> permut;
        string ret;
        _Permutation(ch, permut, ret, len);
        return permut;
    }
};