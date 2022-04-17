#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int  LuckyNum(vector<int>& vv, int n, int pos, int sum, int multi)
{
    //数组， n， 当前位置， 次数， 和， 积
    int count = 0;
    for (int i = pos; i < n; i++)
    {
        sum += vv[i];
        multi *= vv[i];
        //判断幸运
        if (sum > multi)
        {
            count += 1 + LuckyNum(vv, n, i + 1, sum, multi);
        }
        else if (vv[i] == 1)
            count += LuckyNum(vv, n, i + 1, sum, multi);
        else
            break;
        //回退
        sum -= vv[i];
        multi /= vv[i];

        while (i < n - 1 && vv[i] == vv[i + 1])
            i++;
    }

    return count;
}

int main()
{
    int n, m, sum, multi, count = 0;
    while (cin >> n)
    {
        vector<int> vv(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vv[i];
        }
        sort(vv.begin(), vv.end());
        cout << LuckyNum(vv, n, 0, 0, 1) << endl;
    }

    return 0;
}