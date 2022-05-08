#define _CRT_SECURE_NO_WARNINGS 1

/*
链接：https://www.nowcoder.com/questionTerminal/1d18c0841e64454cbc3afaea05e2f63c
来源：牛客网

居然有假币！ 现在猪肉涨了，但是农民的工资却不见涨啊，没钱怎么买猪肉啊。nowcoder这就去买猪肉，结果找来的零钱中有假币！！！
可惜nowcoder 一不小心把它混进了一堆真币里面去了。只知道假币的重量比真币的质量要轻，给你一个天平（天平两端能容纳无限个硬币），
请用最快的时间把那个可恶的假币找出来。

1≤n≤2^30,输入0结束程序。

*/

// write your code here cpp
#include <iostream>
using namespace std;
// 分成 (1/3)n , (1/3)n , (1/3)n；
// 如果是多一个就 (1/3)n , (1/3)n , (1/3)n+1；
// 如果多两个就是 (1/3)n , (1/3)n+1 , (1/3)n+1；
// 而非(1/3)n , (1/3)n , (1/3)n+2；
int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)//0就退出
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