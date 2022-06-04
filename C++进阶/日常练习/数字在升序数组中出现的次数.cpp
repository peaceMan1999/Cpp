#define _CRT_SECURE_NO_WARNINGS 1

/*
给定一个长度为 n 的非降序数组和一个非负数整数 k ，要求统计 k 在数组中出现的次数

数据范围：0 \le n \le 1000 , 0 \le k \le 1000≤n≤1000,0≤k≤100，
数组中每个元素的值满足 0 \le val \le 1000≤val≤100
要求：空间复杂度 O(1)，时间复杂度 O(logn)

重点：时间复杂度要达到 O(logn)
*/

class Solution {
public:
    int BinarySearch(vector<int>& data, float k)
    {
        // 二分查找
        int left = 0, right = data.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (data[mid] < k)
                left = mid + 1;
            else if (data[mid] > k)
                right = mid - 1;
        }
        return left;
    }

    int GetNumberOfK(vector<int> data, int k) {
        // 求出 3.5 和 2.5 的位置再相减
        return BinarySearch(data, k + 0.5) - BinarySearch(data, k - 0.5);
    }
};