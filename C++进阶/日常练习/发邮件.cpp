#define _CRT_SECURE_NO_WARNINGS 1

/*
���ӣ�https://www.nowcoder.com/questionTerminal/95e35e7f6ad34821bc2958e37c08918b
��Դ��ţ����

NowCoderÿ��Ҫ���ܶ��˷��ʼ�����һ�������ַ������ʼ����ѷ���A���ʼ�������B���ѷ���B���ʼ�������A��
��������˼����Ҫ��n���˷��ʼ�����ÿ���˽��յ�1���ʼ�������£��ж���������������˶��յ��˴�����ʼ���
��û�����յ������Լ����ʼ���

��������:
��������������ݣ�ÿ�����ݰ���һ��������n��2��n��20����
*/

// write your code here cpp
#include <iostream>
#include <vector>
using namespace std;

// �����������

int main()
{
    int n;
    vector<long long> f(21, 0);
    f[1] = 0, f[2] = 1, f[3] = 2;
    for (int i = 4; i < 21; i++)
    {
        f[i] = (i - 1) * (f[i - 1] + f[i - 2]);
    }
    while (cin >> n)
    {
        cout << f[n] << endl;
    }

    return 0;
}