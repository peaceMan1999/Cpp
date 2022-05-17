#define _CRT_SECURE_NO_WARNINGS 1

/*
链接：https://www.nowcoder.com/questionTerminal/1046cd038f7a4b04b2b77b415973de1c
来源：牛客网

输入包含多组数据。

每组数据包含两个字符串s,t，分别是成对出现的花布条和小饰条，
其布条都是用可见ASCII字符表示的，可见的ASCII字符有多少个，布条的花纹也有多少种花样。
花纹条和小饰条不会超过1000个字符长。
*/

// write your code here cpp
#include <iostream>
#include <string>
using namespace std;

int GetSame(string str1, string str2)
{
    int pos = str1.find(str2);
    if (pos == string::npos)
        return 0;
    return GetSame(str1.substr(pos + str2.size()), str2) + 1;
}

int main()
{
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        cout << GetSame(str1, str2) << endl;
    }

    return 0;
}