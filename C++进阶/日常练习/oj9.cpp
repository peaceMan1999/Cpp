#define _CRT_SECURE_NO_WARNINGS 1

/*
���������ַ���a,b�е�������Ӵ������ж��������ڽ϶̴������ȳ��ֵ��Ǹ���
ע���Ӵ��Ķ��壺��һ���ַ���ɾȥǰ׺�ͺ�׺��Ҳ���Բ�ɾ���γɵ��ַ�������͡������С��ĸ���ֿ���
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string GetSame(string& s1, string& s2)
{
    //��С��ǰ��
    if (s1.size() > s2.size())
        swap(s1, s2);

    int len1 = s1.size();
    int len2 = s2.size();
    //һ����ʼ�㣬һ������
    int start = 0, max_num = 0;
    vector<vector<int>> vv(len1 + 1, vector<int>(len2 + 1, 0));

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                vv[i][j] = vv[i - 1][j - 1] + 1;
            if (vv[i][j] > max_num)
            {
                max_num = vv[i][j];
                start = i - max_num;
            }
        }
    }
    return s1.substr(start, max_num);
}

int main()
{
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        string substr = GetSame(s1, s2);
        cout << substr << endl;
    }

    return 0;
}