/*

���ӣ�https://www.nowcoder.com/questionTerminal/1d18c0841e64454cbc3afaea05e2f63c
��Դ��ţ����

��Ȼ�мٱң� �����������ˣ�����ũ��Ĺ���ȴ�����ǰ���ûǮ��ô�����Ⱑ��nowcoder���ȥ�����⣬�����������Ǯ���мٱң�������ϧnowcoder һ��С�İ��������һ���������ȥ�ˡ�ֻ֪���ٱҵ���������ҵ�����Ҫ�ᣬ����һ����ƽ����ƽ�������������޸�Ӳ�ң�����������ʱ����Ǹ��ɶ�ļٱ��ҳ�����

��������:
1��n��2^30,����0��������

*/

// write your code here cpp
#include <iostream>

using namespace std;


int main()
{
    long long n;
    while (cin >> n)
    {
        if (n == 0)
            return 0;
        int count = 0;
        while (n > 1)
        {
            n = n / 3 + (n % 3 > 0);
            count++;
        }
        cout << count << endl;
    }

    return 0;
}




