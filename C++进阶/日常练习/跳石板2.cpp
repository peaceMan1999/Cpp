/*

С��������һ��ʯ��·ǰ��ÿ��ʯ���ϴ�1���ű��Ϊ��1��2��3.......
����ʯ��·Ҫ��������Ĺ������ǰ��������С�׵�ǰ���ڵı��ΪK�� ʯ�壬
С�׵���ֻ����ǰ��K��һ��Լ��(����1��K)����������K+X(XΪK��һ����1�ͱ����Լ��)��λ�á� 
С�׵�ǰ���ڱ��ΪN��ʯ�壬�����������ǡ��ΪM��ʯ��ȥ��С����֪��������Ҫ��Ծ���ο��Ե��
���磺
N = 4��M = 24��
4->6->8->12->18->24
����С��������Ҫ��Ծ5�Σ��Ϳ��Դ�4��ʯ������24��ʯ��
����������
����Ϊһ�У�����������N��M���Կո������ (4 �� N �� 100000) (N �� M �� 100000)
���������
���С��������Ҫ��Ծ�Ĳ���,������ܵ������-1

*/

#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;

void GetNum(std::vector<int>& num, int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0) {
            num.push_back(i);
            if (n / i != i) {
                num.push_back(n / i);
            }
        }
    }
}


int GetFloor(std::vector<int>& vv, int n, int m)
{
    for (int i = n; i <= m; i++)
    {
        if (vv[i] == INT_MAX) {
            continue;
        }
        std::vector<int> num;
        GetNum(num, i);
        for (int j = 0; j < num.size(); j++)
        {
            if (num[j] + i <= m && vv[i] != INT_MAX)
            {
                vv[num[j] + i] = vv[i] + 1 < vv[num[j] + i] ? vv[i] + 1 : vv[num[j] + i];
            }
        }
    }

    return vv[m] == INT_MAX ? -1 : vv[m];
}

int main()
{
    int n, m;
    cin >> n >> m;
    std::vector<int> vv(m + 1, INT_MAX);
    vv[n] = 0;

    cout << GetFloor(vv, n, m) << endl;

    return 0;
}

