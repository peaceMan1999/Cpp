#define _CRT_SECURE_NO_WARNINGS 1

/*   1

���ӣ�https://www.nowcoder.com/questionTerminal/9d1559511b3849deaa71b576fa7009dc
��Դ��ţ����

A = ��aba����B = ��b����������4�ְ�B����A�İ취��
* ��A�ĵ�һ����ĸ֮ǰ: "baba" ���ǻ���
* �ڵ�һ����ĸ��a��֮��: "abba" �ǻ���
* ����ĸ��b��֮��: "abba" �ǻ���
* �ڵڶ�����ĸ'a'֮�� "abab" ���ǻ���
�������������Ĵ�Ϊ2
*/

#include <iostream>
#include <string>

using namespace std;

bool IsReverse(string str)
{
    int begin = 0, end = str.size() - 1;
    while (begin < end)
    {
        if (str[begin] != str[end])
        {
            return false;
        }
        begin++;
        end--;
    }
    return true;
}

int main()
{
    string s1, s2, str;
    cin >> s1 >> s2;

    int count = 0;
    for (int i = 0; i < s1.size() + 1; i++)
    {
        str = s1;
        str.insert(i, s2);

        if (IsReverse(str))
        {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}


/*   2

989. ������ʽ�������ӷ�
*/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int sz = 0, n = k, sz2 = num.size();
        while (n)
        {
            sz++;
            n /= 10;
        }
        sz = (sz > sz2 ? sz + 1 : sz2 + 1);
        vector<int> vv;
        vv.reserve(sz);
        int flag = 0, j = 0;
        while (k > 0 || sz2 > 0)
        {
            int sum = 0;
            if (k > 0 && sz2 > 0)
            {
                sum = (k % 10) + num[--sz2] + flag;
                flag = 0;
                k /= 10;
            }
            else if (sz2 > 0 && k <= 0)
            {
                sum = num[--sz2] + flag;
                flag = 0;
            }
            else if (k > 0 && sz2 <= 0)
            {
                sum = (k % 10) + flag;
                k /= 10;
                flag = 0;
            }
            if (sum > 9)
            {
                sum -= 10;
                flag = 1;
            }
            vv.push_back(sum);
        }

        if (flag > 0)
        {
            vv.push_back(1);
        }
        reverse(vv.begin(), vv.end());
        return vv;
    }
};

/*   3

����: nums = [1,2,3,4,5,6,7], k = 3
���: [5,6,7,1,2,3,4]
����:
������ת 1 ��: [7,1,2,3,4,5,6]
������ת 2 ��: [6,7,1,2,3,4,5]
������ת 3 ��: [5,6,7,1,2,3,4]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/rotate-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        reverse(nums.begin(), nums.end());
        int sz = nums.size();
        while (k > sz)
            k -= sz;
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};


/*   4

�ϲ�������������

���룺nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
�����[1,2,2,3,5,6]
���ͣ���Ҫ�ϲ� [1,2,3] �� [2,5,6] ��
�ϲ������ [1,2,2,3,5,6] ������б��Ӵֱ�ע��Ϊ nums1 �е�Ԫ�ء�

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/merge-sorted-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pm = m - 1, pn = n - 1, pv = m + n - 1;
        while (pm >= 0 && pn >= 0)
        {
            if (nums1[pm] < nums2[pn])
                nums1[pv--] = nums2[pn--];
            else
                nums1[pv--] = nums1[pm--];
        }

        while (pn >= 0)
        {
            nums1[pv--] = nums2[pn--];
        }

    }
};