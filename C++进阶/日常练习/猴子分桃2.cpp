/*

链接：https://www.nowcoder.com/questionTerminal/480d2b484e1f43af8ea8434770811b4a
来源：牛客网

老猴子辛苦了一辈子，给那群小猴子们留下了一笔巨大的财富——一大堆桃子。老猴子决定把这些桃子分给小猴子。
第一个猴子来了，它把桃子分成五堆，五堆一样多，但还多出一个。它把剩下的一个留给老猴子，自己拿走其中的一堆。
第二个猴子来了，它把桃子分成五堆，五堆一样多，但又多出一个。它把多出的一个留给老猴子，自己拿走其中的一堆。
后来的小猴子都如此照办。最后剩下的桃子全部留给老猴子。
这里有n只小猴子，请你写个程序计算一下在开始时至少有多少个桃子，以及最后老猴子最少能得到几个桃子。

*/

// write your code here cpp
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0) {
            break;
        }
        long long a = (pow(5, n) - 4);
        long long b = (pow(4, n) - 4 + n);
        cout << a << " " << b << endl;
    }
    return 0;
}



