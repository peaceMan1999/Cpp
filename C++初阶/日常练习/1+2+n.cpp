#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

/*
��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����

���ݷ�Χ��0 < n <= 200
���ף� �ռ临�Ӷ�O(1)  ��ʱ�临�Ӷ�O(n)
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