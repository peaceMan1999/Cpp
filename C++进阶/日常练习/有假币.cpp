#define _CRT_SECURE_NO_WARNINGS 1

/*
���ӣ�https://www.nowcoder.com/questionTerminal/1d18c0841e64454cbc3afaea05e2f63c
��Դ��ţ����

��Ȼ�мٱң� �����������ˣ�����ũ��Ĺ���ȴ�����ǰ���ûǮ��ô�����Ⱑ��nowcoder���ȥ�����⣬�����������Ǯ���мٱң�����
��ϧnowcoder һ��С�İ��������һ���������ȥ�ˡ�ֻ֪���ٱҵ���������ҵ�����Ҫ�ᣬ����һ����ƽ����ƽ�������������޸�Ӳ�ң���
��������ʱ����Ǹ��ɶ�ļٱ��ҳ�����

1��n��2^30,����0��������

*/

// write your code here cpp
#include <iostream>
using namespace std;
// �ֳ� (1/3)n , (1/3)n , (1/3)n��
// ����Ƕ�һ���� (1/3)n , (1/3)n , (1/3)n+1��
// ������������� (1/3)n , (1/3)n+1 , (1/3)n+1��
// ����(1/3)n , (1/3)n , (1/3)n+2��
int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)//0���˳�
            return 0;
        int count = 0;
        while (n > 1)
        {
            count++;
            n = n / 3 + (n % 3 > 0);
        }
        cout << count << endl;
    }
    return 0;
}