#define _CRT_SECURE_NO_WARNINGS 1


/*
����һ������Ϊn����������array�������е�һ������������������һ�������飬�ҵ�һ���������͵����������顣
1.�������������ģ�����[1,3,5,7,9]����������[1,3]��[3,5,7]�ȵȣ�����[1,3,7]����������
2.������ڶ�����͵����������飬��ô�������г�����ģ��������ݱ�֤������ֻ����һ��
3.���ⶨ������������С����Ϊ1��������Ϊ�յ������飬��������[]��ĳ�������������
4.���ص����鲻����ռ临�Ӷȼ���

Ҫ��:ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)
����:ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)

��̬�滮
����
˫ָ��
*/

class Solution {
public:
    vector<int> FindGreatestSumOfSubArray(vector<int>& array) {
        // ��¼����ֵ
        vector<int> dp;
        // ��¼ÿ��λ�����ֵ
        vector<int> count(array.size(), 0);
        int x = array[0];
        int y = 0;
        int left = 0, right = 0, c_left = 0, c_right = 0;
        int max_num = array[0];
        for (int i = 1; i < array.size(); i++) {
            right++;
            // ����±����ֵ
            y = max(x + array[i], array[i]);
            // С��left����
            if (x + array[i] < array[i]) {
                left = right;
            }
            // ���c����
            if (y > max_num || y == max_num && c_right - c_left < right - left) {
                c_left = left;
                c_right = right;
                max_num = y;
            }
            // ����x��y
            x = y;
        }
        for (int i = c_left; i <= c_right; i++) {
            dp.push_back(array[i]);
        }
        return dp;

        /*
                // ��¼����ֵ
            vector<int> dp;
            // ��¼ÿ��λ�����ֵ
            vector<int> count(array.size(),0);
            count[0] = array[0];
            int left = 0, right = 0, c_left = 0, c_right = 0;
            int max_num = array[0];
            for (int i = 1; i < array.size(); i++){
                right++;
                // ����±����ֵ
                count[i] = max(count[i-1] + array[i], array[i]);
                // С��left����
                if (count[i-1] + array[i] < array[i]){
                    left = right;
                }
                // ���c����
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
