#define _CRT_SECURE_NO_WARNINGS 1

/*
���ӣ�https://www.nowcoder.com/questionTerminal/d83721575bd4418eae76c916483493de
��Դ��ţ����

�㳡��վ��һ֧���飬����������ȫ�����ص�Ť������ӣ����������ǵ�������ݣ������æ�ҳ�������ε����������С�
����������������ǣ�1��7��3��5��9��4��8�����������ε������������У�1��7������1��3��5��9������1��3��4��8���ȣ�������ĳ���Ϊ4��

��������:
��������������ݣ�ÿ�����ݵ�һ�а���һ��������n��1��n��1000����

�����ŵڶ��а���n��������m��1��n��10000�������������ÿλ��Ա����ߡ�

7
1 7 3 5 9 4 8

// �о�����

*/

// write your code here cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> d(n);
        for (int i = 0; i < n; i++)
        {
            cin >> d[i];
        }
        // �����������
        int result = 1;
        vector<int> index(n, 1);
        // �ӵڶ�λ��ʼ���Ƚ�ǰ��Ĵ�С
        // 7 �� 1 �ȣ� ��һ��ѭ��
        // 3:1 3:7 �� 5:1 5:7 5:3 ...
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (d[i] > d[j])
                    index[i] = max(index[i], index[j] + 1);
            }
            result = max(index[i], result);
        }
        cout << result << endl;
    }

    return 0;
}