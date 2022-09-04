/*

链接：https://www.nowcoder.com/questionTerminal/3959837097c7413a961a135d7104c314
来源：牛客网

Levenshtein 距离，又称编辑距离，指的是两个字符串之间，由一个转换成另一个所需的最少编辑操作次数。许可的编辑操作包括将一个字符替换成另一个字符，插入一个字符，删除一个字符。编辑距离的算法是首先由俄国科学家 Levenshtein 提出的，故又叫 Levenshtein Distance 。

例如：

字符串A: abcdefg

字符串B: abcdef

通过增加或是删掉字符 ”g” 的方式达到目的。这两种方案都需要一次操作。把这个操作所需要的次数定义为两个字符串的距离。

要求：

给定任意两个字符串，写出一个算法计算它们的编辑距离。


数据范围：给定的字符串长度满足 1 \le len(str) \le 1000 \1≤len(str)≤1000


*/

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int Levenshtein(string& str1, string& str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 == 0)
        return len2;
    if (len2 == 0)
        return len1;

    vector<vector<int>> vv(len1 + 1, vector<int>(len2 + 1, 0));

    for (int i = 0; i <= len1; i++)
        vv[i][0] = i;
    for (int i = 0; i <= len2; i++)
        vv[0][i] = i;

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (str1[i - 1] == str2[j - 1]) {
                vv[i][j] = min(vv[i - 1][j], vv[i][j - 1]) + 1;
                vv[i][j] = min(vv[i - 1][j - 1], vv[i][j]);
            }
            else {
                vv[i][j] = min(vv[i - 1][j], vv[i][j - 1]) + 1;
                vv[i][j] = min(vv[i - 1][j - 1] + 1, vv[i][j]);
            }
        }
    }
    return vv[len1][len2];
}

int main() {
    string str1, str2;
    while (cin >> str1 >> str2) {
        cout << Levenshtein(str1, str2) << endl;
    }
}

