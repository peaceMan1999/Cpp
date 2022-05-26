#define _CRT_SECURE_NO_WARNINGS 1

/*
链接：https://www.nowcoder.com/questionTerminal/f72adfe389b84da7a4986bde2a886ec3
来源：牛客网

求字典序在 s1 和 s2 之间的，长度在 len1 到 len2 的字符串的个数，结果 mod 1000007。

数据范围：1 \le len(s1),len(s2) \le 50 \1≤len(s1),len(s2)≤50  ，1 \le len1,len2 \le 50 \1≤len1,len2≤50

注意：本题有多组输入

输入描述:
每组数据包涵s1（长度小于50），s2（长度小于50），len1（小于50），len2（大于len1，小于50）
*/

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

// 本题需要计算出每一位的差值，再按照位数进行求平方，记得补位，小补‘a’，大补‘z’+1；
int main()
{
    string str1, str2;
    int len1, len2;
    while (cin >> str1 >> str2 >> len1 >> len2)
    {
        // 补位
        if (str1.size() < len2)
            str1.append(len2 - str1.size(), 'a');
        if (str2.size() < len2)
            str2.append(len2 - str2.size(), 'z' + 1);
        // 每一位的差值
        vector<int> index(len2);
        for (int i = 0; i < len2; i++)
        {
            index[i] = str2[i] - str1[i];
        }

        // 计算
        long long result = 0;
        for (int i = len1; i <= len2; i++)
        {
            for (int j = 0; j < i; j++)
            {
                result += index[j] * pow(26, i - j - 1);
            }
        }
        cout << (result - 1 % 1000007) << endl;
    }
    return 0;
}
