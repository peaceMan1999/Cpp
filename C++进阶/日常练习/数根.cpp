#define _CRT_SECURE_NO_WARNINGS 1

/*

数根可以通过把一个数的各个位上的数字加起来得到。如果得到的数是一位数，那么这个数就是数根；如果结果是两位数或者包括更多位的数字，那么再把这些数字加起来。如此进行下去，直到得到是一位数为止。
比如，对于24 来说，把2 和4 相加得到6，由于6 是一位数，因此6 是24 的数根。
再比如39，把3 和9 加起来得到12，由于12 不是一位数，因此还得把1 和2 加起来，最后得到3，这是一个一位数，因此3 是39 的数根。
现在给你一个正整数，输出它的数根。

输入包含多组数据。

每组数据数据包含一个正整数n（1≤n≤10E1000）。

*/

//这道题给的范围太大，所以只能用字符串一个一个处理

#include <iostream>
#include <string>
using namespace std;

int main()
{
    //由于给的数太大，所以只能用字符串接收，再一个一个位+=
    string str;

    while (cin >> str)
    {
        int num = 0;
        //逐个位+=
        for (int i = 0; i < str.size(); i++)
        {
            num += str[i] - '0';
        }

        int sum = 0;
        //开始循环
        while (num)
        {
            sum += num % 10;
            num /= 10;
            if (num == 0 && sum > 9)
            {
                num = sum;
                sum = 0;
            }
        }

        cout << sum << endl;
    }

    return 0;
}