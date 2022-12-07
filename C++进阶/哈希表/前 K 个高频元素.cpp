/*
����һ���������� nums ��һ������ k �����㷵�����г���Ƶ��ǰ k �ߵ�Ԫ�ء�����԰� ����˳�� ���ش𰸡�
*/

class Solution {
public:
    // С����
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Ҫͳ��Ԫ�س���Ƶ��
        unordered_map<int, int> map; // map<nums[i],��Ӧ���ֵĴ���>
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        // ��Ƶ������
        // ����һ��С���ѣ���СΪk
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;

        // �ù̶���СΪk��С���ѣ�ɨ������Ƶ�ʵ���ֵ
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) { // ����ѵĴ�С������K������е�������֤�ѵĴ�СһֱΪk
                pri_que.pop();
            }
        }

        // �ҳ�ǰK����ƵԪ�أ���ΪС�����ȵ���������С�ģ����Ե��������������
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;

    }
};