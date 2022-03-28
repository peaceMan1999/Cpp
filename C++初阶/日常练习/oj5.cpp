#define _CRT_SECURE_NO_WARNINGS 1

/*   1

链接：https://www.nowcoder.com/questionTerminal/9d1559511b3849deaa71b576fa7009dc
来源：牛客网

A = “aba”，B = “b”。这里有4种把B插入A的办法：
* 在A的第一个字母之前: "baba" 不是回文
* 在第一个字母‘a’之后: "abba" 是回文
* 在字母‘b’之后: "abba" 是回文
* 在第二个字母'a'之后 "abab" 不是回文
所以满足条件的答案为2
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

989. 数组形式的整数加法
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

输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右轮转 1 步: [7,1,2,3,4,5,6]
向右轮转 2 步: [6,7,1,2,3,4,5]
向右轮转 3 步: [5,6,7,1,2,3,4]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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

合并两个有序数组

输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
输出：[1,2,2,3,5,6]
解释：需要合并 [1,2,3] 和 [2,5,6] 。
合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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