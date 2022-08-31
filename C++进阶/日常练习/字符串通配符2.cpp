/*

问题描述：在计算机中，通配符一种特殊语法，广泛应用于文件搜索、数据库、正则表达式等领域。现要求各位实现字符串通配符的算法。
要求：
实现如下2个通配符：
*：匹配0个或以上的字符（注：能被*和?匹配的字符仅由英文字母和数字0到9组成，下同）
？：匹配1个字符

注意：匹配时不区分大小写。

输入：
通配符表达式；
一组字符串。
输出：

返回不区分大小写的匹配结果，匹配成功输出true，匹配失败输出false
数据范围：字符串长度：1\le s\le 100\1≤s≤100
进阶：时间复杂度：O(n^2)\O(n
2
 ) ，空间复杂度：O(n)\O(n)
输入描述：
先输入一个带有通配符的字符串，再输入一个需要匹配的字符串

输出描述：
返回不区分大小写的匹配结果，匹配成功输出true，匹配失败输出false

示例1
输入：
te?t*.*
txt12.xls
复制
输出：
false

*/

#include<string>
#include<iostream>
#include<vector>
using namespace std;

bool CharMatch(const char* str1, const char* str2)
{
    if (*str1 == '\0' && *str2 == '\0')
    {
        return true;
    }
    if (*str1 == '\0' || *str2 == '\0')
    {
        return false;
    }

    if (*str1 == '?' && (isalpha(*str2) || isalnum(*str2))) {
        return CharMatch(str1 + 1, str2 + 1);
    }
    else if (*str1 == '*' && (isalpha(*str2) || isdigit(*str2))) {
        // 避免多个*导致栈溢出
        while (*str1 == '*') {
            str1++;
        }
        str1--;
        // 3种可能
        return CharMatch(str1 + 1, str2) || CharMatch(str1 + 1, str2 + 1) || CharMatch(str1, str2 + 1);
    }
    else if (tolower(*str1) == tolower(*str2)) {
        return CharMatch(str1 + 1, str2 + 1);
    }
    return false;
}

int main() {
    string str1, str2;
    while (cin >> str1 >> str2)
    {
        bool ret = CharMatch(str1.c_str(), str2.c_str());
        if (ret) {
            cout << "true" << endl;
        }
        else {
            cout << "false" << endl;
        }
    }
}


