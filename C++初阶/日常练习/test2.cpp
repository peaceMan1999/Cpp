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

class Solution {
public:
    string reverseStr(string s, int k) {
        int sz = s.size()-1;
        string::iterator a = s.begin();
        while (sz >= 2*k)
        {   
            reverse(a, a + k);
            if (sz <= k * 2)
                a += k;
            else
                a += k * 2;
            sz -= (k * 2);
        }
        if (sz <= k)
        {
            if (sz < k && sz != 0)
            {
                reverse(a, s.end());
            }
            else
            {
               reverse(a, a+k);
            }
        }
        else
        {
            reverse(a, a + k);
        }
        return s;
    }
};

int main()
{
    Solution s1;
    string s("abcdefg");
    s1.reverseStr(s, 3);

    return 0;
}