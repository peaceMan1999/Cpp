#define _CRT_SECURE_NO_WARNINGS 1

/*
���ӣ�https://www.nowcoder.com/questionTerminal/1046cd038f7a4b04b2b77b415973de1c
��Դ��ţ����

��������������ݡ�

ÿ�����ݰ��������ַ���s,t���ֱ��ǳɶԳ��ֵĻ�������С������
�䲼�������ÿɼ�ASCII�ַ���ʾ�ģ��ɼ���ASCII�ַ��ж��ٸ��������Ļ���Ҳ�ж����ֻ�����
��������С�������ᳬ��1000���ַ�����
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