#define _CRT_SECURE_NO_WARNINGS 1

/*   1

链接：https://www.nowcoder.com/questionTerminal/4284c8f466814870bae7799a07d49ec8
来源：牛客网

[编程题]跳石板
热度指数：31661时间限制：C/C++ 1秒，其他语言2秒空间限制：C/C++ 32M，其他语言64M
算法知识视频讲解
小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......
这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的 石板，小易单次只能往前跳K的一个约数(不含1和K)步，即跳到K+X(X为K的一个非1和本身的约数)的位置。 小易当前处在编号为N的石板，他想跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达。
例如：
N = 4，M = 24：
4->6->8->12->18->24
于是小易最少需要跳跃5次，就可以从4号石板跳到24号石板

输入描述:
输入为一行，有两个整数N，M，以空格隔开。 (4 ≤ N ≤ 100000) (N ≤ M ≤ 100000)


输出描述:
输出小易最少需要跳跃的步数,如果不能到达输出-1

*/

#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
using namespace std;

void GetStep(int v, vector<int>& step)
{
    for (int i = 2; i <= sqrt(v); i++)//由于会提示操作过于繁琐，所以用开根号
    {
        if (v % i == 0)
        {
            step.push_back(i);
            if (v / i != i)
                step.push_back(v / i);
        }
    }
}

int MinStep(int n, int m)
{
    vector<int> all_step(m + 1, INT_MAX);//初始化成最大值，表示无法到达
    all_step[n] = 0;

    for (int i = n; i <= m; i++)
    {
        if (all_step[i] == INT_MAX) // 说明无法到达
            continue;

        vector<int> step;//用来存每个的约数步数
        GetStep(i, step);

        for (int j = 0; j < step.size(); j++)
        {
            //不能大于m，且判断取小的
            if (step[j] + i <= m && all_step[i + step[j]] != INT_MAX)
            {
                all_step[i + step[j]] =
                    all_step[i + step[j]] < all_step[i] + 1
                    ? all_step[i + step[j]] : all_step[i] + 1;
            }
            else if (step[j] + i <= m && all_step[i + step[j]] == INT_MAX)//没走过就赋值
                all_step[i + step[j]] = all_step[i] + 1;
        }
    }
    return all_step[m] == INT_MAX ? -1 : all_step[m];
}

int main()
{
    int n, m, count;

    while (cin >> n >> m)
    {
        count = MinStep(n, m);
        cout << count << endl;
    }

    return 0;
}

/*    2

链接：https://www.nowcoder.com/questionTerminal/668603dc307e4ef4bb07bcd0615ea677
来源：牛客网

在命令行输入如下命令：

xcopy /s c:\\ d:\\e，

各个参数如下：

参数1：命令字xcopy

参数2：字符串/s

参数3：字符串c:\\

参数4: 字符串d:\\e

请编写一个参数解析程序，实现将命令行各个参数解析出来。


解析规则：

1.参数分隔符为空格
2.对于用""包含起来的参数，如果中间有空格，不能解析为多个参数。比如在命令行输入xcopy /s "C:\\program files" "d:\"时，参数仍然是4个，第3个参数应该是字符串C:\\program files，而不是C:\\program，注意输出参数时，需要将""去掉，引号不存在嵌套情况。
3.参数不定长

4.输入由用例保证，不会出现不符合要求的输入
数据范围：字符串长度：1\le s\le 1000\1≤s≤1000
进阶：时间复杂度：O(n)\O(n) ，空间复杂度：O(n)\O(n)

输入描述:
输入一行字符串，可以有空格



输出描述:
输出参数个数，分解后的参数，每个参数都独占一行

示例1
输入
xcopy /s c:\\ d:\\e
输出
4
xcopy
/s
c:\\
d:\\e

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void GetStr(string& str)
{
    vector<string> vv;
    string tmp;
    bool is_marks = false;//双引号判断字符串

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '"')//""内的是字符串
        {
            is_marks = !is_marks;
        }
        else if (str[i] == ' ' && !is_marks)//判空截断
        {
            vv.push_back(tmp);
            tmp.clear();
        }
        else//都不是就可以插入
        {
            tmp += str[i];
        }
    }
    //最后一截没加入
    vv.push_back(tmp);
    //输出
    cout << vv.size() << endl;
    for (int i = 0; i < vv.size(); i++)
    {
        cout << vv[i] << endl;
    }
}

int main()
{
    string str;
    getline(cin, str);

    GetStr(str);

    return 0;
}