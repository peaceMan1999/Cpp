#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <limits.h>

using namespace std;

/*
[编程题]手套--牛客网
*/

class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
        // write code here
        int left_sum = 0, right_sum = 0, left_min = INT_MAX, right_min = INT_MAX;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (left[i] * right[i] == 0)
                sum += left[i] + right[i];
            else
            {
                left_sum += left[i];
                left_min = left_min < left[i] ? left_min : left[i];
                right_sum += right[i];
                right_min = right_min < right[i] ? right_min : right[i];
            }
        }
        return sum + min(left_sum - left_min + 1, right_sum - right_min + 1) + 1;
    }
};


/*
链接：https://www.nowcoder.com/questionTerminal/0a92c75f5d6b4db28fcfa3e65e5c9b3f
来源：牛客网

[编程题]扑克牌大小
扑克牌游戏大家应该都比较熟悉了，一副牌由54张组成，含3~A，2各4张，小王1张，大王1张。牌面从小到大用如下字符和字符串表示（其中，小写joker表示小王，大写JOKER表示大王）:)
3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
输入两手牌，两手牌之间用“-”连接，每手牌的每张牌以空格分隔，“-”两边没有空格，如：4 4 4 4-joker JOKER
请比较两手牌大小，输出较大的牌，如果不存在比较关系则输出ERROR

基本规则：
（1）输入每手牌可能是个子，对子，顺子（连续5张），三个，炸弹（四个）和对王中的一种，不存在其他情况，由输入保证两手牌都是合法的，顺子已经从小到大排列；
（2）除了炸弹和对王可以和所有牌比较之外，其他类型的牌只能跟相同类型的存在比较关系（如，对子跟对子比较，三个跟三个比较），不考虑拆牌情况（如：将对子拆分成个子）
（3）大小规则跟大家平时了解的常见规则相同，个子，对子，三个比较牌面大小；顺子比较最小牌大小；炸弹大于前面所有的牌，炸弹之间比较牌面大小；对王是最大的牌；
（4）输入的两手牌不会出现相等的情况。

答案提示：
（1）除了炸弹和对王之外，其他必须同类型比较。
（2）输入已经保证合法性，不用检查输入是否是合法的牌。
（3）输入的顺子已经经过从小到大排序，因此不用再排序了.

数据范围：保证输入合法

*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string GetBigger(const string& poker)
{
    //找王炸
    if (poker.find("joker JOKER") != string::npos)
        return "joker JOKER";
    //分开两手牌
    int delimit = poker.find('-');
    string hand1 = poker.substr(0, delimit);
    string hand2 = poker.substr(delimit + 1);
    //查看手牌张数
    int hand1_num = count(hand1.begin(), hand1.end(), ' ') + 1;
    int hand2_num = count(hand2.begin(), hand2.end(), ' ') + 1;
    //取他们的首位
    string hand1_first = hand1.substr(0, hand1.find(' '));
    string hand2_first = hand2.substr(0, hand2.find(' '));
    //比较
    if (hand1_num == hand2_num)
    {
        string str = "345678910JQKA2jokerJOKER";
        if (str.find(hand1_first) > str.find(hand2_first))
            return hand1;
        else
            return hand2;
    }

    if (hand1_num == 4)
        return hand1;
    else if (hand2_num == 4)
        return hand2;
    else
        return "ERROR";
}

int main()
{
    string poker;
    while (getline(cin, poker))
    {
        cout << GetBigger(poker) << endl;
    }

    return 0;
}

/*
[编程题]二叉树的镜像
*/

class Solution {
public:
    TreeNode* Mirror(TreeNode* pRoot) {
        // write code here
        if (pRoot == nullptr)
            return nullptr;

        TreeNode* tmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tmp;

        if (pRoot->left != nullptr)
            Mirror(pRoot->left);
        if (pRoot->right != nullptr)
            Mirror(pRoot->right);

        return pRoot;
    }
};