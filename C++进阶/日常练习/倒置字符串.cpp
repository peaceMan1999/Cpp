#define _CRT_SECURE_NO_WARNINGS 1

/*
��һ�仰�ĵ��ʽ��е��ã���㲻���á����� "I like beijing."������������Ϊ��"beijing. like I"��
�ַ������Ȳ�����100��
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