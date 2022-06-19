#define _CRT_SECURE_NO_WARNINGS 1


/*
输入一个长度为n的整型数组array，数组中的一个或连续多个整数组成一个子数组，找到一个具有最大和的连续子数组。
1.子数组是连续的，比如[1,3,5,7,9]的子数组有[1,3]，[3,5,7]等等，但是[1,3,7]不是子数组
2.如果存在多个最大和的连续子数组，那么返回其中长度最长的，该题数据保证这个最长的只存在一个
3.该题定义的子数组的最小长度为1，不存在为空的子数组，即不存在[]是某个数组的子数组
4.返回的数组不计入空间复杂度计算

要求:时间复杂度O(n)，空间复杂度O(n)
进阶:时间复杂度O(n)，空间复杂度O(1)

动态规划
数组
双指针
*/

class Solution {
public:
    vector<int> FindGreatestSumOfSubArray(vector<int>& array) {
        // 记录返回值
        vector<int> dp;
        // 记录每个位置最大值
        vector<int> count(array.size(), 0);
        int x = array[0];
        int y = 0;
        int left = 0, right = 0, c_left = 0, c_right = 0;
        int max_num = array[0];
        for (int i = 1; i < array.size(); i++) {
            right++;
            // 求出下标最大值
            y = max(x + array[i], array[i]);
            // 小就left更新
            if (x + array[i] < array[i]) {
                left = right;
            }
            // 大就c更新
            if (y > max_num || y == max_num && c_right - c_left < right - left) {
                c_left = left;
                c_right = right;
                max_num = y;
            }
            // 更新x，y
            x = y;
        }
        for (int i = c_left; i <= c_right; i++) {
            dp.push_back(array[i]);
        }
        return dp;

        /*
                // 记录返回值
            vector<int> dp;
            // 记录每个位置最大值
            vector<int> count(array.size(),0);
            count[0] = array[0];
            int left = 0, right = 0, c_left = 0, c_right = 0;
            int max_num = array[0];
            for (int i = 1; i < array.size(); i++){
                right++;
                // 求出下标最大值
                count[i] = max(count[i-1] + array[i], array[i]);
                // 小就left更新
                if (count[i-1] + array[i] < array[i]){
                    left = right;
                }
                // 大就c更新
                if (count[i] > max_num || count[i] == max_num && c_right-c_left < right-left){
                    c_left = left;
                    c_right = right;
                    max_num = count[i];
                }
            }
            for (int i = c_left; i <= c_right; i++){
                dp.push_back(array[i]);
            }
                return dp;
        */
    }
};
