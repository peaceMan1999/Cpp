#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

/*
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

数据范围：0 < n <= 200
进阶： 空间复杂度O(1)  ，时间复杂度O(n)
*/

class A
{
    friend class Solution;
public:
    A()
    {
        _ret += _i;
        _i++;
    }

private:
    static int _i;
    static int _ret;
};
int A::_i = 1;
int A::_ret = 0;

class Solution {
public:
    int Sum_Solution(int n) {
        int _i = 1, _ret = 0;
        A add[n];
        return A::_ret;
    }
};