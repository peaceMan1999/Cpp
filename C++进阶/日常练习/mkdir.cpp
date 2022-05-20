#define _CRT_SECURE_NO_WARNINGS 1

/*
�����У�ÿ��Ҫ����һ̨�»�����ʱ�򣬾���ζ����һ��Ŀ¼��Ҫ����������Ҫ����Ŀ¼��/usr/local/bin��������Ҫ�˴δ�����/usr������/usr/local���Լ���/usr/local/bin�������ڣ�Linux��mkdir�ṩ��ǿ��ġ�-p��ѡ�ֻҪһ�����mkdir -p /usr/local/bin�������Զ�������Ҫ���ϼ�Ŀ¼��
���ڸ���һЩ��Ҫ�������ļ���Ŀ¼�������æ������Ӧ�ġ�mkdir -p�����

ע�� /a/bc/b �� /a/b/bc
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        string str;
        vector<string> dir(n);
        for (int i = 0; i < n; i++)
        {
            cin >> dir[i];
        }
        // ����
        sort(dir.begin(), dir.end());
        // �������
        vector<int> index(n, 1);
        for (int i = 0; i < n - 1; i++)
        {
            if (dir[i + 1].find(dir[i]) != string::npos)
            {
                index[i] = 2;
            }
            if (dir[i + 1].size() > dir[i].size() && dir[i + 1][dir[i].size()] != '/')
            {
                index[i] = 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (index[i] == 1)
            {
                cout << "mkdir -p " << dir[i] << endl;
            }
        }
        cout << endl;
    }
}