#define _CRT_SECURE_NO_WARNINGS 1
/*
链接：https://www.nowcoder.com/questionTerminal/286af664b17243deb745f69138f8a800
来源：牛客网

NowCoder每天要处理许多邮件，但他并不是在收件人列表中，有时候只是被抄送。他认为这些抄送的邮件重要性比自己在收件人列表里的邮件低，因此他要过滤掉这些次要的邮件，优先处理重要的邮件。
现在给你一串抄送列表，请你判断目标用户是否在抄送列表中。

输入描述:
输入有多组数据，每组数据有两行。

第一行抄送列表，姓名之间用一个逗号隔开。如果姓名中包含空格或逗号，则姓名包含在双引号里。总长度不超过512个字符。

第二行只包含一个姓名，是待查找的用户的名字（姓名要完全匹配）。长度不超过16个字符。


输出描述:
如果第二行的名字出现在收件人列表中，则输出“Ignore”，表示这封邮件不重要；否则，输出“Important!”，表示这封邮件需要被优先处理。
*/

// write your code here cpp
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main()
{
    string str, name;
    while (getline(cin, str))
    {
        unordered_set<string> st;
        int i = 0;
        while (i < str.size())
        {
            if (str[i] == '\"') // 有引号
            {
                int pos = str.find('\"', i + 1);
                st.insert(str.substr(i + 1, pos - i - 1));
                i = pos + 2;
            }
            else // 没有引号
            {
                int pos = str.find('\,', i + 1);
                if (pos == string::npos) // 末尾
                {
                    st.insert(str.substr(i, str.size()));
                    break;
                }
                else
                {
                    st.insert(str.substr(i, pos - 1));
                    i = pos + 1;
                }
            }
        } // end of for
        getline(cin, name);
        if (st.find(name) == st.end())
        {
            cout << "Important!" << endl;
        }
        else
        {
            cout << "Ignore" << endl;
        }
    }
    return 0;
}