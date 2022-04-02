#define _CRT_SECURE_NO_WARNINGS 1

/*
链接：https://www.nowcoder.com/questionTerminal/e1bb714eb9924188a0d5a6df2216a3d1
来源：牛客网

[编程题]井字棋

给定一个二维数组board，代表棋盘，其中元素为1的代表是当前玩家的棋子，0表示没有棋子，-1代表是对方玩家的棋子。当一方棋子在横竖斜方向上有连成排的及获胜（及井字棋规则），返回当前玩家是否胜出。

测试样例：
[[1,0,1],[1,-1,-1],[1,-1,0]]
返回：true

*/

class Board {
public:
    bool checkWon(vector<vector<int> > board) {
        int row = board.size();
        //一行都是
        for (int i = 0; i < row; i++)
        {
            int sum = 0;
            for (int j = 0; j < row; j++)
            {
                sum += board[i][j];
            }
            if (sum == row)
                return true;
        }
        //一列都是
        for (int i = 0; i < row; i++)
        {
            int sum = 0;
            for (int j = 0; j < row; j++)
            {
                sum += board[j][i];
            }
            if (sum == row)
                return true;
        }
        //斜线
        int sum = 0;
        for (int i = 0; i < row; i++)
        {
            sum += board[i][i];
        }
        if (sum == row)
            return true;
        //反斜线
        sum = 0;
        for (int i = 0; i < row; i++)
        {
            sum += board[i][row - i - 1];
        }
        if (sum == row)
            return true;
        //不是
        return false;
    }
};


/*
标题：密码强度等级 | 时间限制：1秒 | 内存限制：32768K | 语言限制： 不限
【密码强度等级】密码按如下规则进行计分，并根据不同的得分为密码进行安全等级划分。
一、密码长度:
5 分: 小于等于4 个字符
10 分: 5 到7 字符
25 分: 大于等于8 个字符
二、字母:
0 分: 没有字母
10 分: 密码里的字母全都是小（大）写字母
20 分: 密码里的字母符合”大小写混合“
三、数字:
0 分: 没有数字
10 分: 1 个数字
20 分: 大于1 个数字
四、符号:
0 分: 没有符号
10 分: 1 个符号
25 分: 大于1 个符号
五、奖励（只能选符合最多的那一种奖励）:
2 分: 字母和数字
3 分: 字母、数字和符号
5 分: 大小写字母、数字和符号
最后的评分标准:
>= 90: 非常安全
>= 80: 安全（Secure）
>= 70: 非常强
>= 60: 强（Strong）
>= 50: 一般（Average）
>= 25: 弱（Weak）
>= 0: 非常弱（Very_Weak）
对应输出为：
VERY_SECURE
SECURE
VERY_STRONG
STRONG
AVERAGE
WEAK
VERY_WEAK
请根据输入的密码字符串，进行安全评定。
注：
字母：a-z, A-Z
数字：0-9
符号包含如下： (ASCII码表可以在UltraEdit的菜单view->ASCII Table查看)
!"#$%&'()*+,-./ (ASCII码：0x21~0x2F)
:;<=>?@ (ASCII码：0x3A~0x40)
[\]^_` (ASCII码：0x5B~0x60)
{|}~ (ASCII码：0x7B~0x7E)
提示:
1 <= 字符串的长度<= 300
*/

#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    //总分及分别分
    int sum = 0;
    //判断长度
    int sz = s.size();
    if (sz <= 4)
        sum += 5;
    else if (sz <= 7)
        sum += 10;
    else
        sum += 25;
    //判断字母
    int Greater = 0, Less = 0, n1 = 0;
    for (auto& ch : s)
    {
        if (ch >= 'a' && ch <= 'z')
            Less = 1;
        else if (ch >= 'A' && ch <= 'Z')
            Greater = 1;
    }
    if (Greater == 1)
    {
        sum += 10, n1 = 1;
        if (Less == 1)
            sum += 10, n1 = 2;
    }
    else if (Less == 1)
    {
        sum += 10, n1 = 1;
        if (Greater == 1)
            sum += 10, n1 = 2;
    }
    //判断数字
    int Digit = 0, n2 = 0;
    for (auto& ch : s)
    {
        if (ch >= '0' && ch <= '9')
            Digit++;
    }
    if (Digit == 1)
        sum += 10, n2 = 1;
    else if (Digit > 1)
        sum += 20, n2 = 1;
    //判断符号
    int x = 0, n3 = 0;
    for (auto& ch : s)
    {
        if ((ch >= 0x21 && ch <= 0x2F) ||
            (ch >= 0x3A && ch <= 0x40) ||
            (ch >= 0x5B && ch <= 0x60) ||
            (ch >= 0x7B && ch <= 0x7E))
        {
            x++;
        }
    }
    if (x == 1)
        sum += 10, n3 = 1;
    else if (x > 1)
        sum += 25, n3 = 1;
    //奖励
    int good = 0;
    if (n1 > 0 && n2 == 1)
    {
        sum += 2;
        if (n3 == 1)
        {
            sum += 1;
            if (n1 == 2)
            {
                sum += 2;
            }
        }
    }
    //判断总
    if (sum >= 25)
    {
        if (sum >= 50)
        {
            if (sum >= 60)
            {
                if (sum >= 70)
                {
                    if (sum >= 80)
                    {
                        if (sum >= 90)
                            cout << "VERY_SECURE";
                        else
                            cout << "SECURE";
                    }
                    else
                        cout << "VERY_STRONG";
                }
                else
                    cout << "STRONG";
            }
            else
                cout << "AVERAGE";
        }
        else
            cout << "WEAK";
    }
    else//<=0
        cout << "VERY_WEAK";
    点此或手机扫描二维码查看代码编写过程
        return 0;
}
