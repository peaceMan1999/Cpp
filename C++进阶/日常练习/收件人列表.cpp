#define _CRT_SECURE_NO_WARNINGS 1

/*
���ӣ�https://www.nowcoder.com/questionTerminal/5973a31d58234b068fa1fe34f7290855
��Դ��ţ����

NowCoderÿ��Ҫ�����ͻ�д�����ʼ�����������֪�����һ���ʼ��а�������ռ��ˣ��ռ�������֮�����һ�����źͿո����������ռ�������Ҳ�����ո�򶺺ţ���������Ҫ��˫���Ű�����
���ڸ���һ���ռ����������������������Ӧ���ռ����б�
*/

// write your code here cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        getchar();//����\n
        string str;
        for (int i = 0; i < n; i++)
        {
            getline(cin, str);
            if (str.find(',') != string::npos
                || str.find(' ') != string::npos)
            {
                cout << '\"' << str.c_str() << '\"';
            }
            else
                cout << str.c_str();
            if (i != n - 1)
                cout << ',' << ' ';
            else
                cout << endl;
        }

    }
    return 0;
}