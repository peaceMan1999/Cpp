#define _CRT_SECURE_NO_WARNINGS 1

/*
���ӣ�https://www.nowcoder.com/questionTerminal/c0e553da4ba94ec28bf1276d988f716f
��Դ��ţ����

���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ���
���磺��һ���ַ�����"They are students."���ڶ����ַ����ǡ�aeiou"��ɾ��֮��ĵ�һ���ַ������"Thy r stdnts."��
��֤�����ַ����ĳ��Ⱦ�������100��
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);

    // ���ù�ϣ�ķ�ʽ�ȷ�str2
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