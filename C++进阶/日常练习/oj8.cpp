#define _CRT_SECURE_NO_WARNINGS 1
/*
问题描述：在计算机中，通配符一种特殊语法，广泛应用于文件搜索、数据库、正则表达式等领域。现要求各位实现字符串通配符的算法。
要求：
实现如下2个通配符：
* ：匹配0个或以上的字符（注：能被* 和 ? 匹配的字符仅由英文字母和数字0到9组成，下同）
？：匹配1个字符

注意：匹配时不区分大小写。

输入：
通配符表达式；
一组字符串。
输出：

返回不区分大小写的匹配结果，匹配成功输出true，匹配失败输出false
*/

#include <iostream>
#include <string.h>
#include <ctype.h>
using namespace std;

bool IsRight(const char* s1, const char* s2)
{
    if (*s1 == '\0' && *s2 == '\0')
        return true;
    if (*s1 == '\0' || *s2 == '\0')
        return false;
    if (*s1 == '?')
    {
        if (!isalpha(*s2) && !isdigit(*s2))
            return false;
        return IsRight(s1 + 1, s2 + 1);
    }
    else if (*s1 == '*')
    {
        while (*s1 == '*')
            s1++;
        s1--;
        return IsRight(s1, s2 + 1) || IsRight(s1 + 1, s2 + 1) || IsRight(s1 + 1, s2);
    }
    else if (tolower(*s1) == tolower(*s2))
        return IsRight(s1 + 1, s2 + 1);
    return false;
}

int main()
{
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        bool flag = IsRight(s1.c_str(), s2.c_str());
        if (flag)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }

    return 0;
}