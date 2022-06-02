#define _CRT_SECURE_NO_WARNINGS 1

/*
���ӣ�https://www.nowcoder.com/questionTerminal/1a92fbc771a54feb9eb5bd9b3ff2d0a9
��Դ��ţ����

Emacs�ų���ı༭�������Դ���һ������������������������ͬ�����ǻ��ں�׺���ʽ�ģ���������ڲ������ĺ��档���硰2 3 +���ȼ�����׺���ʽ�ġ�2 + 3����
����ʵ��һ����׺���ʽ�ļ�������

��������:
��������������ݡ�

ÿ�����ݰ������У���һ����һ��������n (3��n��50)�������ŵڶ��а���n������ֵ���������ɵ��б�

��+ - * /���ֱ�Ϊ�Ӽ��˳��������㣬���г���Ϊ����������5 / 3 = 1����
*/

// write your code here cpp
#include <stack>
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        stack<int> Emacs;
        string s;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            if (s >= "0" && s <= "9" || s.size() > 1) // ������
            {
                Emacs.push(stoi(s));
            }
            else
            {
                int right = Emacs.top();
                Emacs.pop();
                int left = Emacs.top();
                Emacs.pop();
                char ch = s[0];
                switch (ch) {
                case '+':
                    Emacs.push(left + right);
                    break;
                case '-':
                    Emacs.push(left - right);
                    break;
                case '*':
                    Emacs.push(left * right);
                    break;
                case '/':
                    Emacs.push(left / right);
                    break;
                default:;
                }
            }
        }
        cout << Emacs.top() << endl;
    }

    return 0;
}
