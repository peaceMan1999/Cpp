#define _CRT_SECURE_NO_WARNINGS 1

/*
将一句话的单词进行倒置，标点不倒置。比如 "I like beijing."，经过处理后变为："beijing. like I"。
字符串长度不超过100。
*/

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    getline(cin, str);

    reverse(str.begin(), str.end());

    int pos = str.find(" ");
    int i = 0;
    while (pos != string::npos)
    {
        reverse(str.begin() + i, str.begin() + pos);
        i = pos + 1;
        pos = str.find(" ", i);
    }
    reverse(str.begin() + i, str.end());

    cout << str.c_str() << endl;

    return 0;
}