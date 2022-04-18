#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <limits.h>

using namespace std;

/*
[�����]����--ţ����
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
���ӣ�https://www.nowcoder.com/questionTerminal/0a92c75f5d6b4db28fcfa3e65e5c9b3f
��Դ��ţ����

[�����]�˿��ƴ�С
�˿�����Ϸ���Ӧ�ö��Ƚ���Ϥ�ˣ�һ������54����ɣ���3~A��2��4�ţ�С��1�ţ�����1�š������С�����������ַ����ַ�����ʾ�����У�Сдjoker��ʾС������дJOKER��ʾ������:)
3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
���������ƣ�������֮���á�-�����ӣ�ÿ���Ƶ�ÿ�����Կո�ָ�����-������û�пո��磺4 4 4 4-joker JOKER
��Ƚ������ƴ�С������ϴ���ƣ���������ڱȽϹ�ϵ�����ERROR

��������
��1������ÿ���ƿ����Ǹ��ӣ����ӣ�˳�ӣ�����5�ţ���������ը�����ĸ����Ͷ����е�һ�֣���������������������뱣֤�����ƶ��ǺϷ��ģ�˳���Ѿ���С�������У�
��2������ը���Ͷ������Ժ������ƱȽ�֮�⣬�������͵���ֻ�ܸ���ͬ���͵Ĵ��ڱȽϹ�ϵ���磬���Ӹ����ӱȽϣ������������Ƚϣ��������ǲ���������磺�����Ӳ�ֳɸ��ӣ�
��3����С��������ƽʱ�˽�ĳ���������ͬ�����ӣ����ӣ������Ƚ������С��˳�ӱȽ���С�ƴ�С��ը������ǰ�����е��ƣ�ը��֮��Ƚ������С�������������ƣ�
��4������������Ʋ��������ȵ������

����ʾ��
��1������ը���Ͷ���֮�⣬��������ͬ���ͱȽϡ�
��2�������Ѿ���֤�Ϸ��ԣ����ü�������Ƿ��ǺϷ����ơ�
��3�������˳���Ѿ�������С����������˲�����������.

���ݷ�Χ����֤����Ϸ�

*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string GetBigger(const string& poker)
{
    //����ը
    if (poker.find("joker JOKER") != string::npos)
        return "joker JOKER";
    //�ֿ�������
    int delimit = poker.find('-');
    string hand1 = poker.substr(0, delimit);
    string hand2 = poker.substr(delimit + 1);
    //�鿴��������
    int hand1_num = count(hand1.begin(), hand1.end(), ' ') + 1;
    int hand2_num = count(hand2.begin(), hand2.end(), ' ') + 1;
    //ȡ���ǵ���λ
    string hand1_first = hand1.substr(0, hand1.find(' '));
    string hand2_first = hand2.substr(0, hand2.find(' '));
    //�Ƚ�
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
[�����]�������ľ���
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