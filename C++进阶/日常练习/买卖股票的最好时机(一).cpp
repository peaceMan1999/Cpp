#define _CRT_SECURE_NO_WARNINGS 1

/*
��������һ������prices������Ϊn������prices[i]�ǹ�Ʊ�ڵ�i��ļ۸����������۸����飬����������Ʊ�ܻ�õ��������
1.���������һ�ι�Ʊ������һ�ι�Ʊ������ÿ�춼�������������һ�Σ��ܹ�ֻ�����������һ�Σ������������������ǰ���ĳһ��
2.������ܻ�ȡ���κ������뷵��0
3.����������������������

���ݷ�Χ��
Ҫ�󣺿ռ临�Ӷ�O(1) ��ʱ�临�Ӷ�O(n)
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
