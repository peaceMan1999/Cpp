#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//char* convertToTitle(int columnNumber) {
//    static char arr[32] = "";
//    int k = columnNumber;
//    int i = 0;
//    //大于‘Z’的都要分解
//    while (k > 26)
//    {
//        arr[i++] = (k % 26)-1 + 'A';
//        k /= 26;
//    }
//    arr[i] = 'A' + (k - 1);
//    //翻转字符串
//    int sz = strlen(arr);
//    if (sz == 1)
//        return arr;
//    int left = 0, right = sz - 1;
//    while (left < right)
//    {
//        char tmp = arr[left];
//        arr[left] = arr[right];
//        arr[right] = tmp;
//        left++;
//        right--;
//    }
//    return arr;
//}
//char* convertToTitle(int columnNumber) {
//    int pos = 8;
//    static char arr[10] = "";
//
//    //从结尾开始放;
//    arr[pos + 1] = '\0';
//    while (columnNumber>1)
//    {
//        int k = columnNumber % 26;
//        columnNumber /= 26;
//        if (k == 0)
//            arr[pos--] = 'Z';
//        else
//            arr[pos--] = 'A' + k - 1;
//
//    }
//
//    return &arr[pos+1];
//}


//int majorityElement(int* nums, int numsSize) {
//    if (numsSize == 1)
//        return nums[0];
//    int max = nums[0];
//    int min = nums[0];
//    //1，遍历数组，算出相对映像
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (nums[i] > max)
//            max = nums[i];
//        else if (nums[i] < min)
//            min = nums[i];
//    }
//    int gap = max - min + 1;
//    //2,填充count数组
//    int* count = (int*)malloc(sizeof(int) * gap);
//    memset(count, 0, sizeof(int) * gap);
//    for (int i = 0; i < numsSize; i++)
//    {
//        count[nums[i] - min]++;
//    }
//    //3，遍历数组哪个下标最大
//    int countnums = 0;
//    for (int i = 0; i < gap; i++)
//    {
//        if (count[i] > countnums)
//            countnums = i;
//    }
//    return countnums+gap-1;
//}
//bool isIsomorphic(char* s, char* t) {
//    int ss[128] = { 0 };
//    int tt[128] = { 0 };
//    int sc = 0, tc = 0;
//    for (int i = 0; s[i] != '\0'; i++) {
//        if (ss[s[i]] == 0)
//            ss[s[i]] = ++sc;
//        if (tt[t[i]] == 0)
//            tt[t[i]] = ++tc;
//        if (ss[s[i]] != tt[t[i]])
//            return false;
//    }
//    return true;
//}
//bool isIsomorphic(char* s, char* t) {
//    int count_s[126] = { 0 };
//    int count_t[126] = { 0 };
//    int sc = 0, tc = 0;
//    while (*s)
//    {
//        if (count_s[*s] == 0)
//            count_s[*s] = ++sc;
//        if (count_t[*t] == 0)
//            count_t[*t] = ++tc;
//        if (count_s[*s] != count_t[*t])
//            return false;
//        s++;
//        t++;
//    }
//    return true;
//}
//int main()
//{
//    char s[] = "papap";
//    char t[] = "titii";
//    isIsomorphic(s, t);
//	return 0;
//}
//
//class Solution {
//public:
//    bool isletter(char x)
//    {
//        if ((x >= 'a' && x <= 'z') || (x >= '0' && x <= '9'))
//            return true;
//        else
//            return false;
//    }
//
//    bool isPalindrome(string s) {
//        for (auto& ch : s)
//        {
//            if (ch >= 'A' && ch <= 'Z')
//                ch += 32;
//        }
//        int left = 0, right = s.size() - 1;
//        while (left < right)
//        {
//            while (left < right && !isletter(s[left]))
//                left++;
//            while (left < right && !isletter(s[right]))
//                right--;
//            if (s[left] != s[right])
//                return false;
//            left++;
//            right--;
//        }
//        return true;
//    }
//};
//class Solution {
//public:
//    string addStrings(string num1, string num2) {
//        int end1 = num1.size() - 1;
//        int end2 = num2.size() - 1;
//        string copy;
//        int count = 0;
//        while (end1 >= 0 || end2 >= 0)
//        {
//            int ret = 0;
//            if (end2 < 0 && end1 >= 0)
//            {
//                ret = num1[end1--] - '0' + count;
//            }
//            else if (end1 < 0 && end2 >= 0)
//            {
//                ret = num2[end2--] - '0' + count;
//            }
//            else
//            {
//                ret = (num1[end1--] - '0') + (num2[end2--] - '0') + count;
//            }
//            count = 0;
//            if (ret > 9)
//            {
//                ret -= 10;
//                count = 1;
//            }
//            //copy += ret + '0';
//            copy.insert(0, 1, ret + '0');
//        }
//        if (count == 1)
//            copy.insert(0, 1, '1');
//        //copy += ret +'0';
//        return copy;
//    }
//};
//
//class Solution {
//public:
//    int firstUniqChar(string s) {
//        int count[26] = { 0 };
//        for (auto& ch : s)
//        {
//            count[ch - 'a']++;
//        }
//        int i = 0;
//        while (count[s[i] - 'a'] != 1)
//        {
//            i++;
//        }
//        return i;
//    }
//};
//int main()
//{
//    Solution s1;
//    s1.firstUniqChar("leetcode");
//	return 0;
//}
//


//#include<iostream>
//using namespace std;

//int main()
//{
//    string s;
//    while (cin >> s)
//    {
//        int count[26] = { 0 };
//        for (auto ch : s)
//        {
//            count[ch - 'a']++;
//        }
//        int i = 0;
//        for (i = 0; i < s.size(); i++)
//        {
//            if (count[s[i] - 'a'] == 1)
//            {
//                cout << s[i] << endl;
//                break;
//            }
//        }
//        cout << "-1" << endl;
//    }
//    return 0;
//}

class Solution {
public:
    string multiply(string num1, string num2) {
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        int sum = 0, count = 0, nextcarry = 1;
        for (int i = num2.size()-1; i >= 0; i--)
        {
            int carry = 1;
            int one = (num1[i] - '0') * nextcarry;
            for (int j = num1.size()-1; j >= 0; j--)
            {
                int two = num2[j] - '0';
                sum += one * two * carry;
                carry *= 10;
            }
            nextcarry *= 10;
        }
        return num1;
    }
};

int main()
{
    string s1 = "456";
    string s2 = "567";
    Solution n1;

    n1.multiply(s1, s2);

    return 0;
}