#define _CRT_SECURE_NO_WARNINGS 1
/*
�����������ڼ�����У�ͨ���һ�������﷨���㷺Ӧ�����ļ����������ݿ⡢������ʽ��������Ҫ���λʵ���ַ���ͨ������㷨��
Ҫ��
ʵ������2��ͨ�����
* ��ƥ��0�������ϵ��ַ���ע���ܱ�* �� ? ƥ����ַ�����Ӣ����ĸ������0��9��ɣ���ͬ��
����ƥ��1���ַ�

ע�⣺ƥ��ʱ�����ִ�Сд��

���룺
ͨ������ʽ��
һ���ַ�����
�����

���ز����ִ�Сд��ƥ������ƥ��ɹ����true��ƥ��ʧ�����false
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