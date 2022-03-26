#define _CRT_SECURE_NO_WARNINGS 1

/*  1

牛牛举办了一次编程比赛,参加比赛的有3*n个选手,每个选手都有一个水平值a_i.现在要将这些选手进行组队,一共组成n个队伍,即每个队伍3人.牛牛发现队伍的水平值等于该队伍队员中第二高水平值。
例如:
一个队伍三个队员的水平值分别是3,3,3.那么队伍的水平值是3
一个队伍三个队员的水平值分别是3,2,3.那么队伍的水平值是3
一个队伍三个队员的水平值分别是1,5,2.那么队伍的水平值是2
为了让比赛更有看点,牛牛想安排队伍使所有队伍的水平值总和最大。
如样例所示:
如果牛牛把6个队员划分到两个队伍
如果方案为:
team1:{1,2,5}, team2:{5,5,8}, 这时候水平值总和为7.
而如果方案为:
team1:{2,5,8}, team2:{1,5,5}, 这时候水平值总和为10.
没有比总和为10更大的方案,所以输出10.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int sz;
    cin >> sz;
    vector<int> vv;
    vv.resize(3 * sz);

    for (int i = 0; i < 3 * sz; i++)
    {
        cin >> vv[i];
    }
    sort(vv.begin(), vv.end());
    long long sum = 0;
    for (int i = 0; i < sz; i++)
    {
        sum += vv[sz + 2 * i];
    }
    cout << sum << endl;
    return 0;
}


/*  2
链接：https://www.nowcoder.com/questionTerminal/2d3f6ddd82da445d804c95db22dcc471?page=1&onlyReference=false
来源：牛客网

牛牛定义排序子序列为一个数组中一段连续的子序列,并且这段子序列是非递增或者非递减排序的。牛牛有一个长度为n的整数数组A,他现在有一个任务是把数组A分为若干段排序子序列,牛牛想知道他最少可以把这个数组分为几段排序子序列.
如样例所示,牛牛可以把数组A划分为[1,2,3]和[2,2,1]两个排序子序列,至少需要划分为2个排序子序列,所以输出2
*/


#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<int> vv;
    vv.resize(n + 1);//方便下面判断[n+1]
    for (int i = 0; i < n; i++)
    {
        cin >> vv[i];
    }
    int i = 0, count = 0;

    while (i < n)
    {
        //非递增
        if (vv[i] < vv[i + 1])
        {
            while (i < n && vv[i] <= vv[i + 1])
            {
                i++;
            }
            count++;
            i++;
        }
        //相等
        else if (vv[i] == vv[i + 1])
            i++;
        //非递减
        else
        {
            while (i < n && vv[i] >= vv[i + 1])
            {
                i++;
            }
            count++;
            i++;
        }
    }
    cout << count << endl;

    return 0;
}

/*  3
给一个长度为 n 的数组，数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组[1,2,3,2,2,2,5,4,2]。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。

数据范围：n \le 50000n≤50000，数组中元素的值 0 \le val \le 100000≤val≤10000
要求：空间复杂度：O(1)O(1)，时间复杂度 O(n)O(n)
*/

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int sz = numbers.size();
        sort(numbers.begin(), numbers.end());
        int count = 0, x = numbers[0];
        for (int i = 0; i < sz; i++)
        {
            if (numbers[i] == x)
                count++;
            else
                count--;
            if (count < 0)
            {
                count = 0;
                x = numbers[i];
            }
        }
        return x;
    }
};

/*  4

链接：https://www.nowcoder.com/questionTerminal/02d8d42b197646a5bbd0a98785bb3a34
来源：牛客网

A,B,C三个人是好朋友,每个人手里都有一些糖果,我们不知道他们每个人手上具体有多少个糖果,但是我们知道以下的信息：
A - B, B - C, A + B, B + C. 这四个数值.每个字母代表每个人所拥有的糖果数.
现在需要通过这四个数值计算出每个人手里有多少个糖果,即A,B,C。这里保证最多只有一组整数A,B,C满足所有题设条件。

输出为一行，如果存在满足的整数A，B，C则按顺序输出A，B，C，用空格隔开，行末无空格。 如果不存在这样的整数A，B，C，则输出No
*/

#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d;
    int A, B1, B2, C;
    cin >> a >> b >> c >> d;
    A = (a + c) / 2;
    B1 = (d + b) / 2;
    B2 = (c - a) / 2;
    C = (d - b) / 2;

    if (B1 != B2)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << A << " " << B1 << " " << C << endl;
    }

    return 0;
}


/*   5

给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数

*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int m, m1, n;
    cin >> m >> n;
    m1 = m;
    bool flag = false;
    if (m < 0)
    {
        flag = true;
        m = -m;
    }
    string s = "0123456789ABCDEF";
    string nums;
    while (m > 0)
    {
        nums += s[m % n];
        m /= n;
    }
    if (flag)
        nums += '-';
    reverse(nums.begin(), nums.end());
    if (m1 == 0)
        cout << '0' << endl;
    else
        cout << nums << endl;

    return 0;
}
