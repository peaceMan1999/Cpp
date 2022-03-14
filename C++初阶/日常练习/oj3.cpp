#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//字符串中的第一个唯一字符

class Solution {
public:
    int firstUniqChar(string s) {
        int count[26] = { 0 };
        for (auto ch : s)
        {
            count[ch - 'a']++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (count[s[i] - 'a'] == 1)
                return i;
        }
        return -1;
    }
};

//字符串相加
class Solution {
public:
    string addStrings(string num1, string num2) {
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        string copy;
        int count = 0;
        while (end1 >= 0 || end2 >= 0)
        {
            int ret = 0;
            if (end2 < 0 && end1 >= 0)
            {
                ret = num1[end1--] - '0' + count;
            }
            else if (end1 < 0 && end2 >= 0)
            {
                ret = num2[end2--] - '0' + count;
            }
            else
            {
                ret = (num1[end1--] - '0') + (num2[end2--] - '0') + count;
            }
            count = 0;
            if (ret > 9)
            {
                ret -= 10;
                count = 1;
            }
            //copy += ret + '0';
            copy.insert(0, 1, ret + '0');
        }
        if (count == 1)
            copy.insert(0, 1, '1');
        //copy += ret +'0';
        return copy;
    }
};

