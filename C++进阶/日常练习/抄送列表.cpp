#define _CRT_SECURE_NO_WARNINGS 1
/*
���ӣ�https://www.nowcoder.com/questionTerminal/286af664b17243deb745f69138f8a800
��Դ��ţ����

NowCoderÿ��Ҫ��������ʼ����������������ռ����б��У���ʱ��ֻ�Ǳ����͡�����Ϊ��Щ���͵��ʼ���Ҫ�Ա��Լ����ռ����б�����ʼ��ͣ������Ҫ���˵���Щ��Ҫ���ʼ������ȴ�����Ҫ���ʼ���
���ڸ���һ�������б������ж�Ŀ���û��Ƿ��ڳ����б��С�

��������:
�����ж������ݣ�ÿ�����������С�

��һ�г����б�����֮����һ�����Ÿ�������������а����ո�򶺺ţ�������������˫������ܳ��Ȳ�����512���ַ���

�ڶ���ֻ����һ���������Ǵ����ҵ��û������֣�����Ҫ��ȫƥ�䣩�����Ȳ�����16���ַ���


�������:
����ڶ��е����ֳ������ռ����б��У��������Ignore������ʾ����ʼ�����Ҫ�����������Important!������ʾ����ʼ���Ҫ�����ȴ���
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
            if (str[i] == '\"') // ������
            {
                int pos = str.find('\"', i + 1);
                st.insert(str.substr(i + 1, pos - i - 1));
                i = pos + 2;
            }
            else // û������
            {
                int pos = str.find('\,', i + 1);
                if (pos == string::npos) // ĩβ
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