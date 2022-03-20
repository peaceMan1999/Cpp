#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;


/*1
给定一个仅包含数字 2 - 9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]

*/

class Solution {
public:
    string nums[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    void _letterCombinations(vector<string>& s1, size_t i, const string& digits, string str)
    {
        if (i == digits.size())
        {
            s1.push_back(str);
            return;
        }


        for (auto ch : nums[digits[i] - '0'])
        {
            _letterCombinations(s1, i + 1, digits, str + ch);
        }

    }

    vector<string> letterCombinations(string digits) {
        vector<string> s1;
        if (digits.empty())
            return s1;
        size_t i = 0;
        string str;
        _letterCombinations(s1, i, digits, str);
        return s1;
    }

    void f1()
    {
        letterCombinations("23");
    }
};

/*2
给一个长度为 n 的数组，数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组[1,2,3,2,2,2,5,4,2]。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。

数据范围：n \le 50000n≤50000，数组中元素的值 0 \le val \le 100000≤val≤10000
要求：空间复杂度：O(1)O(1)，时间复杂度 O(n)O(n)

输入：
[1,2,3,2,2,2,5,4,2]
返回值：
2

*/

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int sz = numbers.size();
        sort(numbers.begin(), numbers.end());
        return numbers[sz / 2];
    }
};

int main()
{
    //Solution::f1();
}

