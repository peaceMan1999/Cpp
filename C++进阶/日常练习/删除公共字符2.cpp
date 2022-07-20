#define _CRT_SECURE_NO_WARNINGS 1

/*
链接：https://www.nowcoder.com/questionTerminal/c0e553da4ba94ec28bf1276d988f716f
来源：牛客网

输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
例如：第一个字符串是"They are students."，第二个字符串是”aeiou"。删除之后的第一个字符串变成"Thy r stdnts."。
保证两个字符串的长度均不超过100。
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);

    // 采用哈希的方式先放str2
    int hash[256] = { 0 };
    for (int i = 0; i < str2.size(); i++)
    {
        hash[str2[i]]++;
    }
    string str = "";
    for (int i = 0; i < str1.size(); i++)
    {
        if (hash[str1[i]] == 0) {
            str += str1[i];
        }
    }
    cout << str.c_str() << endl;

    return 0;
}