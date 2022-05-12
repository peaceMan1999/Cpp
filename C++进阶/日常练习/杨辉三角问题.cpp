#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

/*

以上三角形的数阵，第一行只有一个数1，以下每行的每个数，是恰好是它上面的数、左上角数和右上角的数，3个数之和（如果不存在某个数，认为该数就是0）。

求第n行第一个偶数出现的位置。如果没有偶数，则输出-1。例如输入3,则输出2，输入4则输出3，输入2则输出-1。

*/

int main()
{
    int index[] = { 3, 2, 4, 2 };
    int n;
    while (cin >> n)
    {
        if (n < 3)
            cout << -1 << endl;
        else
        {
            int ret = index[n % 4];
            cout << ret << endl;
        }
    }
    return 0;
}