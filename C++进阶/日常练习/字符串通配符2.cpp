/*

�����������ڼ�����У�ͨ���һ�������﷨���㷺Ӧ�����ļ����������ݿ⡢������ʽ��������Ҫ���λʵ���ַ���ͨ������㷨��
Ҫ��
ʵ������2��ͨ�����
*��ƥ��0�������ϵ��ַ���ע���ܱ�*��?ƥ����ַ�����Ӣ����ĸ������0��9��ɣ���ͬ��
����ƥ��1���ַ�

ע�⣺ƥ��ʱ�����ִ�Сд��

���룺
ͨ������ʽ��
һ���ַ�����
�����

���ز����ִ�Сд��ƥ������ƥ��ɹ����true��ƥ��ʧ�����false
���ݷ�Χ���ַ������ȣ�1\le s\le 100\1��s��100
���ף�ʱ�临�Ӷȣ�O(n^2)\O(n
2
 ) ���ռ临�Ӷȣ�O(n)\O(n)
����������
������һ������ͨ������ַ�����������һ����Ҫƥ����ַ���

���������
���ز����ִ�Сд��ƥ������ƥ��ɹ����true��ƥ��ʧ�����false

ʾ��1
���룺
te?t*.*
txt12.xls
����
�����
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
        // ������*����ջ���
        while (*str1 == '*') {
            str1++;
        }
        str1--;
        // 3�ֿ���
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


