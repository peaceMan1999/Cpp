#define _CRT_SECURE_NO_WARNINGS 1

/*
����̨����չ���⡿
һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨��(nΪ������)�ܹ��ж�����������
���ݷ�Χ��

1 <= n <= 20;
*/

#include <iostream>
using namespace std;

int GetCount(int n)
{
    if (n == 1)
        return 1;
    else
        return GetCount(n - 1) * 2;
}

int main()
{
    //һ��̨����1�֣�����̨��2�֣�3��4�֣�4��8�֣��ɴ˿ɵã�f(n) = f(n-1)*2
    int n;
    while (cin >> n)
    {
        cout << GetCount(n) << endl;
    }

    return 0;
}


