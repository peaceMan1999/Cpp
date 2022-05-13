#define _CRT_SECURE_NO_WARNINGS 1

/*

链接：https://www.nowcoder.com/questionTerminal/0f6976af36324f8bab1ea61e9e826ef5
来源：牛客网

所谓因子分解，就是把给定的正整数a，分解成若干个素数的乘积，
即 a = a1 × a2 × a3 × ... × an,并且 1 < a1 ≤ a2 ≤ a3 ≤ ... ≤ an。其中a1、a2、...、an均为素数。 
先给出一个整数a，请输出分解后的因子。

对应每组数据，以“a = a1 * a2 * a3...”的形式输出因式分解后的结果。
*/

// write your code here cpp
#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        cout << n << " = ";
        for (int i = 2; i < (n / 2) + 1; i++)
        {
            while (n % i == 0)
            {
                cout << i;
                n /= i;
                if (n != 1)
                    cout << " * ";
            }
        }
        if (n != 1)
            cout << n;
        cout << endl;
    }

    return 0;
}