/*
假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？
https://leetcode.cn/problems/gu-piao-de-zui-da-li-run-lcof/
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        int minf = prices[0];
        int maxf = 0;
        for (int i = 1; i < n; ++i)
        {
            if (prices[i] > minf) {
                maxf = max(maxf, prices[i] - minf);
            }
            else {
                minf = prices[i];
            }
        }
        return maxf;
    }
};
