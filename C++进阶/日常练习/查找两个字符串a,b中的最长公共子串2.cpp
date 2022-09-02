/*

链接：https://www.nowcoder.com/questionTerminal/181a1a71c7574266ad07f9739f791506
来源：牛客网

查找两个字符串a,b中的最长公共子串。若有多个，输出在较短串中最先出现的那个。
注：子串的定义：将一个字符串删去前缀和后缀（也可以不删）形成的字符串。请和“子序列”的概念分开！

数据范围：字符串长度1\le length \le300 \1≤length≤300
进阶：时间复杂度：O(n^3)\O(n
3
 ) ，空间复杂度：O(n)\O(n)

输入描述:
输入两个字符串



输出描述:
返回重复出现的字符
示例1
输入
abcdefghijklmnop
abcsafjklmnopqrstuvw
输出
jklmnop

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void GetLongStr(string& str1, string& str2)
{
    if (str1.size() > str2.size()) {
        swap(str1, str2);
    }
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 > len2) {

    }
    vector<vector<int>> vv(len1 + 1, vector<int>(len2 + 1, 0));

    int start = 0, max = 0;
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                vv[i][j] = vv[i - 1][j - 1] + 1;
                if (vv[i][j] > max)
                {
                    max = vv[i][j];
                    start = i - max;
                }
            }
        }
    }
    string msg;
    for (int i = start; i < max + start; i++)
    {
        cout << str1[i];
    }
    cout << endl;
}

int main() {
    string str1, str2;
    while (cin >> str1 >> str2) {
        GetLongStr(str1, str2);
    }
    return 0;
}

