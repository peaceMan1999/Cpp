/*
���ӣ�https://www.nowcoder.com/questionTerminal/610e6c0387a0401fb96675f58cda8559
��Դ��ţ����

���깫˾���Ľ�Ʒ�ر���������񽱵Ĺ��ȴ�����⣺
1. ���ȣ�������Ա����һ��д���Լ����ֵ���������齱���У�
2. ����������������ϣ�ÿ�˴�����ȡһ��������
3. ����鵽��������д�ľ����Լ������֣���ô����ϲ�㣬�н��ˣ���
���ڸ�����μ�������������������ж��ٸ��ʻ�������˻񽱣�

��������:
��������������ݣ�ÿ�����ݰ���һ��������n��2��n��20����
*/
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    //��������
    long long index[21] = { 0, 0, 1 };
    long long all[21] = { 1, 1, 2 };
    for (int i = 3; i <= 20; i++)
    {
        index[i] = (i - 1) * (index[i - 1] + index[i - 2]);
        all[i] = all[i - 1] * i;
    }
    int n;
    while (cin >> n)
    {
        printf("%.2f%%\n", 100.0 * index[n] / all[n]);
    }
    return 0;
}