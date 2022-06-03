#define _CRT_SECURE_NO_WARNINGS 1

/*
在一个二维数组array中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
[
[1,2,8,9],
[2,4,9,12],
[4,7,10,13],
[6,8,11,15]
]
给定 target = 7，返回 true。

给定 target = 3，返回 false。

数据范围：矩阵的长宽满足 0 \le n,m \le 5000≤n,m≤500 ， 矩阵中的值满足 0 \le val \le 10^90≤val≤10
9

进阶：空间复杂度 O(1)O(1) ，时间复杂度 O(n+m)O(n+m)
*/

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if (array.empty())
            return false;
        if (array[0].empty())
            return false;
        for (int i = array.size() - 1, j = 0; i >= 0 && j < array[i].size();)
        {
            if (array[i][j] > target) // 大于往上走
                i--;
            else if (array[i][j] < target) // 小于往右走
                j++;
            else // 遇到对的
                return true;
        }
        return false;
    }
};