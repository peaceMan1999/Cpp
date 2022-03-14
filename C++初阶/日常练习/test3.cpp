#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;
//
//int main()
//{
//    int numRows = 5;
//    vector<vector<int>> vv;
//    vv.resize(numRows);
//    //开空间
//    for (size_t i = 0; i < numRows; i++)
//    {
//        vv[i].resize(i + 1);
//    }
//    //第一个和最后一个是1；
//    for (size_t i = 0; i < numRows; i++)
//    {
//        vv[i][0] = vv[i][i] = 1;
//    }
//
//    for (size_t i = 2; i < numRows; i++)
//    {
//        for (size_t j = 1; j < i - 1; j++)
//        {
//            vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
//        }
//    }
//
//    return 0;
//}

//int* countBits(int n, int* returnSize) 
//{
//    int* ret = (int*)malloc(sizeof(int) * (n + 1));
//    *returnSize = n + 1;
//    ret[0] = 0;
//    for (int i = 1; i < n + 1; i++)
//    {
//        int count = 0;
//        int k = i;
//        while (k > 1)
//        {
//            count++;
//            k /= 2;
//        }
//        ret[i] = count;
//    }
//    return ret;
//}

//int JudgeSize(int n)
//{
//    int count = 0;
//    for (int i = 0; i < 31; i++)
//    {
//        if ((1 & (n >> i)) == 1)
//            count++;
//    }
//    return count;
//}
//
//int* countBits(int n, int* returnSize) {
//    int* ret = (int*)malloc(sizeof(int) * (n + 1));
//    *returnSize = n + 1;
//    ret[0] = 0;
//    for (int i = 1; i < n + 1; i++)
//    {
//        ret[i] = JudgeSize(i);
//    }
//    return ret;
//}
//


//int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
//    //int* count = (int*)malloc(sizeof(int) * (numsSize + 1));
//    int* count = (int*)calloc((numsSize + 1) * 4, sizeof(int));
//    for (int i = 0; i < numsSize; i++)
//    {
//        count[nums[i]]++;
//    }
//    int k = 0;
//    for (int i = 1; i < numsSize+1; i++)
//    {
//        if (count[i] == 0)
//            k++;
//    }
//    int* find = (int*)malloc(sizeof(int) * k);
//    int j = 0;
//    for (int i = 1; i < numsSize; i++)
//    {
//        if (count[i] == 0)
//            find[j++] = i + 1;
//    }
//    *returnSize = k;
//    return find;
//}
//
//class Solution {
//public:
//    string reverseStr(string s, int k) {
//        int sz = s.size() - 1;
//        string::iterator a = s.begin();
//        while (sz >= 2 * k)
//        {
//            reverse(a, a + k);
//            if (sz <= k * 2)
//                a += k;
//            else
//                a += k * 2;
//            sz -= (k * 2);
//        }
//        if (sz == 0)
//            return s;
//        else if (sz <= k)
//        {
//            if (sz < k && sz != 0)
//            {
//                reverse(a, s.end());
//            }
//            else
//            {
//                reverse(a, a + k);
//            }
//        }
//        else
//        {
//            reverse(a, a + k);
//        }
//        return s;
//    }
//};
//
//class Solution {
//public:
//    string reverseWords(string s) {
//        size_t sz = s.find(' ');
//        int i = 0;
//        while (sz != string::npos)
//        {
//            reverse(s.begin() + i, s.begin() + sz);
//            i = sz + 1;
//            sz = s.find(' ', sz + 1);
//        }
//        reverse(s.begin() + i, s.end());
//        return s;
//    }
//};

//class Solution {
//public:
//    string multiply(string num1, string num2) {
//        vector<int> A, B;
//        int n = num1.size(), m = num2.size();
//        for (int i = n - 1; i >= 0; i--) A.push_back(num1[i] - '0'); //反向存贮
//        for (int i = m - 1; i >= 0; i--) B.push_back(num2[i] - '0');
//        vector<int> C(n + m);
//        for (int i = 0; i < n; i++)
//            for (int j = 0; j < m; j++)
//                C[i + j] += A[i] * B[j];
//        int t = 0;  //存贮进位
//        for (int i = 0; i < C.size(); i++) {
//            t += C[i];
//            C[i] = t % 10;
//            t /= 10;
//        }
//        int k = C.size() - 1;
//        while (k > 0 && !C[k]) k--;  //去除前导0
//        string res;
//        while (k >= 0) res += C[k--] + '0';  //反转
//        return res;
//    }
//};

class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> A, B;
        int n = num1.size();
        int m = num2.size();
        for (int i = n - 1; i >= 0; i--)
            A.push_back(num1[i] - '0');
        for (int i = m - 1; i >= 0; i--)
            B.push_back(num2[i] - '0');
        vector<int> C(n + m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                C[i + j] += A[i] * B[j];
            }
        }
        int t = 0;
        for (int i = 0; i < n + m; i++)
        {
            t += C[i];
            C[i] = t % 10;
            t /= 10;
        }
        int k = C.size() - 1;
        if (k > 0 && C[k] == 0)
            k--;
        string s1;
        while (k >= 0)
            s1 += C[k--] + '0';
        return s1;
    }
};

int main()
{
    Solution s1;
    string s2;
    s2 = s1.multiply("123","456");

    return 0;
}