#define _CRT_SECURE_NO_WARNINGS 1

/*
ţ���������඼��С���ģ��������������̲�ס��;
��Ȼ��������Ϊ�һ������ã������ⲻ��������Ϊţ�������Ǹ��� X X����

[�����]�Ǽ�����

���ӣ�https://www.nowcoder.com/questionTerminal/34f17d5f2a8240bea661a23ec095a062
��Դ��ţ����

�Ǽ�ս����չ��100��֮��NowCoder���������������˵����룡���ǵ�������һ��������ͨ��һ�ű������Ϣӳ�������4λ���롣��Ĺ����ǣ�n��Ӧ��ֵ�Ǿ���X��n�η������Ͻǣ�������������4λ����0��䣬�������4λ����ֻ������4λ��
|1 1|^n => |Xn ..|
|1 0|      |.. ..|
����n=2ʱ��
|1 1|^2 => |1 1| * |1 1| => |2 1|
|1 0|      |1 0|   |1 0|    |1 1|
��2��Ӧ�����ǡ�0002����

*/

// write your code here cpp
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int main()
{
    vector<int> vv(10000, 0);
    vv[1] = 1, vv[2] = 2;
    //��ʵ���Ͻǵ�ֵ��һ��쳲���������
    for (int i = 3; i < 10001; i++)
    {
        vv[i] = vv[i - 1] + vv[i - 2];
        //��ĿҪ�����10000ȡС4λ
        vv[i] %= 10000;
    }

    //��ʼ����
    int n;
    //���뼸��
    while (cin >> n)
    {
        //��������ڼ�λ
        int k;
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            printf("%04d", vv[k]);
        }
        cout << endl;
    }

    return 0;
}