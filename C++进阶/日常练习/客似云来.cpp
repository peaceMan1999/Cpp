#define _CRT_SECURE_NO_WARNINGS 1

/*

���ӣ�https://www.nowcoder.com/questionTerminal/3549ff22ae2c4da4890e9ad0ccb6150d
��Դ��ţ����

NowCoder����һ����͵꣬��ҵ�Ŀ��˶��и���ֵ��ã�����ֻҪ����ҵ�Թ�һ����ͣ��ͻ�ÿ�춼������
���ң�����������ҵ����������ͺ󣬽�����ÿ�춼���һλ������һ����Ʒ����
���ǣ���ҵ�Ŀ��˴����һ���˷�չ�ɺƺƵ����ɰ���ǧ�ˣ�1��1��2��3��5����
���ڣ�NowCoder�������æͳ��һ�£�ĳһ��ʱ�䷶Χ�����ܹ��������ٷ���ͣ�����ÿλ����ֻ��һ����ͣ���

�������ݰ������顣
ÿ�����ݰ�����������from��to(1��from��to��80)���ֱ������ĵ�from��͵�to��
*/

// write your code here cpp
#include <iostream>
using namespace std;

int main()
{
    long long arr[81] = { 0 };
    arr[1] = 1, arr[2] = 1;
    for (int i = 3; i <= 81; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    int from, to;
    while (cin >> from >> to)
    {
        long long sum = 0;
        for (int i = from; i <= to; i++)
        {
            sum += arr[i];
        }
        cout << sum << endl;
    }
    return 0;
}