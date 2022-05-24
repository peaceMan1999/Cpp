#define _CRT_SECURE_NO_WARNINGS 1

/*
链接：https://www.nowcoder.com/questionTerminal/9ae56e5bdf4f480387df781671db5172
来源：牛客网

我们有两个字符串m和n，如果它们的子串a和b内容相同，则称a和b是m和n的公共子序列。子串中的字符不一定在原字符串中连续。
例如字符串“abcfbc”和“abfcab”，其中“abc”同时出现在两个字符串中，因此“abc”是它们的公共子序列。此外，“ab”、“af”等都是它们的字串。
现在给你两个任意字符串（不包含空格），请帮忙计算它们的最长公共子序列的长度。

*/

// write your code here cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 经典的动态规划题，面试经常出

int main()
{
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        int len1 = str1.size();
        int len2 = str2.size();
        // 创建向量
        vector<vector<int>> length(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                    length[i][j] = length[i - 1][j - 1] + 1;
                else
                    length[i][j] = max(length[i - 1][j], length[i][j - 1]);
            }
        }
        int k = 0;
        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                if (length[i][j] > k)
                    k = length[i][j];
            }
        }
        cout << k << endl;
    }
    return 0;
}