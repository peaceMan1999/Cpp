#define _CRT_SECURE_NO_WARNINGS 1

/*
链接：https://www.nowcoder.com/questionTerminal/1a92fbc771a54feb9eb5bd9b3ff2d0a9
来源：牛客网

Emacs号称神的编辑器，它自带了一个计算器。与其他计算器不同，它是基于后缀表达式的，即运算符在操作数的后面。例如“2 3 +”等价于中缀表达式的“2 + 3”。
请你实现一个后缀表达式的计算器。

输入描述:
输入包含多组数据。

每组数据包括两行：第一行是一个正整数n (3≤n≤50)；紧接着第二行包含n个由数值和运算符组成的列表。

“+ - * /”分别为加减乘除四则运算，其中除法为整除，即“5 / 3 = 1”。
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
            if (s >= "0" && s <= "9" || s.size() > 1) // 是数字
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
