#define _CRT_SECURE_NO_WARNINGS 1

/*
假设你有一个数组prices，长度为n，其中prices[i]是股票在第i天的价格，请根据这个价格数组，返回买卖股票能获得的最大收益
1.你可以买入一次股票和卖出一次股票，并非每天都可以买入或卖出一次，总共只能买入和卖出一次，且买入必须在卖出的前面的某一天
2.如果不能获取到任何利润，请返回0
3.假设买入卖出均无手续费

数据范围：
要求：空间复杂度O(1) ，时间复杂度O(n)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0, sell = 0, max_get = 0;
        int max_num = prices[0], min_num = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < min_num)
            {
                min_num = prices[i];
            }
            else
            {
                max_num = prices[i];
                if (max_num - min_num > max_get)
                    max_get = max_num - min_num;
            }
        }
        return max_get;
    }
};
